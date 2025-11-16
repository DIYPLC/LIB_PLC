#include <stdint.h>
#include <stdbool.h>
#include <iso646.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "GlobalVar.h" // Глобальные переменные ПЛК.
#include "M328P_HW.h" // Аппаратно зависимые функции ATmega328p 16MHz 5VDC

#define SET_BIT(Var,Bit) ( Var = Var |  (1 << (Bit)) )
#define RST_BIT(Var,Bit) ( Var = Var & ~(1 << (Bit)) )

// Для ADM2486BRVZ
#define INIT_LED() (DDRB  |=  (1 << 5))
#define LED_ON()   (PORTB |=  (1 << 5))
#define LED_OFF()  (PORTB &= ~(1 << 5))

extern struct GlobalVar GV; // Глобальные переменные ПЛК.

// Описание регистров в книге:
// Евстифеев А.В. Микроконтроллеры AVR семейства Mega руководство пользователя

/****************************************************************************************/

void GPIO_INIT(void)
{
  INIT_LED();
  return;
}

/****************************************************************************************/

void TIMER2_INIT(void) // Настраиваем прерывание каждые 1ms
{
  // ATmega328p 16MHz
  // 8bit Timer2
  // HW Timer 1 CTC mode сброс при совпадении
  // 500Hz = 16000000/(2*64*(1+249)) //data sheet
  // 500Hz = 2ms period = 1ms time pulse (time call ISR)
  OCR2A = 249; // Регистр сравнения
  RST_BIT(TCCR2A, WGM20); // Регистр управления CTC mode сброс при совпадении
  SET_BIT(TCCR2A, WGM21); // Регистр управления CTC mode сброс при совпадении
  RST_BIT(TCCR2B, WGM22); // Регистр управления CTC mode сброс при совпадении
  RST_BIT(TCCR2B,  CS20); // Регистр управления Предделитель 64
  RST_BIT(TCCR2B,  CS21); // Регистр управления Предделитель 64
  SET_BIT(TCCR2B,  CS22); // Регистр управления Предделитель 64
  SET_BIT(TIMSK2, OCIE2A); // Маскирование прерываний совпадение А таймера1.
  return;
}

ISR(TIMER2_COMPA_vect) // Циклическое прерывание каждую 1ms
{
  cli(); // Выключить все прерывания.
  GV.millis_ms = GV.millis_ms + 1; // Аналог Arduino millis();
  sei(); // Включить все прерывания.
}

void Program_delay_500ms(void)
{
  // Arduino nano 16MHz
  const uint64_t ARDUINO_NANO_MAGIC_CONST = 101218;
  volatile uint64_t i = 0;
  while (i <= ARDUINO_NANO_MAGIC_CONST)
  {
    i = i + 1;
  }
}

void PLC_Digital_output_cyclic(struct GlobalVar *p)
{
  if (p->Do1)
  {
    LED_ON();
  }
  else
  {
    LED_OFF();
  }
  return;
}

void PLC_Digital_input_cyclic(struct GlobalVar *p)
{
  return;
}

/****************************************************************************************/

// @COPYLEFT ALL WRONGS RESERVED :)
// Author: VA
// Contacts: DIY.PLC.314@gmail.com
// Date start LIB_PLC: 2014
// License: GNU GPL-2.0-or-later
// https://www.gnu.org/licenses/old-licenses/gpl-2.0.html
// https://www.youtube.com/watch?v=n1F_MfLRlX0
// https://www.youtube.com/@DIY_PLC
// https://github.com/DIYPLC/LIB_PLC
// https://oshwlab.com/diy.plc.314/PLC_HW1_SW1
// https://3dtoday.ru/3d-models/mechanical-parts/body/korpus-na-din-reiku
// https://t.me/DIY_PLC
