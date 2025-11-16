#include <stdint.h>
#include <stdbool.h>
#include <iso646.h>
#include "FbBitsToWord.h"

#define In0  p->In0
#define In1  p->In1
#define In2  p->In2
#define In3  p->In3
#define In4  p->In4
#define In5  p->In5
#define In6  p->In6
#define In7  p->In7
#define In8  p->In8
#define In9  p->In9
#define In10 p->In10
#define In11 p->In11
#define In12 p->In12
#define In13 p->In13
#define In14 p->In14
#define In15 p->In15
#define Out  p->Out

void FbBitsToWord(struct DbBitsToWord *p)
{

  Out = 0;
  if (In0 )
  {
    Out = (Out bitor 0b0000000000000001);
  }
  if (In1 )
  {
    Out = (Out bitor 0b0000000000000010);
  }
  if (In2 )
  {
    Out = (Out bitor 0b0000000000000100);
  }
  if (In3 )
  {
    Out = (Out bitor 0b0000000000001000);
  }
  if (In4 )
  {
    Out = (Out bitor 0b0000000000010000);
  }
  if (In5 )
  {
    Out = (Out bitor 0b0000000000100000);
  }
  if (In6 )
  {
    Out = (Out bitor 0b0000000001000000);
  }
  if (In7 )
  {
    Out = (Out bitor 0b0000000010000000);
  }
  if (In8 )
  {
    Out = (Out bitor 0b0000000100000000);
  }
  if (In9 ) {
    Out = (Out bitor 0b0000001000000000);
  }
  if (In10)
  {
    Out = (Out bitor 0b0000010000000000);
  }
  if (In11)
  {
    Out = (Out bitor 0b0000100000000000);
  }
  if (In12)
  {
    Out = (Out bitor 0b0001000000000000);
  }
  if (In13)
  {
    Out = (Out bitor 0b0010000000000000);
  }
  if (In14)
  {
    Out = (Out bitor 0b0100000000000000);
  }
  if (In15)
  {
    Out = (Out bitor 0b1000000000000000);
  }

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
