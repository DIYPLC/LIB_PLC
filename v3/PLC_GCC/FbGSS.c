#include <stdint.h>
#include <stdbool.h>
#include <iso646.h>
#include <math.h>
#include "FbGSS.h"

#define Amplitude          p->Amplitude
#define Period             p->Period
#define Phase              p->Phase
#define Offset             p->Offset
#define PulseTime          p->PulseTime
#define Ts                 p->Ts
#define Sine               p->Sine
#define Cosine             p->Cosine
#define RectangleR         p->RectangleR
#define RectangleB         p->RectangleB
#define Triangle           p->Triangle
#define Prnd               p->Prnd
#define CurrentTime        p->CurrentTime
#define IntegratorTriangle p->IntegratorTriangle
#define SummatorRnd        p->SummatorRnd

void FbGSS(struct DbGSS *p)
{

  //Временные переменные, не сохраняемые.
  uint32_t Tmp;

  Sine =   Amplitude * sinf(2 * M_PI * (1.0 / Period) * CurrentTime + Phase) + Offset; //Синус.
  Cosine = Amplitude * cosf(2 * M_PI * (1.0 / Period) * CurrentTime + Phase) + Offset; //Косинус.

  if (CurrentTime < PulseTime) //Прямоугольные импульсы.
  {
    RectangleR = Amplitude + Offset;
    RectangleB = true;
  }
  else
  {
    RectangleR = Offset;
    RectangleB = false;
  }

  if (CurrentTime <= (Period * 0.5)) //Треугольные импульсы.
  {
    IntegratorTriangle = IntegratorTriangle + Ts;
  }
  else
  {
    IntegratorTriangle = IntegratorTriangle - Ts;
  }
  if (Period != 0.0)
  {
    Triangle = (((IntegratorTriangle * 2.0) / Period) * Amplitude) + Offset;
  }

  //Псевдослучайные числа линейный конгруэнтный метод.
  SummatorRnd = SummatorRnd * 1103515245 + 12345;
  //принудительно отбрасывающей младшие 16 и один старший разряд.
  Tmp = SummatorRnd & 0b01111111111111110000000000000000;
  //Арифметический сдвиг вправо на 16бит.
  Tmp = Tmp >> 16;
  //Масштабирование 0...32767 -> 0...1
  Prnd = ( ((float)Tmp) / 32767.0 ) * Amplitude + Offset;

  CurrentTime = CurrentTime + Ts; //Формирование периода.
  if (CurrentTime >= Period)
  {
    CurrentTime = 0.0;
    IntegratorTriangle = 0.0;
  }

  return;
}

//  +---------+
//  | GNU GPL |
//  +---------+
//  |
//  |
//  .= .-_-. =.
// ((_/)o o(\_))
//  `-'(. .)`-'
//  |/| \_/ |\
//  ( |     | )
//  /"\_____/"\
//  \__)   (__/
// @COPYLEFT ALL WRONGS RESERVED :)
// Author: VA
// Contacts: DIY.PLC.314@gmail.com
// License: GNU GPL v2
