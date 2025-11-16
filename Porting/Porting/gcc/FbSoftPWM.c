#include <stdint.h>
#include <stdbool.h>
#include <iso646.h>
#include "FbSoftPWM.h"

#define DutyCucle      p->DutyCucle
#define PeriodPositive p->PeriodPositive
#define PeriodNegative p->PeriodNegative
#define DBMAX          p->DBMAX
#define DBMIN          p->DBMIN
#define Ts             p->Ts
#define PWMPOS         p->PWMPOS
#define PWMNEG         p->PWMNEG
#define TimerPositive  p->TimerPositive
#define TimerNegative  p->TimerNegative

void FbSoftPWM(struct DbSoftPWM *p)
{

  // Временные переменные, не сохраняемые.
  float Percent          ; // Входной сигнал после зоны нечувствительности и амплитудного ограничителя -100...0...100[%].
  float TimePulsePositive; // Время импульса для положительного коэффициента заполнения [с].
  float TimePulseNegative; // Время импульса для отрицательного коэффициента заполнения [с].

  // Зона нечувствительности для входного сигнала.
  if ((DBMIN < DutyCucle) and (DutyCucle < DBMAX))
  {
    Percent = 0.0;
  }
  else
  {
    Percent = DutyCucle;
  }

  // Амплитудный ограничитель входного сигнала от -100% до 100%.
  if (Percent >= 100.0)
  {
    Percent = 100.0;
  }
  if (Percent <= -100.0)
  {
    Percent = -100.0;
  }

  // Формирование импульсов на открытие.
  if (Percent > 0.0)
  {
    PWMNEG = false;
    TimerNegative = 0.0;
    TimePulsePositive = PeriodPositive * Percent * 0.01;
    if (TimerPositive <= TimePulsePositive)
    {
      PWMPOS = true;
    }
    else
    {
      PWMPOS = false;
    }
    TimerPositive = TimerPositive + Ts;
    if (TimerPositive >= PeriodPositive)
    {
      TimerPositive = 0.0;
    }
  }

  // Формирование импульсов на закрытие.
  if (Percent < 0.0)
  {
    PWMPOS = false;
    TimerPositive = 0.0;
    TimePulseNegative = PeriodNegative * Percent * (-0.01);
    if (TimerNegative <= TimePulseNegative)
    {
      PWMNEG = true;
    }
    else
    {
      PWMNEG = false;
    }
    TimerNegative = TimerNegative + Ts;
    if (TimerNegative >= PeriodNegative)
    {
      TimerNegative = 0.0;
    }
  }

  // Нет импульсов.
  if (Percent == 0.0)
  {
    PWMPOS = false;
    PWMNEG = false;
    TimerPositive = 0.0;
    TimerNegative = 0.0;
  }

  return;
}

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
