// Генератор сигналов и псевдослучайных чисел.
//             DbGSS
//    +---------------------+
//    |        FbGSS        |
//   -|Amplitude        Sine|->-
//   -|Period         Cosine|->-
//   -|Phase      RectangleR|->-
//   -|Offset     RectangleB|->-
//   -|PulseTime    Triangle|->-
//   -|Ts               Prnd|->-
//    +---------------------+
/*
  Пример вызова программы. Выполнять код каждые Ts = 0.1 с.
  static struct DbGSS DbGSS1 = {0};
  DbGSS1.Amplitude = 1.0              ; // Амплитуда выходного сигнала.
  DbGSS1.Period    = 10.0             ; // Период выходного сигнала [с].
  DbGSS1.Phase     = 0.0              ; // Фаза выходного сигнала [рад].
  DbGSS1.Offset    = 0.0              ; // Постоянная составляющая выходного сигнала.
  DbGSS1.PulseTime = 5.0              ; // Время импульса [с].
  DbGSS1.Ts        = 0.1              ; // Шаг дискретизации по времени [с].
  FbGSS(&DbGSS1)                      ; // Генератор сигналов и псевдослучайных чисел.
  //               = DbGSS1.Sine      ; // Синусоидальный сигнал.
  //               = DbGSS1.Cosine    ; // Косинусоидальный сигнал.
  //               = DbGSS1.RectangleR; // Прямоугольный сигнал вещественный.
  //               = DbGSS1.RectangleB; // Прямоугольный сигнал булевый.
  //               = DbGSS1.Triangle  ; // Треугольный, линейно нарастающий и убывающий сигнал.
  //               = DbGSS1.Prnd      ; // Псевдослучайные числа в диапазоне 0...1.
*/

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

struct DbGSS
{
  // Входные переменные, сохраняемые.
  float Amplitude ; // Амплитуда выходного сигнала.
  float Period    ; // Период выходного сигнала [с].
  float Phase     ; // Фаза выходного сигнала [рад].
  float Offset    ; // Постоянная составляющая выходного сигнала.
  float PulseTime ; // Время импульса [с].
  float Ts        ; // Шаг дискретизации по времени [с].
  // Выходные переменные, сохраняемые.
  float Sine       ; // Синусоидальный сигнал.
  float Cosine     ; // Косинусоидальный сигнал.
  float RectangleR ; // Прямоугольный сигнал вещественный.
  bool  RectangleB ; // Прямоугольный сигнал булевый.
  float Triangle   ; // Треугольный, линейно нарастающий и убывающий сигнал.
  float Prnd       ; // Псевдослучайные числа в диапазоне 0...1.
  // Внутренние переменные, сохраняемые.
  float    CurrentTime        ; // Текущее время расчета [с].
  float    IntegratorTriangle ; // Интегратор для треугольных импульсов.
  uint32_t SummatorRnd        ; // Сумматор для псевдослучайных чисел.
};

void FbGSS(struct DbGSS *p);

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
