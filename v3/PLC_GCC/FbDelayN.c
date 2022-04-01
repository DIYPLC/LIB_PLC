#include <stdint.h>
#include <stdbool.h>
#include <iso646.h>
#include "FbDelayN.h"

#define In     p->In
#define Out    p->Out
#define Buffer p->Buffer

void FbDelayN(struct DbDelayN *p)
{
  //W(Z)=Z^(-100)
  Out = Buffer[98];
  for (uint8_t i = 98; i >= 1; i = i - 1) //i с 98 до 1 с шагом -1
  {
    Buffer[i] = Buffer[i - 1]; //Buffer[0]...Buffer[98]
  }
  Buffer[0] = In;

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
