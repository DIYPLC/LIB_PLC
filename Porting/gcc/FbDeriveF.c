#include <stdint.h>
#include <stdbool.h>
#include <iso646.h>
#include "FbDeriveF.h"

#define In        p->In
#define Kdf       p->Kdf
#define Ts        p->Ts
#define Out       p->Out
#define Dintegral p->Dintegral

void FbDeriveF(struct DbDeriveF *p)
{

  // W(s)=s/(1+Tdf*s) при Tdf=1/Kdf и Ts->0.
  if (Kdf <= 0.0)
  {
    Dintegral = 0.0;
    Out = 0.0;
  }
  else
  {
    Out = (In - Dintegral) * Kdf;
    Dintegral = Dintegral + (Ts * Out);
  }

  return;
}

// Внутренняя схема фильтра.
//
//          Вычитание   Умножение
//            +---+     +------+
// In ----->--| + |     |      |
//            |   |-->--| *Kdf |-->----+-->-- Out
//      +-->--| - |     |      |       |
//      |     +---+     +------+       |
//      |                              |
//      |              Интегрирование  |
//      |              +----------+    |
//      |   Dintegral  |  Ts * z  |    |
//      +--------------| -------- |----+
//                     |   z - 1  |
//                     +----------+

// Условное графическое обозначение (приближенное).
//
//    +-----------------+
//    |        s        |
// ->-| --------------- |->-
//    | (1/Kdf) * s + 1 |
//    +-----------------+

// Электрическая схема фильтра.
//
// +    || C            +
// o----||----o---------o
//      ||    |
//  U In      |     U Out
//           +-+
//           | | R
//           | |
//           +-+
//            |
// -          |         -
// o----------o---------o
// Tf = 1/Kdf = R * C ([с] = [Ом] * [Ф])

// Временная характеристика.
//
// ^ Out
// |
// 1*            Y(t) = 0 - exp(-(t/Tf))
// | *
// |  *
// |    *
// |      *
// 0---------***---> t[s]
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
