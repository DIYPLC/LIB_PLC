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

class FbGSS
{
  public:
    void Run(void);
    void Set_Amplitude(float value);
    void Set_Period(float value);
    void Set_Phase(float value);
    void Set_Offset(float value);
    void Set_PulseTime(float value);
    void Set_Ts(float value);
    float Get_Sine(void);
    float Get_Cosine(void);
    float Get_RectangleR(void);
    bool  Get_RectangleB(void);
    float Get_Triangle(void);
    float Get_Prnd(void);
  private:
    // Входные переменные, сохраняемые.
    float Amplitude = 1.0 ; // Амплитуда выходного сигнала.
    float Period    = 10.0; // Период выходного сигнала [с].
    float Phase     = 0.0 ; // Фаза выходного сигнала [рад].
    float Offset    = 0.0 ; // Постоянная составляющая выходного сигнала.
    float PulseTime = 5.0 ; // Время импульса [с].
    float Ts        = 0.1 ; // Шаг дискретизации по времени [с].
    // Выходные переменные, сохраняемые.
    float Sine       = 0.0  ; // Синусоидальный сигнал.
    float Cosine     = 0.0  ; // Косинусоидальный сигнал.
    float RectangleR = 0.0  ; // Прямоугольный сигнал вещественный.
    bool  RectangleB = false; // Прямоугольный сигнал булевый.
    float Triangle   = 0.0  ; // Треугольный, линейно нарастающий и убывающий сигнал.
    float Prnd       = 0.0  ; // Псевдослучайные числа в диапазоне 0...1.
    // Внутренние переменные, сохраняемые.
    float    CurrentTime        = 0.0; // Текущее время расчета [с].
    float    IntegratorTriangle = 0.0; // Интегратор для треугольных импульсов.
    uint32_t SummatorRnd        = 1  ; // Сумматор для псевдослучайных чисел.
};

/*
  Пример вызова программы. Выполнять код каждые Ts = 0.1 с.
  DbGSS1.Set_Period(1.0)                    ; // Период выходного сигнала [с].
  DbGSS1.Set_PulseTime(0.5)                 ; // Время импульса [с].
  DbGSS1.Set_Ts(GV.Ts)                      ; // Шаг дискретизации по времени [с].
  DbGSS1.Run()                              ; // Генератор сигналов и псевдослучайных чисел.
  GV.tmp_floats[0] = DbGSS1.Get_RectangleR(); // Прямоугольный сигнал вещественный.
  GV.Do0           = DbGSS1.Get_RectangleB(); // Прямоугольный сигнал булевый.
*/
