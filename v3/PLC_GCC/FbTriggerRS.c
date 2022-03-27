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
