// ПИД-регулятор.
//         DbPIDcontrol
//    +--------------------+
//    |    FbPIDcontrol    |
// ->-|PV                MV|->-
//   -|SP                  |
//   -|Kp                  |
//   -|Ki                  |
//   -|Kd                  |
//   -|Kdf                 |
//   -|ERMAX               |
//   -|ERMIN               |
//   -|MVMAX               |
//   -|MVMIN               |
//   -|Ts                  |
//   -|Manual              |
//   -|OnMan               |
//    +--------------------+
/*
  Пример вызова программы. Выполнять код каждые Ts = 0.1 с.
  static struct DbPIDcontrol DbPIDcontrol1 = {0};
  DbPIDcontrol1.PV     = 0.0              ; // Измеренное значение регулируемого параметра.
  DbPIDcontrol1.SP     = 0.0              ; // Заданное значение регулируемого параметра.
  DbPIDcontrol1.Kp     = 0.01             ; // Коэффициент усиления пропорциональный.
  DbPIDcontrol1.Ki     = 0.01             ; // Коэффициент усиления интегральный.
  DbPIDcontrol1.Kd     = 0.0              ; // Коэффициент усиления дифференциальный.
  DbPIDcontrol1.Kdf    = 1.0              ; // Коэффициент фильтрации дифференциальный Kdf=1/Tdf.
  DbPIDcontrol1.ERMAX  =  0.001           ; // Зона нечувствительности к ошибке регулирования, максимум.
  DbPIDcontrol1.ERMIN  = -0.001           ; // Зона нечувствительности к ошибке регулирования, минимум.
  DbPIDcontrol1.MVMAX  = 100.0            ; // Максимальное значение сигнала управления.
  DbPIDcontrol1.MVMIN  = 0.0              ; // Минимальное значение сигнала управления.
  DbPIDcontrol1.Ts     = 0.1              ; // Шаг дискретизации по времени в секундах.
  DbPIDcontrol1.Manual = 25.0             ; // Сигнал управления в ручном режиме работы.
  DbPIDcontrol1.ManOn  = false            ; // Включить ручной режим работы регулятора.
  FbPIDcontrol(&DbPIDcontrol1)            ; // ПИД-регулятор.
  //                   = DbPIDcontrol1.Out; // Сигнал управления на исполнительный механизм.
*/

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

struct DbPIDcontrol
{
  // Входные переменные, сохраняемые.
  float PV       ; // Измеренное значение регулируемого параметра.
  float SP       ; // Заданное значение регулируемого параметра.
  float Kp       ; // Коэффициент усиления пропорциональный.
  float Ki       ; // Коэффициент усиления интегральный.
  float Kd       ; // Коэффициент усиления дифференциальный.
  float Kdf      ; // Коэффициент фильтрации дифференциальный Kdf=1/Tdf.
  float ERMAX    ; // Зона нечувствительности к ошибке регулирования, максимум.
  float ERMIN    ; // Зона нечувствительности к ошибке регулирования, минимум.
  float MVMAX    ; // Максимальное значение сигнала управления.
  float MVMIN    ; // Минимальное значение сигнала управления.
  float Ts       ; // Шаг дискретизации по времени в секундах.
  float Manual   ; // Сигнал управления в ручном режиме работы.
  bool  OnMan    ; // Включить ручной режим работы регулятора.
  // Выходные переменные, сохраняемые.
  float MV       ; // Сигнал управления на исполнительный механизм.
  // Внутренние переменные, сохраняемые.
  float Er       ; // Ошибка регулирования.
  float Ppart    ; // Пропорциональная составляющая регулятора.
  float Ipart    ; // Интегратор интегральной составляющей регулятора.
  float Dpart    ; // Дифференциальная составляющая регулятора.
  float Dintegral; // Интегратор дифференциальной составляющей регулятора.
};

void FbPIDcontrol(struct DbPIDcontrol *p);

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
