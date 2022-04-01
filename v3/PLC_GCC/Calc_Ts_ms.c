#include <stdint.h>
#include <stdbool.h>
#include <iso646.h>
#include "Calc_Ts_ms.h"

uint32_t Calc_Ts_ms(uint32_t Uptime_ms)
{
  //Рассчет шага дискретизации по времени [мс].
  //На вход функции подать millis() или его аналоги.
  //Функцию можно вызвать только в одном месте циклически.
  static uint32_t Time_previous_ms = 0; //Предыдущее значение времени [мс].
  uint32_t Ts_ms = 0; //Шаг дискретизации по времени [мс].
  if (Time_previous_ms <= Uptime_ms)
  {
    Ts_ms = Uptime_ms - Time_previous_ms; //разность времени без переполнения (займа).
  }
  else
  {
    Ts_ms = (0xFFFFFFFF - Time_previous_ms) + Uptime_ms + 1; //разность времени при переполнении.
  }
  Time_previous_ms = Uptime_ms; //Запомнить предидущее состояние.
  return Ts_ms;
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
