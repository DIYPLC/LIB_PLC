// Мигалка.
//            DbBlink
//    +---------------------+
//    |       FbBlink       |
//   -|Time_on_ms        Out|->-
//   -|Time_off_ms          |
//   -|Ts_ms                |
//   -|Reset                |
//    +---------------------+
/*
  Пример вызова программы. Выполнять код каждые Ts_ms = 100 ms.
  static FbBlink DbBlink;
  DbBlink.Time_on_ms  = 1000        ; // Время импульса [мс].
  DbBlink.Time_off_ms = 1000        ; // Время паузы [мс].
  DbBlink.Ts_ms       = 100         ; // Шаг дискретизации по времени [мс].
  DbBlink.Reset       = false       ; // Сброс при перезагрузке.
  DbBlink()                         ; // Мигалка.
  //                  = DbBlink1.Out; // Мигающая лампочка.
*/
#pragma once

class FbBlink {
public:
  // Входные переменные, сохраняемые.
  uint32_t Time_on_ms = 2000;   // Время импульса [мс].
  uint32_t Time_off_ms = 2000;  // Время паузы [мс].
  uint32_t Ts_ms = 100;         // Шаг дискретизации по времени [мс].
  bool Reset = false;           // Сброс при перезагрузке.
  // Выходные переменные, сохраняемые.
  bool Out = false;  // Мигающая лампочка.
  void operator()();
private:
  // Внутренние переменные, сохраняемые.
  uint32_t Timer1 = 0;  // Внутренний таймер [мс].
  uint8_t State1 = 0;   // Внутренний граф состояния.
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
