// Детектор ниспадающего фронта (среза).
//       DbEdgeNeg
//     +-----------+
//     | FbEdgeNeg |
//  ->-|In      Out|->-
//     +-----------+
/*
  Пример вызова программы.
  static struct DbEdgeNeg DbEdgeNeg1 = {0};
  DbEdgeNeg1.In = false         ; // Вход.
  FbEdgeNeg(&DbEdgeNeg1)        ; // Детектор ниспадающего фронта (среза).
  //            = DbEdgeNeg1.Out; // Выход.
*/

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

struct DbEdgeNeg
{
  // Входные переменные, сохраняемые.
  bool In        ; // Вход.
  // Выходные переменные, сохраняемые.
  bool Out       ; // Выход.
  // Внутренние переменные, сохраняемые.
  bool In_previos; // Предыдущее состояние входа.
};

void FbEdgeNeg(struct DbEdgeNeg *p);

#ifdef __cplusplus
}
#endif

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
