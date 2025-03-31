#include <math.h>
#include <stdint.h>
#include "FbGSS.hpp"

void FbGSS::operator()() {

  Sine = Amplitude * sinf(2 * M_PI * (1.0 / Period) * CurrentTime + Phase) + Offset;
  Cosine = Amplitude * cosf(2 * M_PI * (1.0 / Period) * CurrentTime + Phase) + Offset;

  if (CurrentTime < PulseTime)  // Прямоугольные импульсы.
  {
    RectangleR = Amplitude + Offset;
    RectangleB = true;
  } else {
    RectangleR = Offset;
    RectangleB = false;
  }

  if (CurrentTime <= (Period * 0.5))  // Треугольные импульсы.
  {
    IntegratorTriangle = IntegratorTriangle + Ts;
  } else {
    IntegratorTriangle = IntegratorTriangle - Ts;
  }
  if (Period != 0.0) {
    Triangle = (((IntegratorTriangle * 2.0) / Period) * Amplitude) + Offset;
  }

  // Псевдослучайные числа линейный конгруэнтный метод.
  SummatorRnd = SummatorRnd * 1103515245 + 12345;
  // Принудительно отбрасывающей младшие 16 и один старший разряд.
  uint32_t Tmp;
  Tmp = SummatorRnd & 0b01111111111111110000000000000000;
  // Арифметический сдвиг вправо на 16бит.
  Tmp = Tmp >> 16;
  // Масштабирование 0...32767 -> 0...1
  Prnd = (((float)Tmp) / 32767.0) * Amplitude + Offset;

  CurrentTime = CurrentTime + Ts;  // Формирование периода.
  if (CurrentTime >= Period) {
    CurrentTime = 0.0;
    IntegratorTriangle = 0.0;
  }

  return;
}
