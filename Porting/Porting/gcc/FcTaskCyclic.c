#include <stdint.h>  // uint8_t...uint64_t int8_t...int64_t
#include <stdbool.h> // bool true false
#include <iso646.h>  // and or not
#include "LIB_PLC.h"

#include "FcTaskCyclic.h" // Задача вызывается циклически.
#include "MODBUS.h"

#define MW usRegHoldingBuf // Регистры MODBUS

extern uint16_t usRegHoldingBuf[];
extern struct GlobalVar GV; // Глобальные переменные ПЛК.
static struct DbBlink DbBlink1 = {0};
static struct DbFilterA DbFilterA1 = {0};

void FcTaskCyclic(bool Reset, uint32_t Ts_ms) // Задача выполняется с плавающим временем цикла.
{

  // Карта регистров MODBUS HOLDING REGISTERS  Slave Address 1
  // Время работы мс.
  MW[0] = 0x7fff bitand GV.millis_ms; // HOLDING REGISTER 0 int16
  // Время скана мс.
  MW[1] = 0x7fff bitand GV.Ts_ms; // HOLDING REGISTER 1 int16
  // Максимальное время скана мс.
  MW[2] = 0x7fff bitand GV.Ts_ms_max; // HOLDING REGISTER 2 int16

  // Тест на сложение.
  if (Reset) {
    MW[5] = -2;
    MW[6] = -3;
  }
  MW[7] = MW[6] + MW[5];

  // Пример работы с дискретными алгоритмами.
  // Мигалка.
  //            DbBlink
  //    +---------------------+
  //    |       FbBlink       |
  //   -|Time_on_ms        Out|->-
  //   -|Time_off_ms          |
  //   -|Ts_ms                |
  //   -|Reset                |
  //    +---------------------+
  DbBlink1.Time_on_ms  = 500         ; // Время импульса [мс].
  DbBlink1.Time_off_ms = 500         ; // Время паузы [мс].
  DbBlink1.Ts_ms       = Ts_ms       ; // Шаг дискретизации по времени [мс].
  DbBlink1.Reset       = Reset       ; // Сброс при перезагрузке.
  FbBlink(&DbBlink1)                 ; // Мигалка.
  GV.Blink1000ms       = DbBlink1.Out; // Мигающая лампочка.

  GV.Do1 = GV.Blink1000ms;

  // Пример работы с аналоговыми алгоритмами.
  // Фильтр апериодический.
  //      DbFilterA
  //    +-----------+
  //    | FbFilterA |
  // ->-|In      Out|->-
  //   -|Tf         |
  //   -|Ts         |
  //    +-----------+
  DbFilterA1.In = (float) DbBlink1.Out; // Входной сигнал до фильтрации.
  DbFilterA1.Tf = 0.15                ; // Постоянная времени фильтра [с].
  DbFilterA1.Ts = GV.Ts               ; // Шаг дискретизации по времени [с].
  FbFilterA(&DbFilterA1)              ; // Фильтр апериодический.
  //            = DbFilterA1.Out      ; // Выходной сигнал после фильтрации.

  return;
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
