#include <stdint.h>
#include <stdbool.h>
#include <iso646.h>
#include "FbEdgePos.h"

#define In         p->In
#define Out        p->Out
#define In_previos p->In_previos

void FbEdgePos(struct DbEdgePos *p)
{

  //Детектор нарастающего фронта.
  Out = In and not(In_previos);
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
