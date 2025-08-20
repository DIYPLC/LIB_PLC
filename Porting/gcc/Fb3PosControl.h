// Регулятор трехпозиционный.
//       Db3PosControl
//     +---------------+
//     | Fb3PosControl |
//  ->-|PV        OpPos|->-
//    -|SP        OpNeg|->-
//    -|DBand          |
//    -|HystPos        |
//    -|HystNeg        |
//     +---------------+
/*
  Пример вызова программы.
  static struct Db3PosControl Db3PosControl1 = {0};
  Db3PosControl1.PV      = 0.0                  ; // Измеренное значение регулируемого параметра.
  Db3PosControl1.SP      = 0.0                  ; // Заданное значение регулируемого параметра.
  Db3PosControl1.DBand   = 2.0                  ; // Зона нечувствительности > 0.
  Db3PosControl1.HystPos = 1.0                  ; // Гистерезис > 0.
  Db3PosControl1.HystNeg = 1.0                  ; // Гистерезис > 0.
  Fb3PosControl(&Db3PosControl1)                ; // Регулятор трехпозиционный.
  //                     = Db3PosControl1.OpPos ; // Выход управляющего сигнала положительный.
  //                     = Db3PosControl1.OpNeg ; // Выход управляющего сигнала отрицательный.
*/

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

struct Db3PosControl
{
  // Входные переменные, сохраняемые.
  float PV     ; // Измеренное значение регулируемого параметра.
  float SP     ; // Заданное значение регулируемого параметра.
  float DBand  ; // Зона нечувствительности > 0.
  float HystPos; // Гистерезис > 0.
  float HystNeg; // Гистерезис > 0.
  // Выходные переменные, сохраняемые.
  bool  OpPos  ; // Выход управляющего сигнала положительный.
  bool  OpNeg  ; // Выход управляющего сигнала отрицательный.
  // Внутренние переменные, сохраняемые.
  float ER     ; // Ошибка регулирования.
};

void Fb3PosControl(struct Db3PosControl *p);

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
