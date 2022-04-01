#include <stdint.h>
#include <stdbool.h>
#include <iso646.h>
#include "FbRamp.h"

#define In      p->In
#define TAcc    p->TAcc
#define TDec    p->TDec
#define Ts      p->Ts
#define Out     p->Out
#define AccMode p->AccMode
#define DecMode p->DecMode

void FbRamp(struct DbRamp *p)
{

  AccMode = (In  > Out); //Активен режим ускорения.
  DecMode = (In  < Out); //Активен режим замедления.

  //Режим замедления.
  if (DecMode)
  {
    if (TDec <= 0.0)
    {
      Out = In;
    }
    else
    {
      Out = Out - (Ts / TDec);
    }
  }

  //Режим ускорения.
  if (AccMode)
  {
    if (TAcc <= 0.0)
    {
      Out = In;
    }
    else
    {
      Out = Out + (Ts / TAcc);
    }
  }

  //Установившийся режим.
  if ((AccMode and (Out >= In)) or (DecMode and (Out <= In)) or (In = Out))
  {
    Out = In;
  }

  return;
}

// Временная характеристика.
//
// ^ In
// |
// 1  *************
// |  *           *
// |  *           *
// |  *           *
// 0--------------------> t[s]
//
// ^ Out
// |
// |   TAcc       TDec
// |    1s        0.5s
// |  <----->     <-->
// 1        *******
// |      *        *
// |    *           *
// |  *              *
// 0--------------------> t[s]

// Блок схема.
//
// Константы    Переключатель    Интегратор
// +------+     +-----------+
// |  1   |     | In > Out  |
// | ---- |-->--|--+        |
// | TAcc |     |   \       |
// +------+     |    \      |
//              |     \     |
// +------+     |      \    |     +-----+
// |      |     |       \   |     |  1  |
// |  0   |-->--|--+     +--|-->--| --- |-->-- Out
// |      |     | In ~= Out |     |  s  |
// +------+     |           |     +-----+
//              |           |
// +------+     |           |
// |  1   |     |           |
// | ---- |-->--|--+        |
// | TDec |     | In < Out  |
// +------+     +-----------+

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
