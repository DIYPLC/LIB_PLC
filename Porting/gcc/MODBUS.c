#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>
#include <avr/pgmspace.h>
#include <stdbool.h>
#include <stdint.h>
#include "MODBUS.h"

#define ENTER_CRITICAL_SECTION() cli()
#define EXIT_CRITICAL_SECTION() sei()
#define assert(x)

#define MB_PORT_HAS_CLOSE 0

#define MB_TIMER_PRESCALER (1024UL)
#define MB_TIMER_TICKS (F_CPU / MB_TIMER_PRESCALER)
#define MB_50US_TICKS (20000UL)

#define UART_BAUD_RATE 9600
#define UART_BAUD_CALC(UART_BAUD_RATE, F_OSC) \
  ((F_OSC) / ((UART_BAUD_RATE)*16UL) - 1)

#define MB_SER_PDU_SIZE_MIN 4   /*!< Minimum size of a Modbus RTU frame. */
#define MB_SER_PDU_SIZE_MAX 256 /*!< Maximum size of a Modbus RTU frame. */
#define MB_SER_PDU_SIZE_CRC 2   /*!< Size of CRC field in PDU. */
#define MB_SER_PDU_ADDR_OFF 0   /*!< Offset of slave address in Ser-PDU. */
#define MB_SER_PDU_PDU_OFF 1    /*!< Offset of Modbus-PDU in Ser-PDU. */

#define MB_PDU_SIZE_MAX 253 /*!< Maximum size of a PDU. */
#define MB_PDU_SIZE_MIN 1   /*!< Function Code */
#define MB_PDU_FUNC_OFF 0   /*!< Offset of function code in PDU. */
#define MB_PDU_DATA_OFF 1   /*!< Offset for response data in PDU. */

#define MB_RTU_ENABLED (1)
#define MB_FUNC_HANDLERS_MAX (16)
#define MB_FUNC_READ_HOLDING_ENABLED (1)
#define MB_FUNC_WRITE_HOLDING_ENABLED (1)
#define MB_FUNC_WRITE_MULTIPLE_HOLDING_ENABLED (1)
#define MB_FUNC_READWRITE_HOLDING_ENABLED (1)

#define MB_ADDRESS_BROADCAST (0) /*! Modbus broadcast address. */
#define MB_ADDRESS_MIN (1)       /*! Smallest possible slave address. */
#define MB_ADDRESS_MAX (247)     /*! Biggest possible slave address. */
#define MB_FUNC_NONE (0)
#define MB_FUNC_READ_COILS (1)
#define MB_FUNC_READ_DISCRETE_INPUTS (2)
#define MB_FUNC_WRITE_SINGLE_COIL (5)
#define MB_FUNC_WRITE_MULTIPLE_COILS (15)
#define MB_FUNC_READ_HOLDING_REGISTER (3)
#define MB_FUNC_READ_INPUT_REGISTER (4)
#define MB_FUNC_WRITE_REGISTER (6)
#define MB_FUNC_WRITE_MULTIPLE_REGISTERS (16)
#define MB_FUNC_READWRITE_MULTIPLE_REGISTERS (23)
#define MB_FUNC_DIAG_READ_EXCEPTION (7)
#define MB_FUNC_DIAG_DIAGNOSTIC (8)
#define MB_FUNC_DIAG_GET_COM_EVENT_CNT (11)
#define MB_FUNC_DIAG_GET_COM_EVENT_LOG (12)
#define MB_FUNC_OTHER_REPORT_SLAVEID (17)
#define MB_FUNC_ERROR (128)

#define MB_PDU_FUNC_READ_ADDR_OFF (MB_PDU_DATA_OFF + 0)
#define MB_PDU_FUNC_READ_REGCNT_OFF (MB_PDU_DATA_OFF + 2)
#define MB_PDU_FUNC_READ_SIZE (4)
#define MB_PDU_FUNC_READ_REGCNT_MAX (0x007D)
#define MB_PDU_FUNC_WRITE_ADDR_OFF (MB_PDU_DATA_OFF + 0)
#define MB_PDU_FUNC_WRITE_VALUE_OFF (MB_PDU_DATA_OFF + 2)
#define MB_PDU_FUNC_WRITE_SIZE (4)
#define MB_PDU_FUNC_WRITE_MUL_ADDR_OFF (MB_PDU_DATA_OFF + 0)
#define MB_PDU_FUNC_WRITE_MUL_REGCNT_OFF (MB_PDU_DATA_OFF + 2)
#define MB_PDU_FUNC_WRITE_MUL_BYTECNT_OFF (MB_PDU_DATA_OFF + 4)
#define MB_PDU_FUNC_WRITE_MUL_VALUES_OFF (MB_PDU_DATA_OFF + 5)
#define MB_PDU_FUNC_WRITE_MUL_SIZE_MIN (5)
#define MB_PDU_FUNC_WRITE_MUL_REGCNT_MAX (0x0078)
#define MB_PDU_FUNC_READWRITE_READ_ADDR_OFF (MB_PDU_DATA_OFF + 0)
#define MB_PDU_FUNC_READWRITE_READ_REGCNT_OFF (MB_PDU_DATA_OFF + 2)
#define MB_PDU_FUNC_READWRITE_WRITE_ADDR_OFF (MB_PDU_DATA_OFF + 4)
#define MB_PDU_FUNC_READWRITE_WRITE_REGCNT_OFF (MB_PDU_DATA_OFF + 6)
#define MB_PDU_FUNC_READWRITE_BYTECNT_OFF (MB_PDU_DATA_OFF + 8)
#define MB_PDU_FUNC_READWRITE_WRITE_VALUES_OFF (MB_PDU_DATA_OFF + 9)
#define MB_PDU_FUNC_READWRITE_SIZE_MIN (9)

#if defined(__AVR_ATmega328P__)
#define UCSRB UCSR0B
#define TXEN TXEN0
#define RXEN RXEN0
#define RXCIE RXCIE0
#define TXCIE TXCIE0
#define UDRE UDRIE0
#define UBRR UBRR0
#define UCSRC UCSR0C
#define UPM1 UPM01
#define UPM0 UPM00
#define UCSZ0 UCSZ00
#define UCSZ1 UCSZ01
#define UDR UDR0
#define SIG_USART_DATA USART_UDRE_vect
#define SIG_USART_RECV USART_RX_vect
#define SIG_UART_TRANS USART_TX_vect
#define SIG_OUTPUT_COMPARE1A TIMER1_COMPA_vect
#endif

#define RTS_PIN PB0
#define RTS_DDR DDRB
#define RTS_PORT PORTB

#define RTS_INIT \
  do { \
    RTS_DDR |= _BV(RTS_PIN); \
    RTS_PORT &= ~(_BV(RTS_PIN)); \
  } while (0);

#define RTS_HIGH \
  do { \
    RTS_PORT |= _BV(RTS_PIN); \
  } while (0);

#define RTS_LOW \
  do { \
    RTS_PORT &= ~(_BV(RTS_PIN)); \
  } while (0);

typedef enum {
  MB_EX_NONE = 0x00,
  MB_EX_ILLEGAL_FUNCTION = 0x01,
  MB_EX_ILLEGAL_DATA_ADDRESS = 0x02,
  MB_EX_ILLEGAL_DATA_VALUE = 0x03,
  MB_EX_SLAVE_DEVICE_FAILURE = 0x04,
  MB_EX_ACKNOWLEDGE = 0x05,
  MB_EX_SLAVE_BUSY = 0x06,
  MB_EX_MEMORY_PARITY_ERROR = 0x08,
  MB_EX_GATEWAY_PATH_FAILED = 0x0A,
  MB_EX_GATEWAY_TGT_FAILED = 0x0B
} eMBException;
typedef eMBException (*pxMBFunctionHandler)(uint8_t *pucFrame, uint16_t *pusLength);

typedef enum {
  EV_READY,          /*!< Startup finished. */
  EV_FRAME_RECEIVED, /*!< Frame received. */
  EV_EXECUTE,        /*!< Execute function. */
  EV_FRAME_SENT      /*!< Frame sent. */
} eMBEventType;

typedef enum {
  STATE_RX_INIT, /*!< Receiver is in initial state. */
  STATE_RX_IDLE, /*!< Receiver is in idle state. */
  STATE_RX_RCV,  /*!< Frame is beeing received. */
  STATE_RX_ERROR /*!< If the frame is invalid. */
} eMBRcvState;

typedef enum {
  STATE_TX_IDLE, /*!< Transmitter is in idle state. */
  STATE_TX_XMIT  /*!< Transmitter is in transfer state. */
} eMBSndState;

typedef struct
{
  uint8_t ucFunctionCode;
  pxMBFunctionHandler pxHandler;
} xMBFunctionHandler;

typedef enum {
  MB_REG_READ,  /*!< Read register values and pass to protocol stack. */
  MB_REG_WRITE  /*!< Update register values. */
} eMBRegisterMode;

static uint16_t usRegHoldingStart = REG_HOLDING_START;
volatile uint16_t usRegHoldingBuf[REG_HOLDING_NREGS];

typedef void (*pvMBFrameStart)(void);
typedef void (*pvMBFrameStop)(void);
typedef eMBErrorCode (*peMBFrameReceive)(uint8_t *pucRcvAddress, uint8_t **pucFrame, uint16_t *pusLength);
typedef eMBErrorCode (*peMBFrameSend)(uint8_t slaveAddress, const uint8_t *pucFrame, uint16_t usLength);
typedef void (*pvMBFrameClose)(void);

static uint8_t ucMBAddress;

static uint16_t usTimerOCRADelta;
static uint16_t usTimerOCRBDelta;

static eMBEventType eQueuedEvent;
static bool xEventInQueue;

static volatile eMBSndState eSndState;
static volatile eMBRcvState eRcvState;
volatile uint8_t ucRTUBuf[MB_SER_PDU_SIZE_MAX];
static volatile uint8_t *pucSndBufferCur;
static volatile uint16_t usSndBufferCount;
static volatile uint16_t usRcvBufferPos;

static peMBFrameSend peMBFrameSendCur;
static pvMBFrameStart pvMBFrameStartCur;
static pvMBFrameStop pvMBFrameStopCur;
static peMBFrameReceive peMBFrameReceiveCur;
static pvMBFrameClose pvMBFrameCloseCur;

static const PROGMEM uint8_t aucCRCHi[] = {
  0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
  0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
  0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01,
  0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41,
  0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81,
  0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
  0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01,
  0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
  0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
  0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
  0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01,
  0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
  0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
  0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
  0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01,
  0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
  0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
  0x40
};

static const PROGMEM uint8_t aucCRCLo[] = {
  0x00, 0xC0, 0xC1, 0x01, 0xC3, 0x03, 0x02, 0xC2, 0xC6, 0x06, 0x07, 0xC7, 0x05, 0xC5, 0xC4,
  0x04, 0xCC, 0x0C, 0x0D, 0xCD, 0x0F, 0xCF, 0xCE, 0x0E, 0x0A, 0xCA, 0xCB, 0x0B, 0xC9, 0x09,
  0x08, 0xC8, 0xD8, 0x18, 0x19, 0xD9, 0x1B, 0xDB, 0xDA, 0x1A, 0x1E, 0xDE, 0xDF, 0x1F, 0xDD,
  0x1D, 0x1C, 0xDC, 0x14, 0xD4, 0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6, 0xD2, 0x12, 0x13, 0xD3,
  0x11, 0xD1, 0xD0, 0x10, 0xF0, 0x30, 0x31, 0xF1, 0x33, 0xF3, 0xF2, 0x32, 0x36, 0xF6, 0xF7,
  0x37, 0xF5, 0x35, 0x34, 0xF4, 0x3C, 0xFC, 0xFD, 0x3D, 0xFF, 0x3F, 0x3E, 0xFE, 0xFA, 0x3A,
  0x3B, 0xFB, 0x39, 0xF9, 0xF8, 0x38, 0x28, 0xE8, 0xE9, 0x29, 0xEB, 0x2B, 0x2A, 0xEA, 0xEE,
  0x2E, 0x2F, 0xEF, 0x2D, 0xED, 0xEC, 0x2C, 0xE4, 0x24, 0x25, 0xE5, 0x27, 0xE7, 0xE6, 0x26,
  0x22, 0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0, 0xA0, 0x60, 0x61, 0xA1, 0x63, 0xA3, 0xA2,
  0x62, 0x66, 0xA6, 0xA7, 0x67, 0xA5, 0x65, 0x64, 0xA4, 0x6C, 0xAC, 0xAD, 0x6D, 0xAF, 0x6F,
  0x6E, 0xAE, 0xAA, 0x6A, 0x6B, 0xAB, 0x69, 0xA9, 0xA8, 0x68, 0x78, 0xB8, 0xB9, 0x79, 0xBB,
  0x7B, 0x7A, 0xBA, 0xBE, 0x7E, 0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C, 0xB4, 0x74, 0x75, 0xB5,
  0x77, 0xB7, 0xB6, 0x76, 0x72, 0xB2, 0xB3, 0x73, 0xB1, 0x71, 0x70, 0xB0, 0x50, 0x90, 0x91,
  0x51, 0x93, 0x53, 0x52, 0x92, 0x96, 0x56, 0x57, 0x97, 0x55, 0x95, 0x94, 0x54, 0x9C, 0x5C,
  0x5D, 0x9D, 0x5F, 0x9F, 0x9E, 0x5E, 0x5A, 0x9A, 0x9B, 0x5B, 0x99, 0x59, 0x58, 0x98, 0x88,
  0x48, 0x49, 0x89, 0x4B, 0x8B, 0x8A, 0x4A, 0x4E, 0x8E, 0x8F, 0x4F, 0x8D, 0x4D, 0x4C, 0x8C,
  0x44, 0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86, 0x82, 0x42, 0x43, 0x83, 0x41, 0x81, 0x80,
  0x40
};

static enum {
  STATE_ENABLED,
  STATE_DISABLED,
  STATE_NOT_INITIALIZED
} eMBState = STATE_NOT_INITIALIZED;

eMBErrorCode eMBRegHoldingCB(uint8_t* pucRegBuffer, uint16_t usAddress, uint16_t usNRegs, eMBRegisterMode eMode);

bool xMBPortEventInit(void);
bool xMBPortEventPost(eMBEventType eEvent);
bool xMBPortEventGet(/*@out@ */ eMBEventType *eEvent);
bool xMBPortSerialInit(uint8_t ucPort, uint32_t ulBaudRate, uint8_t ucDataBits, eMBParity eParity);
void vMBPortClose(void);
void xMBPortSerialClose(void);
void vMBPortSerialEnable(bool xRxEnable, bool xTxEnable);
bool xMBPortSerialGetByte(int8_t *pucByte);
bool xMBPortSerialPutByte(int8_t ucByte);
bool xMBPortTimersInit(uint16_t usTimeOut50us);
void xMBPortTimersClose(void);
void vMBPortTimersEnable(void);
void vMBPortTimersDisable(void);
void vMBPortTimersDelay(uint16_t usTimeOutMS);
extern bool (*pxMBFrameCBByteReceived)(void);
extern bool (*pxMBFrameCBTransmitterEmpty)(void);
extern bool (*pxMBPortCBTimerExpired)(void);

eMBException eMBFuncReadHoldingRegister(uint8_t *pucFrame, uint16_t *usLen);
eMBException eMBFuncWriteHoldingRegister(uint8_t *pucFrame, uint16_t *usLen);
eMBException eMBFuncWriteMultipleHoldingRegister(uint8_t *pucFrame, uint16_t *usLen);
eMBException eMBFuncReadWriteMultipleHoldingRegister(uint8_t *pucFrame, uint16_t *usLen);

eMBErrorCode eMBRTUInit(uint8_t slaveAddress, uint8_t ucPort, uint32_t ulBaudRate, eMBParity eParity);
void eMBRTUStart(void);
void eMBRTUStop(void);
eMBErrorCode eMBRTUReceive(uint8_t *pucRcvAddress, uint8_t **pucFrame, uint16_t *pusLength);
eMBErrorCode eMBRTUSend(uint8_t slaveAddress, const uint8_t *pucFrame, uint16_t usLength);
bool xMBRTUReceiveFSM(void);
bool xMBRTUTransmitFSM(void);
bool xMBRTUTimerT15Expired(void);
bool xMBRTUTimerT35Expired(void);

bool (*pxMBFrameCBByteReceived)(void);
bool (*pxMBFrameCBTransmitterEmpty)(void);
bool (*pxMBPortCBTimerExpired)(void);
bool (*pxMBFrameCBReceiveFSMCur)(void);
bool (*pxMBFrameCBTransmitFSMCur)(void);

static xMBFunctionHandler xFuncHandlers[MB_FUNC_HANDLERS_MAX] = {
  { MB_FUNC_READ_HOLDING_REGISTER, eMBFuncReadHoldingRegister },
  { MB_FUNC_WRITE_MULTIPLE_REGISTERS, eMBFuncWriteMultipleHoldingRegister },
  { MB_FUNC_WRITE_REGISTER, eMBFuncWriteHoldingRegister },
  { MB_FUNC_READWRITE_MULTIPLE_REGISTERS, eMBFuncReadWriteMultipleHoldingRegister }
};

eMBErrorCode eMBRegHoldingCB(uint8_t* pucRegBuffer, uint16_t usAddress, uint16_t usNRegs, eMBRegisterMode eMode) {
  eMBErrorCode eStatus = MB_ENOERR;
  int iRegIndex;
  if ((usAddress >= REG_HOLDING_START) && (usAddress + usNRegs <= REG_HOLDING_START + REG_HOLDING_NREGS)) {
    iRegIndex = (int)(usAddress - usRegHoldingStart);
    switch (eMode) {
      case MB_REG_READ:
        while (usNRegs > 0) {
          *pucRegBuffer++ = (uint8_t)(usRegHoldingBuf[iRegIndex] >> 8);
          *pucRegBuffer++ = (uint8_t)(usRegHoldingBuf[iRegIndex] & 0xFF);
          iRegIndex++;
          usNRegs--;
        }
        break;
      case MB_REG_WRITE:
        while (usNRegs > 0) {
          usRegHoldingBuf[iRegIndex] = *pucRegBuffer++ << 8;
          usRegHoldingBuf[iRegIndex] |= *pucRegBuffer++;
          iRegIndex++;
          usNRegs--;
        }
        break;
    }
  } else {
    eStatus = MB_ENOREG;
  }
  return eStatus;
}

eMBErrorCode eMBInit(uint8_t ucSlaveAddress, uint8_t ucPort, uint32_t ulBaudRate, eMBParity eParity) {
  eMBErrorCode eStatus = MB_ENOERR;
  if ((ucSlaveAddress == MB_ADDRESS_BROADCAST) || (ucSlaveAddress < MB_ADDRESS_MIN) || (ucSlaveAddress > MB_ADDRESS_MAX)) {
    eStatus = MB_EINVAL;
  } else {
    ucMBAddress = ucSlaveAddress;
    //    switch (eMode)
    //      case MB_RTU:
    pvMBFrameStartCur = eMBRTUStart;
    //pvMBFrameStopCur = eMBRTUStop;
    peMBFrameSendCur = eMBRTUSend;
    peMBFrameReceiveCur = eMBRTUReceive;
    pvMBFrameCloseCur = MB_PORT_HAS_CLOSE ? vMBPortClose : NULL;
    pxMBFrameCBByteReceived = xMBRTUReceiveFSM;
    pxMBFrameCBTransmitterEmpty = xMBRTUTransmitFSM;
    pxMBPortCBTimerExpired = xMBRTUTimerT35Expired;
    eStatus = eMBRTUInit(ucMBAddress, ucPort, ulBaudRate, eParity);
    if (eStatus == MB_ENOERR) {
      if (!xMBPortEventInit()) {
        eStatus = MB_EPORTERR;
      } else {
        eMBState = STATE_DISABLED;
      }
    }
  }
  return eStatus;
}

eMBErrorCode eMBEnable(void) {
  eMBErrorCode eStatus = MB_ENOERR;
  if (eMBState == STATE_DISABLED) {
    pvMBFrameStartCur();
    eMBState = STATE_ENABLED;
  } else {
    eStatus = MB_EILLSTATE;
  }
  return eStatus;
}

eMBErrorCode eMBPoll(void) {
  static uint8_t *ucMBFrame;
  static uint8_t ucRcvAddress;
  static uint8_t ucFunctionCode;
  static uint16_t usLength;
  static eMBException eException;
  int i;
  eMBErrorCode eStatus = MB_ENOERR;
  eMBEventType eEvent;
  if (eMBState != STATE_ENABLED) {
    return MB_EILLSTATE;
  }
  if (xMBPortEventGet(&eEvent) == true) {
    switch (eEvent) {
      case EV_READY:
        break;
      case EV_FRAME_RECEIVED:
        eStatus = peMBFrameReceiveCur(&ucRcvAddress, &ucMBFrame, &usLength);
        if (eStatus == MB_ENOERR) {
          if ((ucRcvAddress == ucMBAddress) || (ucRcvAddress == MB_ADDRESS_BROADCAST)) {
            (void)xMBPortEventPost(EV_EXECUTE);
          }
        }
        break;
      case EV_EXECUTE:
        ucFunctionCode = ucMBFrame[MB_PDU_FUNC_OFF];
        eException = MB_EX_ILLEGAL_FUNCTION;
        for (i = 0; i < MB_FUNC_HANDLERS_MAX; i++) {
          if (xFuncHandlers[i].ucFunctionCode == 0) {
            break;
          } else if (xFuncHandlers[i].ucFunctionCode == ucFunctionCode) {
            eException = xFuncHandlers[i].pxHandler(ucMBFrame, &usLength);
            break;
          }
        }
        if (ucRcvAddress != MB_ADDRESS_BROADCAST) {
          if (eException != MB_EX_NONE) {
            usLength = 0;
            ucMBFrame[usLength++] = (uint8_t)(ucFunctionCode | MB_FUNC_ERROR);
            ucMBFrame[usLength++] = eException;
          }
          eStatus = peMBFrameSendCur(ucMBAddress, ucMBFrame, usLength);
        }
        break;
      case EV_FRAME_SENT:
        break;
    }
  }
  return MB_ENOERR;
}

eMBException prveMBError2Exception(eMBErrorCode eErrorCode) {
  eMBException eStatus;
  switch (eErrorCode) {
    case MB_ENOERR:
      eStatus = MB_EX_NONE;
      break;
    case MB_ENOREG:
      eStatus = MB_EX_ILLEGAL_DATA_ADDRESS;
      break;
    case MB_ETIMEDOUT:
      eStatus = MB_EX_SLAVE_BUSY;
      break;
    default:
      eStatus = MB_EX_SLAVE_DEVICE_FAILURE;
      break;
  }
  return eStatus;
}

eMBException eMBFuncWriteHoldingRegister(uint8_t *pucFrame, uint16_t *usLen) {
  uint16_t usRegAddress;
  eMBException eStatus = MB_EX_NONE;
  eMBErrorCode eRegStatus;
  if (*usLen == (MB_PDU_FUNC_WRITE_SIZE + MB_PDU_SIZE_MIN)) {
    usRegAddress = (uint16_t)(pucFrame[MB_PDU_FUNC_WRITE_ADDR_OFF] << 8);
    usRegAddress |= (uint16_t)(pucFrame[MB_PDU_FUNC_WRITE_ADDR_OFF + 1]);
    usRegAddress++;
    eRegStatus = eMBRegHoldingCB(&pucFrame[MB_PDU_FUNC_WRITE_VALUE_OFF], usRegAddress, 1, MB_REG_WRITE);
    if (eRegStatus != MB_ENOERR) {
      eStatus = prveMBError2Exception(eRegStatus);
    }
  } else {
    eStatus = MB_EX_ILLEGAL_DATA_VALUE;
  }
  return eStatus;
}

eMBException eMBFuncWriteMultipleHoldingRegister(uint8_t *pucFrame, uint16_t *usLen) {
  uint16_t usRegAddress;
  uint16_t usRegCount;
  uint8_t ucRegByteCount;
  eMBException eStatus = MB_EX_NONE;
  eMBErrorCode eRegStatus;
  if (*usLen >= (MB_PDU_FUNC_WRITE_MUL_SIZE_MIN + MB_PDU_SIZE_MIN)) {
    usRegAddress = (uint16_t)(pucFrame[MB_PDU_FUNC_WRITE_MUL_ADDR_OFF] << 8);
    usRegAddress |= (uint16_t)(pucFrame[MB_PDU_FUNC_WRITE_MUL_ADDR_OFF + 1]);
    usRegAddress++;
    usRegCount = (uint16_t)(pucFrame[MB_PDU_FUNC_WRITE_MUL_REGCNT_OFF] << 8);
    usRegCount |= (uint16_t)(pucFrame[MB_PDU_FUNC_WRITE_MUL_REGCNT_OFF + 1]);
    ucRegByteCount = pucFrame[MB_PDU_FUNC_WRITE_MUL_BYTECNT_OFF];
    if ((usRegCount >= 1) && (usRegCount <= MB_PDU_FUNC_WRITE_MUL_REGCNT_MAX) && (ucRegByteCount == (uint8_t)(2 * usRegCount))) {
      eRegStatus =
        eMBRegHoldingCB(&pucFrame[MB_PDU_FUNC_WRITE_MUL_VALUES_OFF], usRegAddress, usRegCount, MB_REG_WRITE);
      if (eRegStatus != MB_ENOERR) {
        eStatus = prveMBError2Exception(eRegStatus);
      } else {
        *usLen = MB_PDU_FUNC_WRITE_MUL_BYTECNT_OFF;
      }
    } else {
      eStatus = MB_EX_ILLEGAL_DATA_VALUE;
    }
  } else {
    eStatus = MB_EX_ILLEGAL_DATA_VALUE;
  }
  return eStatus;
}

eMBException eMBFuncReadHoldingRegister(uint8_t *pucFrame, uint16_t *usLen) {
  uint16_t usRegAddress;
  uint16_t usRegCount;
  uint8_t *pucFrameCur;
  eMBException eStatus = MB_EX_NONE;
  eMBErrorCode eRegStatus;
  if (*usLen == (MB_PDU_FUNC_READ_SIZE + MB_PDU_SIZE_MIN)) {
    usRegAddress = (uint16_t)(pucFrame[MB_PDU_FUNC_READ_ADDR_OFF] << 8);
    usRegAddress |= (uint16_t)(pucFrame[MB_PDU_FUNC_READ_ADDR_OFF + 1]);
    usRegAddress++;
    usRegCount = (uint16_t)(pucFrame[MB_PDU_FUNC_READ_REGCNT_OFF] << 8);
    usRegCount = (uint16_t)(pucFrame[MB_PDU_FUNC_READ_REGCNT_OFF + 1]);
    if ((usRegCount >= 1) && (usRegCount <= MB_PDU_FUNC_READ_REGCNT_MAX)) {
      pucFrameCur = &pucFrame[MB_PDU_FUNC_OFF];
      *usLen = MB_PDU_FUNC_OFF;
      *pucFrameCur++ = MB_FUNC_READ_HOLDING_REGISTER;
      *usLen += 1;
      *pucFrameCur++ = (uint8_t)(usRegCount * 2);
      *usLen += 1;
      eRegStatus = eMBRegHoldingCB(pucFrameCur, usRegAddress, usRegCount, MB_REG_READ);
      if (eRegStatus != MB_ENOERR) {
        eStatus = prveMBError2Exception(eRegStatus);
      } else {
        *usLen += usRegCount * 2;
      }
    } else {
      eStatus = MB_EX_ILLEGAL_DATA_VALUE;
    }
  } else {
    eStatus = MB_EX_ILLEGAL_DATA_VALUE;
  }
  return eStatus;
}

eMBException eMBFuncReadWriteMultipleHoldingRegister(uint8_t *pucFrame, uint16_t *usLen) {
  uint16_t usRegReadAddress;
  uint16_t usRegReadCount;
  uint16_t usRegWriteAddress;
  uint16_t usRegWriteCount;
  uint8_t ucRegWriteByteCount;
  uint8_t *pucFrameCur;
  eMBException eStatus = MB_EX_NONE;
  eMBErrorCode eRegStatus;
  if (*usLen >= (MB_PDU_FUNC_READWRITE_SIZE_MIN + MB_PDU_SIZE_MIN)) {
    usRegReadAddress = (uint16_t)(pucFrame[MB_PDU_FUNC_READWRITE_READ_ADDR_OFF] << 8U);
    usRegReadAddress |= (uint16_t)(pucFrame[MB_PDU_FUNC_READWRITE_READ_ADDR_OFF + 1]);
    usRegReadAddress++;
    usRegReadCount = (uint16_t)(pucFrame[MB_PDU_FUNC_READWRITE_READ_REGCNT_OFF] << 8U);
    usRegReadCount |= (uint16_t)(pucFrame[MB_PDU_FUNC_READWRITE_READ_REGCNT_OFF + 1]);
    usRegWriteAddress = (uint16_t)(pucFrame[MB_PDU_FUNC_READWRITE_WRITE_ADDR_OFF] << 8U);
    usRegWriteAddress |= (uint16_t)(pucFrame[MB_PDU_FUNC_READWRITE_WRITE_ADDR_OFF + 1]);
    usRegWriteAddress++;
    usRegWriteCount = (uint16_t)(pucFrame[MB_PDU_FUNC_READWRITE_WRITE_REGCNT_OFF] << 8U);
    usRegWriteCount |= (uint16_t)(pucFrame[MB_PDU_FUNC_READWRITE_WRITE_REGCNT_OFF + 1]);
    ucRegWriteByteCount = pucFrame[MB_PDU_FUNC_READWRITE_BYTECNT_OFF];
    if ((usRegReadCount >= 1) && (usRegReadCount <= 0x7D) && (usRegWriteCount >= 1) && (usRegWriteCount <= 0x79) && ((2 * usRegWriteCount) == ucRegWriteByteCount)) {
      eRegStatus = eMBRegHoldingCB(&pucFrame[MB_PDU_FUNC_READWRITE_WRITE_VALUES_OFF], usRegWriteAddress, usRegWriteCount, MB_REG_WRITE);
      if (eRegStatus == MB_ENOERR) {
        pucFrameCur = &pucFrame[MB_PDU_FUNC_OFF];
        *usLen = MB_PDU_FUNC_OFF;
        *pucFrameCur++ = MB_FUNC_READWRITE_MULTIPLE_REGISTERS;
        *usLen += 1;
        *pucFrameCur++ = (uint8_t)(usRegReadCount * 2);
        *usLen += 1;
        eRegStatus = eMBRegHoldingCB(pucFrameCur, usRegReadAddress, usRegReadCount, MB_REG_READ);
        if (eRegStatus == MB_ENOERR) {
          *usLen += 2 * usRegReadCount;
        }
      }
      if (eRegStatus != MB_ENOERR) {
        eStatus = prveMBError2Exception(eRegStatus);
      }
    } else {
      eStatus = MB_EX_ILLEGAL_DATA_VALUE;
    }
  }
  return eStatus;
}

uint16_t usMBCRC16(uint8_t *pucFrame, uint16_t usLen) {
  // https://github.com/cwalter-at/freemodbus/blob/master/demo/AVR/port/mbcrc.c
  // Copyright (C) 2006 Christian Walter <wolti@sil.at> LGPL
  uint8_t ucCRCHi = 0xFF;
  uint8_t ucCRCLo = 0xFF;
  int iIndex;
  while (usLen--) {
    iIndex = ucCRCLo ^ *(pucFrame++);
    ucCRCLo = ucCRCHi ^ pgm_read_byte(&aucCRCHi[iIndex]);
    ucCRCHi = pgm_read_byte(&aucCRCLo[iIndex]);
    ;
  }
  return ucCRCHi << 8 | ucCRCLo;
}

eMBErrorCode eMBRTUInit(uint8_t ucSlaveAddress, uint8_t ucPort, uint32_t ulBaudRate, eMBParity eParity) {
  eMBErrorCode eStatus = MB_ENOERR;
  uint32_t usTimerT35_50us;
  (void)ucSlaveAddress;
  ENTER_CRITICAL_SECTION();
  if (xMBPortSerialInit(ucPort, ulBaudRate, 8, eParity) != true) {
    eStatus = MB_EPORTERR;
  } else {
    if (ulBaudRate > 19200) {
      usTimerT35_50us = 35; /* 1800us. */
    } else {
      usTimerT35_50us = (7UL * 220000UL) / (2UL * ulBaudRate);
    }
    if (xMBPortTimersInit((uint16_t)usTimerT35_50us) != true) {
      eStatus = MB_EPORTERR;
    }
  }
  EXIT_CRITICAL_SECTION();
  return eStatus;
}

void eMBRTUStart(void) {
  ENTER_CRITICAL_SECTION();
  eRcvState = STATE_RX_INIT;
  vMBPortSerialEnable(true, false);
  vMBPortTimersEnable();
  EXIT_CRITICAL_SECTION();
}

eMBErrorCode eMBRTUReceive(uint8_t *pucRcvAddress, uint8_t **pucFrame, uint16_t *pusLength) {
  bool xFrameReceived = false;
  eMBErrorCode eStatus = MB_ENOERR;
  ENTER_CRITICAL_SECTION();
  assert(usRcvBufferPos < MB_SER_PDU_SIZE_MAX);
  if ((usRcvBufferPos >= MB_SER_PDU_SIZE_MIN)
      && (usMBCRC16((uint8_t *)ucRTUBuf, usRcvBufferPos) == 0)) {
    *pucRcvAddress = ucRTUBuf[MB_SER_PDU_ADDR_OFF];
    *pusLength = (uint16_t)(usRcvBufferPos - MB_SER_PDU_PDU_OFF - MB_SER_PDU_SIZE_CRC);
    *pucFrame = (uint8_t *)&ucRTUBuf[MB_SER_PDU_PDU_OFF];
    xFrameReceived = true;
  } else {
    eStatus = MB_EIO;
  }
  EXIT_CRITICAL_SECTION();
  return eStatus;
}

eMBErrorCode eMBRTUSend(uint8_t ucSlaveAddress, const uint8_t *pucFrame, uint16_t usLength) {
  eMBErrorCode eStatus = MB_ENOERR;
  uint16_t usCRC16;
  ENTER_CRITICAL_SECTION();
  if (eRcvState == STATE_RX_IDLE) {
    pucSndBufferCur = (uint8_t *)pucFrame - 1;
    usSndBufferCount = 1;
    pucSndBufferCur[MB_SER_PDU_ADDR_OFF] = ucSlaveAddress;
    usSndBufferCount += usLength;
    usCRC16 = usMBCRC16((uint8_t *)pucSndBufferCur, usSndBufferCount);
    ucRTUBuf[usSndBufferCount++] = (uint8_t)(usCRC16 & 0xFF);
    ucRTUBuf[usSndBufferCount++] = (uint8_t)(usCRC16 >> 8);
    eSndState = STATE_TX_XMIT;
    vMBPortSerialEnable(false, true);
  } else {
    eStatus = MB_EIO;
  }
  EXIT_CRITICAL_SECTION();
  return eStatus;
}

bool xMBRTUReceiveFSM(void) {
  bool xTaskNeedSwitch = false;
  uint8_t ucByte;
  assert(eSndState == STATE_TX_IDLE);
  (void)xMBPortSerialGetByte((int8_t *)&ucByte);
  switch (eRcvState) {
    case STATE_RX_INIT:
      vMBPortTimersEnable();
      break;
    case STATE_RX_ERROR:
      vMBPortTimersEnable();
      break;
    case STATE_RX_IDLE:
      usRcvBufferPos = 0;
      ucRTUBuf[usRcvBufferPos++] = ucByte;
      eRcvState = STATE_RX_RCV;
      vMBPortTimersEnable();
      break;
    case STATE_RX_RCV:
      if (usRcvBufferPos < MB_SER_PDU_SIZE_MAX) {
        ucRTUBuf[usRcvBufferPos++] = ucByte;
      } else {
        eRcvState = STATE_RX_ERROR;
      }
      vMBPortTimersEnable();
      break;
  }
  return xTaskNeedSwitch;
}

bool xMBRTUTransmitFSM(void) {
  bool xNeedPoll = false;
  assert(eRcvState == STATE_RX_IDLE);
  switch (eSndState) {
    case STATE_TX_IDLE:
      vMBPortSerialEnable(true, false);
      break;
    case STATE_TX_XMIT:
      if (usSndBufferCount != 0) {
        xMBPortSerialPutByte((int8_t)*pucSndBufferCur);
        pucSndBufferCur++;
        usSndBufferCount--;
      } else {
        xNeedPoll = xMBPortEventPost(EV_FRAME_SENT);
        vMBPortSerialEnable(true, false);
        eSndState = STATE_TX_IDLE;
      }
      break;
  }
  return xNeedPoll;
}

bool xMBRTUTimerT35Expired(void) {
  bool xNeedPoll = false;
  switch (eRcvState) {
    case STATE_RX_INIT:
      xNeedPoll = xMBPortEventPost(EV_READY);
      break;
    case STATE_RX_RCV:
      xNeedPoll = xMBPortEventPost(EV_FRAME_RECEIVED);
      break;
    case STATE_RX_ERROR:
      break;
    default:
      assert((eRcvState == STATE_RX_INIT) || (eRcvState == STATE_RX_RCV) || (eRcvState == STATE_RX_ERROR));
  }
  vMBPortTimersDisable();
  eRcvState = STATE_RX_IDLE;
  return xNeedPoll;
}

bool xMBPortTimersInit(uint16_t usTim1Timerout50us) {
  usTimerOCRADelta =
    (MB_TIMER_TICKS * usTim1Timerout50us) / (MB_50US_TICKS);
  TCCR1A = 0x00;
  TCCR1B = 0x00;
  TCCR1C = 0x00;
  vMBPortTimersDisable();
  return true;
}

inline void vMBPortTimersEnable() {
  TCNT1 = 0x0000;
  if (usTimerOCRADelta > 0) {
    TIMSK1 |= _BV(OCIE1A);
    OCR1A = usTimerOCRADelta;
  }
  TCCR1B |= _BV(CS12) | _BV(CS10);
}

inline void vMBPortTimersDisable() {
  TCCR1B &= ~(_BV(CS12) | _BV(CS10));
  TIMSK1 &= ~(_BV(OCIE1A));
  TIFR1 |= _BV(OCF1A);
}

SIGNAL(SIG_OUTPUT_COMPARE1A) {
  (void)pxMBPortCBTimerExpired();
}

void vMBPortSerialEnable(bool xRxEnable, bool xTxEnable) {
#ifdef RTS_ENABLE
  UCSRB |= _BV(TXEN) | _BV(TXCIE);
#else
  UCSRB |= _BV(TXEN);
#endif
  if (xRxEnable) {
    UCSRB |= _BV(RXEN) | _BV(RXCIE);
  } else {
    UCSRB &= ~(_BV(RXEN) | _BV(RXCIE));
  }
  if (xTxEnable) {
    UCSRB |= _BV(TXEN) | _BV(UDRE);
#ifdef RTS_ENABLE
    RTS_HIGH;
#endif
  } else {
    UCSRB &= ~(_BV(UDRE));
  }
}

bool xMBPortSerialInit(uint8_t ucPORT, uint32_t ulBaudRate, uint8_t ucDataBits, eMBParity eParity) {
  uint8_t ucUCSRC = 0;
  (void)ucPORT;
  UBRR = UART_BAUD_CALC(ulBaudRate, F_CPU);
  switch (eParity) {
    case MB_PAR_EVEN:
      ucUCSRC |= _BV(UPM1);
      break;
    case MB_PAR_ODD:
      ucUCSRC |= _BV(UPM1) | _BV(UPM0);
      break;
    case MB_PAR_NONE:
      break;
  }
  switch (ucDataBits) {
    case 8:
      ucUCSRC |= _BV(UCSZ0) | _BV(UCSZ1);
      break;
    case 7:
      ucUCSRC |= _BV(UCSZ1);
      break;
  }
#if defined(__AVR_ATmega328P__)
  UCSRC |= ucUCSRC;
#endif
  vMBPortSerialEnable(false, false);
#ifdef RTS_ENABLE
  RTS_INIT;
#endif
  return true;
}

bool xMBPortSerialPutByte(int8_t ucByte) {
  UDR = ucByte;
  return true;
}

bool xMBPortSerialGetByte(int8_t *pucByte) {
  *pucByte = UDR;
  return true;
}

SIGNAL(SIG_USART_DATA) {
  pxMBFrameCBTransmitterEmpty();
}

SIGNAL(SIG_USART_RECV) {
  pxMBFrameCBByteReceived();
}

SIGNAL(SIG_UART_TRANS) {
  RTS_LOW;
}

bool xMBPortEventInit(void) {
  xEventInQueue = false;
  return true;
}

bool xMBPortEventPost(eMBEventType eEvent) {
  xEventInQueue = true;
  eQueuedEvent = eEvent;
  return true;
}

bool xMBPortEventGet(eMBEventType *eEvent) {
  bool xEventHappened = false;

  if (xEventInQueue) {
    *eEvent = eQueuedEvent;
    xEventInQueue = false;
    xEventHappened = true;
  }
  return xEventHappened;
}

// https://github.com/cwalter-at/freemodbus

/*
   FreeModbus Libary: A portable Modbus implementation for Modbus ASCII/RTU.
   Copyright (c) 2006-2018 Christian Walter <cwalter@embedded-solutions.at>
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:
   1. Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
   2. Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
   3. The name of the author may not be used to endorse or promote products
      derived from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
   IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
   OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
   IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
   INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
   NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
   THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
