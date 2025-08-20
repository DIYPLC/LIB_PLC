// Блок задержки сигнала на 100 тактов.
//      DbDelayN
//    +----------+
//    | FbDelayN |
// ->-|In     Out|->-
//    +----------+
/*
  Пример вызова программы.
  static struct DbDelayN DbDelayN1 = {0};
  DbDelayN1.In = 0.0          ; // Вход.
  FbDelayN(&DbDelayN1)        ; // Блок задержки сигнала на 100 тактов.
  //           = DbDelayN1.Out; // Выход.
*/

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

struct DbDelayN
{
  // Входные переменные, сохраняемые.
  float    In        ; // Вход.
  // Выходные переменные, сохраняемые.
  float    Out       ; // Выход.
  // Внутренние переменные, сохраняемые.
  float    Buffer[98+1]; // Буфер задержки сигнала.
};

void FbDelayN(struct DbDelayN *p);

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
