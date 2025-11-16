// Амплитудный ограничитель.
//       DbLimit
//    +-----------+
//    |  FbLimit  |
// ->-|In      Out|->-
//   -|OutMax     |
//   -|OutMin     |
//    +-----------+
/*
  Пример вызова программы.
  static struct DbLimit DbLimit1 = {0};
  DbLimit1.In     = 0.0         ; // Вход амплитудного ограничителя.
  DbLimit1.OutMax = 100.0       ; // Максимальное значение выхода.
  DbLimit1.OutMin = 0.0         ; // Минимальное значение выхода.
  FbLimit(&DbLimit1)            ; // Амплитудный ограничитель.
  //              = DbLimit1.Out; // Выход амплитудного ограничителя.
*/

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

struct DbLimit
{
  // Входные переменные, сохраняемые.
  float In    ; // Вход амплитудного ограничителя.
  float OutMax; // Максимальное значение выхода.
  float OutMin; // Минимальное значение выхода.
  // Выходные переменные, сохраняемые.
  float Out   ; // Выход амплитудного ограничителя.
};

void FbLimit(struct DbLimit *p);

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
