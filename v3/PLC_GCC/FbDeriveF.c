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

  //W(s)=s/(1+Tdf*s) при Tdf=1/Kdf и Ts->0.
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
//    |        1        |
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

//  +---------+
//  | GNU GPL |
//  +---------+
//  |
//  |
//  .= .-_-. =.
// ((_/)o o(\_))
//  `-'(. .)`-'
//  |/| \_/ |\
//  ( |     | )
//  /"\_____/"\
//  \__)   (__/
// @COPYLEFT ALL WRONGS RESERVED :)
// Author: VA
// Contacts: DIY.PLC.314@gmail.com
// License: GNU GPL v2
