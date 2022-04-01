#include <stdint.h>
#include <stdbool.h>
#include <iso646.h>
#include "FbFilterNaN.h"

#define In    p->In
#define Out   p->Out
#define Alarm p->Alarm

void FbFilterNaN(struct DbFilterNaN *p)
{
  union
  {
    float    float32;
    uint32_t uint32;
    uint16_t uint16[2];
    uint8_t  uint8[4];
  } Convertor;
  Convertor.float32 = In;

  if ( 0x7F800000 == (Convertor.uint32 & 0x7F800000) )
  {
    Out   = 0.0;
    Alarm = true;
  }
  else
  {
    Out   = In;
    Alarm = false;
  }

  return;
}

//Если In==(NaN или Inf или -Inf) то Out=0 иначе Out=In.
// hex 7F800000 = bin 01111111_10000000_00000000_00000000
//Стандарт IEEE 754.

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
