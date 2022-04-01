#include <stdint.h>
#include <stdbool.h>
#include <iso646.h>
#include "FbEdgeNeg.h"

#define In         p->In
#define Out        p->Out
#define In_previos p->In_previos

void FbEdgeNeg(struct DbEdgeNeg *p)
{

  //Детектор ниспадающего фронта (среза).
  Out = In_previos and not(In);
  //Запомнить предыдущее состояние входа.
  In_previos = In;

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
