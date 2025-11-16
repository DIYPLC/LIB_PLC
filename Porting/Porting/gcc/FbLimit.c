#include <stdint.h>
#include <stdbool.h>
#include <iso646.h>
#include "FbLimit.h"

#define In     p->In
#define OutMax p->OutMax
#define OutMin p->OutMin
#define Out    p->Out

void FbLimit(struct DbLimit *p)
{

  // Амплитудный ограничитель.
  if (In >= OutMax)
  {
    Out = OutMax; // Ограничение выхода сверху.
  }
  else
  {
    if (In <= OutMin)
    {
      Out = OutMin; // Ограничение выхода снизу.
    }
    else
    {
      Out = In; // Выход без ограничений.
    }
  }

  return;
}

// Условное графическое обозначение.
//
//         OutMax
//      +-----------+
//      |           |
//      |       +-- |
//      |      /    |
// In->-|     /     |->-Out
//      |    /      |
//      | --+       |
//      |           |
//      +-----------+
//         OutMin

// Статическая характеристика.
//
//                +Out
//                  |
//                  |     ********
//                  |    *   |
//                  |   *    |
//                  |  *     | OutMax
//                  | *      |
//                  |*       |
// -In <------------+------------> +In
//         |       *|
//         |      * |
//  OutMin |     *  |
//         |    *   |
//         |   *    |
//     ********     |
//                  |
//                -Out

// Временная характеристика.
//
// +In
// |            *
// |           * *
// |----------*---* -----------------
// |         *     *               |
// |        *       *              | OutMax
// |       *         *             |
// +------*-----------*----------------------> t[s]
// |     *             *           |
// |    *               *          | OutMin
// |   *                 *         |
// |--*-------------------*----------
// | *                     *
// |*                       *
// -In
//
// +Out
// |
// |
// |----------***** -----------------
// |         *     *               |
// |        *       *              | OutMax
// |       *         *             |
// +------*-----------*----------------------> t[s]
// |     *             *           |
// |    *               *          | OutMin
// |   *                 *         |
// |***-------------------***--------
// |
// |
// -Out

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
