// Example use LIB_PLC generator and scope.
// Arduino style.
// Arduino Nano ATmega328p 16MHz 5VDC
#include <stdint.h>
#include <iso646.h>
#include "FbTs.hpp"
#include "FbGSS.hpp"
#include "FbBlink.hpp"
#include "FbFilterA.hpp"

static FbTs DbTs;
static FbBlink DbBlink;
static FbFilterA DbFilterA;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  DbTs.Reset = true;
  DbTs.millis = millis();
  DbTs();
  FcTaskCyclic(DbTs.Reset, DbTs.Ts_ms);
  return;
}

void loop() {
  DbTs.Reset = false;
  DbTs.millis = millis();
  DbTs();
  FcTaskCyclic(DbTs.Reset, DbTs.Ts_ms);
  return;
}

void FcTaskCyclic(bool Reset, uint32_t Ts_ms) {  // Задача выполняется с плавающим временем цикла.

  // Шаг дискретизации по времени [с].
  float Ts = ((float)Ts_ms) * 0.001;

  // Мигалка.
  //            DbBlink
  //    +---------------------+
  //    |       FbBlink       |
  //   -|Time_on_ms        Out|->-
  //   -|Time_off_ms          |
  //   -|Ts_ms                |
  //   -|Reset                |
  //    +---------------------+
  DbBlink.Time_on_ms = 800;   // Время импульса [мс].
  DbBlink.Time_off_ms = 800;  // Время паузы [мс].
  DbBlink.Ts_ms = Ts_ms;      // Шаг дискретизации по времени [мс].
  DbBlink.Reset = Reset;      // Сброс при перезагрузке.
  DbBlink();                  // Мигалка.
  //            = DbBlink.Out; // Мигающая лампочка.

  // Фильтр апериодический.
  //      DbFilterA
  //    +-----------+
  //    | FbFilterA |
  // ->-|In      Out|->-
  //   -|Tf         |
  //   -|Ts         |
  //    +-----------+
  DbFilterA.In = (float)DbBlink.Out;  // Входной сигнал до фильтрации.
  DbFilterA.Tf = 0.2;                 // Постоянная времени фильтра [с].
  DbFilterA.Ts = Ts;                  // Шаг дискретизации по времени [с].
  DbFilterA();                        // Фильтр апериодический.
  //           = DbFilterA.Out; // Выходной сигнал после фильтрации.

  Serial.print(DbFilterA.In);
  Serial.print(',');
  Serial.print(DbFilterA.Out);
  Serial.print(',');
  Serial.print(Ts);
  Serial.println();

  if (DbBlink.Out) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
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
