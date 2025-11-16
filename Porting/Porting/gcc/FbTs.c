#include <stdint.h>
#include <stdbool.h>
#include <iso646.h>
#include "FbTs.h"

#define millis           p->millis
#define Reset            p->Reset
#define Ts_ms            p->Ts_ms
#define Ts               p->Ts
#define Ts_ms_max        p->Ts_ms_max
#define Uptime_s         p->Uptime_s
#define Time_previous_ms p->Time_previous_ms
#define Uptime_ms        p->Uptime_ms

void FbTs(struct DbTs *p)
{

  // Рассчет шага дискретизации по времени [мс].
  if (Time_previous_ms <= millis)
  {
    Ts_ms = millis - Time_previous_ms; // Разность времени без переполнения (займа).
  }
  else
  {
    // Данное вычисление зависит от платформы надо перепроверить!
    ;// Ts_ms = (0xFFFFFFFF - Time_previous_ms) + millis + 1; // разность времени при переполнении.
  }
  // 4294967295ms = 49.7 day!
  // STM32F103C8T6 STM32CubeIDE 1.6.1
  // sizeof(bool) = 1byte = 8bit
  // sizeof(uint8_t) = 1byte = 8bit
  // sizeof(uint16_t) = 2byte = 16bit
  // sizeof(uint32_t) = 4byte = 32bit
  // sizeof(uint64_t) = 8byte = 64bit
  // sizeof(float) = 4byte = 32bit
  // sizeof(double) = 8byte = 64bit

  // Инициализация при первом старте.
  if (Reset)
  {
    Time_previous_ms = millis;
    Ts_ms = 0;
    Ts = 0.0;
    Ts_ms_max = 0;
    Uptime_s = 0;
  }

  // Запомнить предидущее состояние.
  Time_previous_ms = millis;

  // Шаг дискретизации по времени [с].
  Ts = ((float)Ts_ms) * 0.001;

  // Максимальное время скана [мс].
  if (Ts_ms > Ts_ms_max)
  {
    Ts_ms_max = Ts_ms;
  }

  // Время в работе [мс].
  Uptime_ms = Uptime_ms + ((uint64_t)Ts_ms);
  // Время в работе [с].
  Uptime_s = (uint32_t)(Uptime_ms / 1000);

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
