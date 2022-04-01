#include <stdint.h>
#include <stdbool.h>
#include <iso646.h>
#include "FbWordToBits.h"

#define In    p->In
#define Out0  p->Out0
#define Out1  p->Out1
#define Out2  p->Out2
#define Out3  p->Out3
#define Out4  p->Out4
#define Out5  p->Out5
#define Out6  p->Out6
#define Out7  p->Out7
#define Out8  p->Out8
#define Out9  p->Out9
#define Out10 p->Out10
#define Out11 p->Out11
#define Out12 p->Out12
#define Out13 p->Out13
#define Out14 p->Out14
#define Out15 p->Out15

void FbWordToBits(struct DbWordToBits *p)
{

  //Логическое условие без оператора if.
  Out0  = ((In bitand 0b0000000000000001) != 0);
  Out1  = ((In bitand 0b0000000000000010) != 0);
  Out2  = ((In bitand 0b0000000000000100) != 0);
  Out3  = ((In bitand 0b0000000000001000) != 0);
  Out4  = ((In bitand 0b0000000000010000) != 0);
  Out5  = ((In bitand 0b0000000000100000) != 0);
  Out6  = ((In bitand 0b0000000001000000) != 0);
  Out7  = ((In bitand 0b0000000010000000) != 0);
  Out8  = ((In bitand 0b0000000100000000) != 0);
  Out9  = ((In bitand 0b0000001000000000) != 0);
  Out10 = ((In bitand 0b0000010000000000) != 0);
  Out11 = ((In bitand 0b0000100000000000) != 0);
  Out12 = ((In bitand 0b0001000000000000) != 0);
  Out13 = ((In bitand 0b0010000000000000) != 0);
  Out14 = ((In bitand 0b0100000000000000) != 0);
  Out15 = ((In bitand 0b1000000000000000) != 0);

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
