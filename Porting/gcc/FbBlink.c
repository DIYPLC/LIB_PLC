#include <stdint.h>
#include <stdbool.h>
#include <iso646.h>
#include "FbBlink.h"

#define Time_on_ms p->Time_on_ms
#define Time_off_ms p->Time_off_ms
#define Ts_ms p->Ts_ms
#define Reset p->Reset
#define Out p->Out
#define Timer1 p->Timer1
#define State1 p->State1

enum STATES  // Номера состояний.
{
  STATE_RESET = 0,  // Сброс.
  STATE_ON = 1,     // Включить лампочку на заданное время.
  STATE_OFF = 2     // Выключить лампочку на заданное время.
};

void FbBlink(struct DbBlink *p) {

#if (1)  // ON.
  // Версия 1. Универсальная версия с графом состояния.
  if (Reset) {  // Сброс при перезагрузке.
    State1 = STATE_RESET;
  }

  switch (State1)  // Граф состояний.
  {

    case STATE_RESET:  // Сброс.
      Out = false;
      Timer1 = 0;
      State1 = STATE_ON;
      break;

    case STATE_ON:  // Включить лампочку на заданное время.
      Out = true;
      Timer1 = Timer1 + Ts_ms;
      if (Timer1 >= Time_on_ms) {
        State1 = STATE_OFF;
        Timer1 = 0;
      }
      break;

    case STATE_OFF:  // Выключить лампочку на заданное время.
      Out = false;
      Timer1 = Timer1 + Ts_ms;
      if (Timer1 >= Time_off_ms) {
        State1 = STATE_ON;
        Timer1 = 0;
      }
      break;

    default:  // RESET при неопределенном состоянии.
      State1 = STATE_RESET;
      break;
  }
#endif

#if (0)  // OFF.
  // Версия 2. Простая для понимания версия.
  // Формируем период.
  if ((Timer1 >= (Time_on_ms + Time_off_ms)) or Reset) {
    Timer1 = 0;
  } else {
    Timer1 = Timer1 + Ts_ms;
  }
  // Формируем время импульса.
  if (Timer1 <= Time_on_ms) {
    Out = true;
  } else {
    Out = false;
  }
#endif

#if (0)  // OFF.
  // Версия 3. Простая для компилятора.
  // Формируем период.
  Timer1 = (Timer1 + Ts_ms) * ((Timer1 <= (Time_on_ms + Time_off_ms)) and not(Reset));
  // Формируем время импульса.
  Out = (Timer1 <= Time_on_ms);
#endif

  return;
}

// Граф состояний.
//
//            |
//           -+- Reset
//            |
//            V
//  +-------------------+
//  | State1 =          |
//  | STATE_RESET       |
//  | Out = 0           |
//  +-------------------+
//            |
//            |
//            |
//            |
//            V
//  +-------------------+
//  | State1 =          |
//  | STATE_ON          |<--------------+
//  | Out = 1           |               |
//  +-------------------+               |
//            |                         |
//            |                         |
//           -+- Timer1 >= Time_on_ms  -+- Timer1 >= Time_off_ms
//            |                         |
//            V                         |
//  +-------------------+               |
//  | State1 =          |               |
//  | STATE_OFF         |---------------+
//  | Out = 0           |
//  +-------------------+

//  Out
//  ^
//  |     Time_on_ms   Time_off_ms
//  |   |<---------->|<----------->|
// 1|   **************             *****
//  |   *            *             *
// 0*****------------***************------> t[ms]

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
