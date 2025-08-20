#pragma once

#ifdef __cplusplus
extern "C"
{
#endif
// Аппаратно зависимые функции ATmega328p 16MHz 5VDC

void USART0_INIT(void); // Инициализация USART0 9600 8N1
void USART0_RX_ON(void); // Включаем приемник
void USART0_TX_ON(void); // Включаем передатчик
uint8_t USART0_READ_BYTE(void); // Читаем байт из USART0
void USART0_WRITE_BYTE(uint8_t In); // Пишем байт в USART0
void GPIO_INIT(void);
void TIMER1_INIT(void); // Настраиваем прерывание каждые 100ms
void TIMER2_INIT(void); // Настраиваем прерывание каждые 1ms
void Program_delay_500ms(void);
void PLC_Digital_output_cyclic(struct GlobalVar *p);
void PLC_Digital_input_cyclic(struct GlobalVar *p);

#define INTERRUPT_OFF(); asm volatile ("cli");
#define INTERRUPT_ON(); asm volatile ("sei");
#define NOP(); asm volatile ("nop");
#define DDRB_BIT_5_SET(); asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(DDRB)),"I" (5) );
#define PORTB_BIT_5_SET(); asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTB)),"I" (5) );
#define PORTB_BIT_5_RST(); asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTB)),"I" (5) );

// Arduino Nano Atmega328p 16MHz macros
#define PB5_ON();   asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTB)),"I" (5) );
#define D13_ON();   asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTB)),"I" (5) );
#define PB5_OFF();  asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTB)),"I" (5) );
#define D13_OFF();  asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTB)),"I" (5) );
#define LED_ON();   asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTB)),"I" (5) );
#define LED_OFF();  asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTB)),"I" (5) );
#define INIT_LED(); asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(DDRB )),"I" (5) );
#define INIT_PB5(); asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(DDRB )),"I" (5) );

#define PB4_ON();   asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTB)),"I" (4) );
#define D12_ON();   asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTB)),"I" (4) );
#define PB4_OFF();  asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTB)),"I" (4) );
#define D12_OFF();  asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTB)),"I" (4) );
#define INIT_PB4(); asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(DDRB )),"I" (4) );

#define PB3_ON();   asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTB)),"I" (3) );
#define D11_ON();   asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTB)),"I" (3) );
#define PB3_OFF();  asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTB)),"I" (3) );
#define D11_OFF();  asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTB)),"I" (3) );
#define INIT_PB3(); asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(DDRB )),"I" (3) );

#define PB2_ON();   asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTB)),"I" (2) );
#define D10_ON();   asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTB)),"I" (2) );
#define PB2_OFF();  asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTB)),"I" (2) );
#define D10_OFF();  asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTB)),"I" (2) );
#define INIT_PB2(); asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(DDRB )),"I" (2) );

#define PB1_ON();   asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTB)),"I" (1) );
#define D9_ON();    asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTB)),"I" (1) );
#define PB1_OFF();  asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTB)),"I" (1) );
#define D9_OFF();   asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTB)),"I" (1) );
#define INIT_PB1(); asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(DDRB )),"I" (1) );

#define PB0_ON();   asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTB)),"I" (0) );
#define D8_ON();    asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTB)),"I" (0) );
#define PB0_OFF();  asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTB)),"I" (0) );
#define D8_OFF();   asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTB)),"I" (0) );
#define INIT_PB0(); asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(DDRB )),"I" (0) );

#define PC5_ON();   asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTC)),"I" (5) );
#define A5_ON();    asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTC)),"I" (5) );
#define PC5_OFF();  asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTC)),"I" (5) );
#define A5_OFF();   asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTC)),"I" (5) );
#define INIT_PC5(); asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(DDRC )),"I" (5) );

#define PC4_ON();   asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTC)),"I" (4) );
#define A4_ON();    asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTC)),"I" (4) );
#define PC4_OFF();  asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTC)),"I" (4) );
#define A4_OFF();   asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTC)),"I" (4) );
#define INIT_PC4(); asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(DDRC )),"I" (4) );

#define PC3_ON();   asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTC)),"I" (3) );
#define A3_ON();    asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTC)),"I" (3) );
#define PC3_OFF();  asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTC)),"I" (3) );
#define A3_OFF();   asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTC)),"I" (3) );
#define INIT_PC3(); asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(DDRC )),"I" (3) );

#define PC2_ON();   asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTC)),"I" (2) );
#define A2_ON();    asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTC)),"I" (2) );
#define PC2_OFF();  asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTC)),"I" (2) );
#define A2_OFF();   asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTC)),"I" (2) );
#define INIT_PC2(); asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(DDRC )),"I" (2) );

#define PC1_ON();   asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTC)),"I" (1) );
#define A1_ON();    asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTC)),"I" (1) );
#define PC1_OFF();  asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTC)),"I" (1) );
#define A1_OFF();   asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTC)),"I" (1) );
#define INIT_PC1(); asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(DDRC )),"I" (1) );

#define PC0_ON();   asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTC)),"I" (0) );
#define A0_ON();    asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTC)),"I" (0) );
#define PC0_OFF();  asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTC)),"I" (0) );
#define A0_OFF();   asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTC)),"I" (0) );
#define INIT_PC0(); asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(DDRC )),"I" (0) );

#define PD7_ON();   asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTD)),"I" (7) );
#define D7_ON();    asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTD)),"I" (7) );
#define PD7_OFF();  asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTD)),"I" (7) );
#define D7_OFF();   asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTD)),"I" (7) );
#define INIT_PD7(); asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(DDRD )),"I" (7) );

#define PD6_ON();   asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTD)),"I" (6) );
#define D6_ON();    asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTD)),"I" (6) );
#define PD6_OFF();  asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTD)),"I" (6) );
#define D6_OFF();   asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTD)),"I" (6) );
#define INIT_PD6(); asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(DDRD )),"I" (6) );

#define PD5_ON();   asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTD)),"I" (5) );
#define D5_ON();    asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTD)),"I" (5) );
#define PD5_OFF();  asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTD)),"I" (5) );
#define D5_OFF();   asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTD)),"I" (5) );
#define INIT_PD5(); asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(DDRD )),"I" (5) );

#define PD4_ON();   asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTD)),"I" (4) );
#define D4_ON();    asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTD)),"I" (4) );
#define PD4_OFF();  asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTD)),"I" (4) );
#define D4_OFF();   asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTD)),"I" (4) );
#define INIT_PD4(); asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(DDRD )),"I" (4) );

#define PD3_ON();   asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTD)),"I" (3) );
#define D3_ON();    asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTD)),"I" (3) );
#define PD3_OFF();  asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTD)),"I" (3) );
#define D3_OFF();   asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTD)),"I" (3) );
#define INIT_PD3(); asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(DDRD )),"I" (3) );

#define PD2_ON();   asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTD)),"I" (2) );
#define D2_ON();    asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTD)),"I" (2) );
#define PD2_OFF();  asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTD)),"I" (2) );
#define D2_OFF();   asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTD)),"I" (2) );
#define INIT_PD2(); asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(DDRD )),"I" (2) );

#define PD1_ON();   asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTD)),"I" (1) );
#define D1_ON();    asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTD)),"I" (1) );
#define PD1_OFF();  asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTD)),"I" (1) );
#define D1_OFF();   asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTD)),"I" (1) );
#define INIT_PD1(); asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(DDRD )),"I" (1) );

#define PD0_ON();   asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTD)),"I" (0) );
#define D0_ON();    asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTD)),"I" (0) );
#define PD0_OFF();  asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTD)),"I" (0) );
#define D0_OFF();   asm volatile ("cbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(PORTD)),"I" (0) );
#define INIT_PD0(); asm volatile ("sbi %0,%1" :/* no outputs */: "I" (_SFR_IO_ADDR(DDRD )),"I" (0) );

#ifdef __cplusplus
}
#endif

// @COPYLEFT ALL WRONGS RESERVED :)
// Author: VA
// Contacts: DIY.PLC.314@gmail.com
// Date start LIB_PLC: 2014
// License: GNU GPL-2.0-or-later
// https://www.gnu.org/licenses/old-licenses/gpl-2.0.html
// https://www.youtube.com/watch?v=n1F_MfLRlX0
// https://www.youtube.com/@DIY_PLC
// https://github.com/DIYPLC/LIB_PLC
// https://oshwlab.com/diy.plc.314/PLC_HW1_SW1
// https://3dtoday.ru/3d-models/mechanical-parts/body/korpus-na-din-reiku
// https://t.me/DIY_PLC
