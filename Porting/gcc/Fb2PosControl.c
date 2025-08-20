#include <stdint.h>
#include <stdbool.h>
#include <iso646.h>
#include "Fb2PosControl.h"

#define PV   p->PV
#define SP   p->SP
#define HYST p->HYST
#define OP   p->OP
#define ER   p->ER

void Fb2PosControl(struct Db2PosControl *p)
{

  // Ошибка регулирования.
  ER = SP - PV;

  // Регулятор двухпозиционный.
  if (ER >= HYST)
  {
    OP = true;
  }

  if (ER <= HYST * (-1.0))
  {
    OP = false;
  }

  return;
}

// Применение.
//
// Двухпозиционный регулятор используется как простейший регулятор температуры, давления, уровня.

// Условное графическое обозначение.
//
//      +---------------+
//      |               |
//      |    +--<--+--  |
//      |    |     |    |
// ER->-|    v     ^    |->-OP
//      |    |     |    |
//      |  --+-->--+    |
//      |               |
//      +---------------+

// Статическая характеристика.
//
//                 OP
//                  ^
//                  |
//           ***<***1***<******
//           *      |      *
//           v      |      ^
//           *      |      *
// -ER <--******>***0***>***--> +ER
//           |      |      |
//           |<---->|<---->|
//             HYST   HYST

// Временная характеристика.
//
// ^ PV,SP
// |         PV
// |----------*---------------*------
// |         * *             * *   |
// |        *   *           *   *  |  SP + HYST
// |       *     *         *       |
// |======*=======*=======*========== SP
// |     *         *     *         |
// |    *           *   *          |  SP - HYST
// |   *             * *           |
// |--*---------------*--------------
// | *
// |*
// +-----------------------------------------> t[s]
//
// ^ OP
// |
// 1***********       *********
// |          *       *       *
// 0----------*********-------***------------> t[s]

// Схема включения.
//
//                  +---------------+
//                  |               |   Объект управления
//                  |    +--<--+--  |     +-----------+
//        +---+ ER  |    |     |    | OP  |     K     |
// SP-->--| + |-->--|    v     ^    |-->--| --------- |-->--+-->PV
// PV  +--| - |     |    |     |    |     | T * s + 1 |     |
//     |  +---+     |  --+-->--+    |     +-----------+     |
//     |            |               |                       |
//     |            +---------------+                       |
//     |                                                    |
//     +----------------------------------------------------+

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
