#include <stdint.h>
#include <stdbool.h>
#include <iso646.h>
#include "FbFilterA.h"

#define In  p->In
#define Tf  p->Tf
#define Ts  p->Ts
#define Out p->Out

void FbFilterA(struct DbFilterA *p)
{

  // Внутренние переменные, не сохраняемые.
  float Tmp; // Временная переменная вход интегратора.

  // W(s) = 1 / (1 + Tf * s) при Ts->0.
  if (Tf <= 0.0)
  {
    Out = In;
  }
  else
  {
    Tmp = (In - Out) / Tf;
    Out = Out + Tmp * Ts;
  }

  return;
}

// Внутренняя схема фильтра.
//
//          Вычитание   Деление      Интегрирование
//            +---+     +------+     +----------+
// In ----->--| + |     |   1  | Tmp |  Ts * z  |
//            |   |-->--| ---- |-->--| -------- |--+-->-- Out
//      +-->--| - |     |  Tf  |     |   z - 1  |  |
//      |     +---+     +------+     +----------+  |
//      |                                          |
//      +------------------------------------------+

// Условное графическое обозначение (приближенное).
//
//    +--------------+
//    |      1       |
// ->-| ------------ |->-
//    |  Tf * s + 1  |
//    +--------------+

// Электрическая схема фильтра.
//
//         R
// +    +-----+              +
// o----|     |----o---------o
//      +-----+    |
//                 | C
//               -----
// U In          -----   U Out
//                 |
// -               |         -
// o---------------o---------o
// Tf = R * C ([с] = [Ом] * [Ф])

// Временная характеристика.
//
// ^ Out
// |
// 1         *** Y(t) = 1 - exp(-(t/Tf))
// |      *
// |    *
// |  *
// | *
// 0---------------> t[s]
//
// ^ In
// |
// 1************ X(t) = 1
// |
// |
// |
// |
// 0---------------> t[s]

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
