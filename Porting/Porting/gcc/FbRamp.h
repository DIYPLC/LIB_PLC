// Рампа разгона / торможения.
//        DbRamp
//    +------------+
//    |   FbRamp   |
// ->-|In       Out|->-
//   -|TAcc        |
//   -|TDec        |
//   -|Ts          |
//    +------------+
/*
  Пример вызова программы. Выполнять код каждые Ts = 0.1 с.
  static struct DbRamp DbRamp1 = {0};
  DbRamp1.In   = 0.0        ; // Входной сигнал.
  DbRamp1.TAcc = 1.0        ; // Время разгона на единицу [с].
  DbRamp1.TDec = 1.0        ; // Время торможения на единицу [c].
  DbRamp1.Ts   = 0.1        ; // Шаг дискретизации по времени [с].
  FbRamp(&DbRamp1)          ; // Рампа разгона / торможения.
  //           = DbRamp1.Out; // Выходной сигнал.
*/

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

struct DbRamp
{
  // Входные переменные, сохраняемые.
  float In     ; // Входной сигнал.
  float TAcc   ; // Время разгона на единицу [с].
  float TDec   ; // Время торможения на единицу [c].
  float Ts     ; // Шаг дискретизации по времени [с].
  // Выходные переменные, сохраняемые.
  float Out    ; // Выходной сигнал.
  // Внутренние переменные, сохраняемые.
  bool AccMode; // Активен режим ускорения.
  bool DecMode; // Активен режим замедления.
};

void FbRamp(struct DbRamp *p);

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
