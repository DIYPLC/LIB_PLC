#include <stdint.h>
#include <stdbool.h>
#include <iso646.h>
#include "FbTimerTof.h"

#define In           p->In
#define TimeDelayOff p->TimeDelayOff
#define Ts_ms        p->Ts_ms
#define Out          p->Out
#define Timer1       p->Timer1

void FbTimerTof(struct DbTimerTof *p)
{
  if (TimeDelayOff > 0) //Таймер включен.
  {
    if (In) //На входе 1 то на выходе тоже 1.
    {
      Out = true;
      Timer1 = 0;
    }
    else //Если на входе 0.
    {
      if (Out) //На выходе 1.
      {
        if (Timer1 >= TimeDelayOff) //Задержка включения закончилась.
        {
          Out = false;
          Timer1 = 0;
        }
        else //Задержка включения активна.
        {
          Out = true;
          Timer1 = Timer1 + Ts_ms;
        };
      }
      else //На выходе 0.
      {
        Out = false;
        Timer1 = 0;
      }
    }
  }
  else //Таймер выключен.
  {
    Out = In;
    Timer1 = 0;
  }

  return;
}

// Применение.
//
//Блок может применятся как фильтр дребезга контактов и как расширитель импульсов.

// Временная характеристика.
//
//  In
//  ^
//  |     TimeDelayOff          TimeDelayOff
//  |       |<--->|               |<--->|
// 1|   *****     |     ***** *** *     |
//  |   *   *     |     *   * * * *     |
// 0*****---*************---***-*************----> t[s]
//
//  Out
//  ^
//  |     TimeDelayOff          TimeDelayOff
//  |       |<--->|               |<--->|
// 1|   ***********     *****************
//  |   *         *     *               *
// 0*****---------*******---------------*****----> t[s]

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
