#include <stdint.h>
#include <stdbool.h>
#include <iso646.h>
#include <avr/io.h>
#include "Digital_output.h"
#include "GlobalVar.h"

#define SET_BIT(Var,Bit) ( Var = Var |  (1 << (Bit)) )
#define RST_BIT(Var,Bit) ( Var = Var & ~(1 << (Bit)) )

#define INIT_LED() (DDRB|=(1<<5))
#define LED_ON() (PORTB|=(1<<5))
#define LED_OFF() (PORTB&=~(1<<5))

extern struct GlobalVar GV;

void Digital_output_init(void)
{
  INIT_LED();
  return;
}

void Digital_output_cyclic(void)
{
  if (GV.Do0)
  {
    LED_ON();
  }
  else
  {
    LED_OFF();
  }
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
