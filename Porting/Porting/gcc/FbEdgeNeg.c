#include <stdint.h>
#include <stdbool.h>
#include <iso646.h>
#include "FbEdgeNeg.h"

#define In         p->In
#define Out        p->Out
#define In_previos p->In_previos

void FbEdgeNeg(struct DbEdgeNeg *p)
{

  // Детектор ниспадающего фронта (среза).
  Out = In_previos and not(In);
  // Запомнить предыдущее состояние входа.
  In_previos = In;

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
