#include <stdint.h>
#include <stdbool.h>
#include <iso646.h>
#include "FbTriggerRS.h"

#define S p->S
#define R p->R
#define Q p->Q

void FbTriggerRS(struct DbTriggerRS *p)
{

  //RS- Триггер.
  Q = (Q or S) and (not(R));

  return;
}

//   Релейная интерпритация.
//  |                       |
//  |   R       S       Q   |
//  +--|/|--+--| |--+--( )--+
//  |       |       |       |
//  |       |   Q   |       |
//  |       +--| |--+       |
//  |                       |

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
