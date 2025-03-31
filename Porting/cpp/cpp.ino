#include "FbGSS.hpp"

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  delay(100);  // TODO.

  static FbGSS DbGSS1;
  DbGSS1.Period = 1.0;          // Период выходного сигнала [с].
  DbGSS1.PulseTime = 0.5;       // Время импульса [с].
  DbGSS1.Ts = 0.1;              // Шаг дискретизации по времени [с].
  DbGSS1.Run();                 // Генератор сигналов и псевдослучайных чисел.
  bool a = DbGSS1.RectangleR;   // Прямоугольный сигнал вещественный.
  float b = DbGSS1.RectangleB;  // Прямоугольный сигнал булевый.

  if (DbGSS1.RectangleB) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}
