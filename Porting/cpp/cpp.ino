// Example use LIB_PLC generator and scope.
// Arduino style.
// Arduino Nano ATmega328p 16MHz 5VDC

#include "FbTs.hpp"
#include "FbGSS.hpp"

static FbTs DbTs;
static FbGSS DbGSS;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);

  DbTs.Reset = true;
  DbTs.millis = millis();
  DbTs();
}

void loop() {
  DbTs.Reset = false;
  DbTs.millis = millis();
  DbTs();

  DbGSS.Period = 1.0;          // Период выходного сигнала [с].
  DbGSS.PulseTime = 0.5;       // Время импульса [с].
  DbGSS.Ts = DbTs.Ts;          // Шаг дискретизации по времени [с].
  DbGSS();                     // Генератор сигналов и псевдослучайных чисел.

  Serial.print(DbGSS.Sine);
  Serial.print(',');
  Serial.print(DbGSS.Cosine);
  Serial.print(',');
  Serial.print(DbTs.Ts_ms);
  Serial.println();

  if (DbGSS.RectangleB) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}

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
