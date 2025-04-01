// Генератор сигналов и псевдослучайных чисел.
//             DbGSS
//    +---------------------+
//    |        FbGSS        |
//   -|Amplitude        Sine|->-
//   -|Period         Cosine|->-
//   -|Phase      RectangleR|->-
//   -|Offset       ctangleB|->-
//   -|PulseTime    Triangle|->-
//   -|Ts               Prnd|->-
//    +---------------------+

class FbGSS {
  public:
    // Входные переменные, сохраняемые.
    float Amplitude = 1.0;  // Амплитуда выходного сигнала.
    float Period = 10.0;    // Период выходного сигнала [с].
    float Phase = 0.0;      // Фаза выходного сигнала [рад].
    float Offset = 0.0;     // Постоянная составляющая выходного сигнала.
    float PulseTime = 5.0;  // Время импульса [с].
    float Ts = 0.1;         // Шаг дискретизации по времени [с].
    // Выходные переменные, сохраняемые.
    float Sine = 0.0;         // Синусоидальный сигнал.
    float Cosine = 0.0;       // Косинусоидальный сигнал.
    float RectangleR = 0.0;   // Прямоугольный сигнал вещественный.
    bool RectangleB = false;  // Прямоугольный сигнал булевый.
    float Triangle = 0.0;     // Треугольный, линейно нарастающий и убывающий сигнал.
    float Prnd = 0.0;         // Псевдослучайные числа в диапазоне 0...1.
    void operator()();
  private:
    // Внутренние переменные, сохраняемые.
    float CurrentTime = 0.0;         // Текущее время расчета [с].
    float IntegratorTriangle = 0.0;  // Интегратор для треугольных импульсов.
    uint32_t SummatorRnd = 1;        // Сумматор для псевдослучайных чисел.
};

/*
  Пример вызова программы. Выполнять код каждые Ts = 0.1 с.
  static FbGSS DbGSS;
  DbGSS1.Period = 1.0;          // Период выходного сигнала [с].
  DbGSS1.PulseTime = 0.5;       // Время импульса [с].
  DbGSS1.Ts = 0.1;              // Шаг дискретизации по времени [с].
  DbGSS1();                     // Генератор сигналов и псевдослучайных чисел.
  bool a = DbGSS1.RectangleR;   // Прямоугольный сигнал вещественный.
  float b = DbGSS1.RectangleB;  // Прямоугольный сигнал булевый.
*/

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
