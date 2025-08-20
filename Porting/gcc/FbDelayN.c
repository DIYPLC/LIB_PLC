#include <stdint.h>
#include <stdbool.h>
#include <iso646.h>
#include "FbDelayN.h"

#define In     p->In
#define Out    p->Out
#define Buffer p->Buffer

void FbDelayN(struct DbDelayN *p)
{
  // W(Z)=Z^(-100)
  Out = Buffer[98];
  for (uint8_t i = 98; i >= 1; i = i - 1) // i с 98 до 1 с шагом -1
  {
    Buffer[i] = Buffer[i - 1]; // Buffer[0]...Buffer[98]
  }
  Buffer[0] = In;

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
