#include <stdint.h>
#include <stdbool.h>
#include <iso646.h>
#include "Fb3PosControl.h"

#define PV      p->PV
#define SP      p->SP
#define DBand   p->DBand
#define HystPos p->HystPos
#define HystNeg p->HystNeg
#define OpPos   p->OpPos
#define OpNeg   p->OpNeg
#define ER      p->ER

void Fb3PosControl(struct Db3PosControl *p)
{

  // Ошибка регулирования.
  ER = SP - PV;

  // ВКЛ нагрев или движение вперед.
  if (ER >= (DBand + HystPos))
  {
    OpPos = true;
  }

  // ВЫКЛ нагрев или движение вперед.
  if (ER <= (DBand - HystPos))
  {
    OpPos = false;
  }

  // ВКЛ охлаждение или движение назад.
  if (ER <= (0.0 - DBand - HystNeg))
  {
    OpNeg = true;
  }

  // ВЫКЛ охлаждение или движение назад.
  if (ER >= (0.0 - DBand + HystNeg))
  {
    OpNeg = false;
  }

  return;
}

// Применение.
//
// Трехпозиционный регулятор используется как простейший регулятор температуры или положения.

// Статическая характеристика.
//
//                           OpPos
//                             ^
//                             |  DBand
//                             |<-------->|
//                             |          |
//                             |   HystPos|HystPos
//                             |   |<---->|<---->|
//                             |   |      |      |
//                            1|---***<***1***<******
//                             |   *      |      *
//                             |   v      |      ^
//                             |   *      |      *
// -ER <-----***<*******<******0******>*******>***-----> +ER
//           *      |      *   |
//           v      |      ^   |
//           *      |      *   |
//        ******>***1***>***---|-1
//           |      |      |   |
//           |<---->|<---->|   |
//           HystHeg|HystHeg   |
//                  |          |
//                  |<-------->|
//                     DBand   |
//                             v
//                           OpNeg

// Схема включения.
//
//        +---------------+     +-------------+     +-------------+
// SP-->--|SP        OpPos|-->--| Нагреватель |-->--| Датчик      |--+-->PV
//        |               |     +-------------+     | температуры |  |
//        |               |                         |             |  |
//        |               |     +-------------+     |             |  |
//     +--|PV        OpNeg|-->--| Охладитель  |-->--|             |  |
//     |  +---------------+     +-------------+     +-------------+  |
//     |                                                             |
//     +-------------------------------------------------------------+
//
//        +---------------+     +--------------+     +-------------+
// SP-->--|SP        OpPos|-->--| Мотор вперед |-->--| Датчик      |--+-->PV
//        |               |     +--------------+     | положения   |  |
//        |               |                          |             |  |
//        |               |     +--------------+     |             |  |
//     +--|PV        OpNeg|-->--| Мотор назад  |-->--|             |  |
//     |  +---------------+     +--------------+     +-------------+  |
//     |                                                              |
//     +--------------------------------------------------------------+

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
