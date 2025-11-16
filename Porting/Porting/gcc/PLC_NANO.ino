// Программирование в стиле ПЛК версия от 01.04.2025.
// Библиотека LIB_PLC.
// В файле MODBUS.c Сеть MODBUS RTU SALVE ADR1 RS485 для SCADA/HMI.
// Ресурсы ПЛК в GlobalVar.h
// Arduino Nano ATmega328p 16MHz 5VDC
// Arduino IDE 1.8.19
// Windows 10 pro 64bit
// Программатор по умолчанию AVRISP mkll old boot loader

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdbool.h>
#include <iso646.h>
#include "GlobalVar.h" // Глобальные переменные ПЛК.
#include "M328P_HW.h" // Аппаратно зависимые функции ATmega328p 16MHz 5VDC
#include "FcTaskCyclic.h" // Задача выполняется с плавающим временем цикла.
#include "MODBUS.h" // MODBUS RTU SALVE.
#include "FbTs.h"

#define SetBit(Var,Bit)   ( (Var) = (Var) |  (1 << (Bit)) )
#define ResetBit(Var,Bit) ( (Var) = (Var) & ~(1 << (Bit)) )

struct GlobalVar GV = {0}; // Глобальные переменные ПЛК.
static struct DbTs DbTs1 = {0};
extern uint16_t usRegHoldingBuf[];

int main(void)
{
  GPIO_INIT();
  TIMER2_INIT(); // Настраиваем прерывание каждые 1ms.

  eMBInit(1, 0, 9600, MB_PAR_NONE);  // MODBUS RTU SLAVE ADDRESS 1, USART0 9600 8N1.
  sei(); // Включить все прерывания.
  eMBEnable();

  GV.Reset = true;
  // Расчет времени скана.
  //             DbTs
  //    +---------------------+
  //    |        FbTs         |
  //   -|millis          Ts_ms|->-
  //   -|Reset              Ts|->-
  //    |            Ts_ms_max|->-
  //    |             Uptime_s|->-
  //    +---------------------+
  DbTs1.millis = GV.millis_ms   ; // millis() Arduino.
  DbTs1.Reset  = GV.Reset       ; // Сброс при перезагрузке.
  FbTs(&DbTs1)                  ; // Расчет времени скана.
  GV.Ts_ms     = DbTs1.Ts_ms    ; // Шаг дискретизации по времени [мс].
  GV.Ts        = DbTs1.Ts       ; // Шаг дискретизации по времени [с].
  GV.Ts_ms_max = DbTs1.Ts_ms_max; // Максимальное время скана [мс].
  GV.Uptime_s  = DbTs1.Uptime_s ; // Время в работе [мс].

  FcTaskCyclic(GV.Reset, GV.Ts_ms); // Задача выполняется с плавающим временем цикла.

  while (1)
  {
    PLC_Digital_input_cyclic(&GV) ;
    (void)eMBPoll();

    GV.Reset = false;
    // Расчет времени скана.
    //             DbTs
    //    +---------------------+
    //    |        FbTs         |
    //   -|millis          Ts_ms|->-
    //   -|Reset              Ts|->-
    //    |            Ts_ms_max|->-
    //    |             Uptime_s|->-
    //    +---------------------+
    DbTs1.millis = GV.millis_ms   ; // millis() Arduino.
    DbTs1.Reset  = GV.Reset       ; // Сброс при перезагрузке.
    FbTs(&DbTs1)                  ; // Расчет времени скана.
    GV.Ts_ms     = DbTs1.Ts_ms    ; // Шаг дискретизации по времени [мс].
    GV.Ts        = DbTs1.Ts       ; // Шаг дискретизации по времени [с].
    GV.Ts_ms_max = DbTs1.Ts_ms_max; // Максимальное время скана [мс].
    GV.Uptime_s  = DbTs1.Uptime_s ; // Время в работе [мс].

    FcTaskCyclic(GV.Reset, GV.Ts_ms); // Задача выполняется с плавающим временем цикла.
    PLC_Digital_output_cyclic(&GV);
  }
}

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
