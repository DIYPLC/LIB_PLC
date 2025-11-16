// Производная с фильтром.
//      DbDeriveF
//    +-----------+
//    | FbDeriveF |
// ->-|In      Out|->-
//   -|Kdf        |
//   -|Ts         |
//    +-----------+
/*
  Пример вызова программы. Выполнять код каждые Ts = 100 мс.
  static struct DbDeriveF DbDeriveF1 = {0};
  DbDeriveF1.In    = 0.0           ; // Входной сигнал.
  DbDeriveF1.Kdf   = 1.0           ; // Коэффициент фильтрации дифференциальный Kdf=1/Tdf.
  DbDeriveF1.Ts    = 0.1           ; // Шаг дискретизации по времени [с].
  FbDeriveF(&DbDeriveF1)           ; // Производная с фильтром.
  //               = DbDeriveF1.Out; // Выходной сигнал.
*/

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

struct DbDeriveF
{
  // Входные переменные, сохраняемые.
  float In       ; // Входной сигнал.
  float Kdf      ; // Коэффициент фильтрации дифференциальный Kdf=1/Tdf.
  float Ts       ; // Шаг дискретизации по времени [с].
  // Выходные переменные, сохраняемые.
  float Out      ; // Выходной сигнал.
  // Внутренние переменные, сохраняемые.
  float Dintegral; // Интегратор.
};

void FbDeriveF(struct DbDeriveF *p);

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
