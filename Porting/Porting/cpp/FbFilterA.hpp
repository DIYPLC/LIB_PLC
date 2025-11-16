// Фильтр апериодический.
//      DbFilterA
//    +-----------+
//    | FbFilterA |
// ->-|In      Out|->-
//   -|Tf         |
//   -|Ts         |
//    +-----------+
/*
  Пример вызова программы. Выполнять код каждые Ts = 0.1с.
  static FbFilterA DbFilterA;
  DbFilterA.In = 0.0          ; // Входной сигнал до фильтрации.
  DbFilterA.Tf = 1.0          ; // Постоянная времени фильтра [с].
  DbFilterA.Ts = 0.1          ; // Шаг дискретизации по времени [с].
  DbFilterA()                 ; // Фильтр апериодический.
  //           = DbFilterA.Out; // Выходной сигнал после фильтрации.
*/
#pragma once

class FbFilterA {
public:
  // Входные переменные, сохраняемые.
  float In = 0.0;  // Входной сигнал до фильтрации.
  float Tf = 1.0;  // Постоянная времени фильтра [с].
  float Ts = 0.1;  // Шаг дискретизации по времени [с].
  // Выходные переменные, сохраняемые.
  float Out = 0.0;  // Выходной сигнал после фильтрации.
  void operator()();
private:
  // Внутренние переменные, сохраняемые.
};

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
