//Программирование в стиле ПЛК версия от 27.03.2022.
//Библиотека LibPlc для gcc детально не протестирована, нет MODBUS.
//Основной алгоритм в FcTaskCyclic1.c
//Ресурсы ПЛК в GlobalVar.h
//Arduino Nano
//Arduino IDE 1.8.13
//Windows 10 pro 64bit
#include <stdint.h>
#include "GlobalVar.h"
#include "Calc_Ts_ms.h"
#include "FcTaskCyclic1.h"
//#include "FcTaskCyclic2.h"
#include "Digital_output.h"

struct GlobalVar GV = {0};

void Plotter_UART(float line1, float line2)
{
  Serial.print(line1);
  Serial.print(',');
  Serial.println(line2);
  return;
}

void Plotter_UART_init(void)
{
  Serial.begin(9600);
  Serial.println("line1, line2");
}

void setup()
{
  Plotter_UART_init();
  GV.Uptime_ms = millis(); //Время работы [мс].
  GV.Ts_ms = 0           ; //Время предидущего скана [мс].
  GV.Ts = 0.0            ; //Время предидущего скана [с].
  GV.Reset = true        ; //Флаг первого скана.
  FcTaskCyclic1();
  //FcTaskCyclic2();
  Digital_output_init();
}

void loop()
{
  GV.Uptime_ms = millis()            ; //Время работы [мс].
  GV.Ts_ms = Calc_Ts_ms(GV.Uptime_ms); //Время предидущего скана [мс].
  GV.Ts = ((float)GV.Ts_ms) * 0.001  ; //Время предидущего скана [с].
  GV.Reset = false                   ; //Флаг первого скана.
  FcTaskCyclic1(); //Регулятор давления
  //FcTaskCyclic2(); //Юнит тест LibPlc
  Digital_output_cyclic();
  Plotter_UART(GV.tmp_floats[0], GV.tmp_floats[1]);
  if (GV.Ts_ms > GV.Ts_max_ms) {
    GV.Ts_max_ms = GV.Ts_ms;
  } //Максимальное время скана [мс].
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
