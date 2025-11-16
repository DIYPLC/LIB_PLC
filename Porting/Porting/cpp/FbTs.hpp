#pragma once

class FbTs {
public:
  // Входные переменные, сохраняемые.
  uint32_t millis = 0;  // millis() Arduino.
  bool Reset = false;   // Сброс при перезагрузке.
  // Выходные переменные, сохраняемые.
  uint32_t Ts_ms = 100;    // Шаг дискретизации по времени [мс].
  float Ts = 0.1;          // Шаг дискретизации по времени [с].
  uint32_t Ts_ms_max = 0;  // Максимальное время скана [мс].
  uint32_t Uptime_s = 0;   // Время в работе [с].
  void operator()();
private:
  // Внутренние переменные, сохраняемые.
  // Внутренние переменные, сохраняемые.
  uint32_t Time_previous_ms = 0;  // Предидущее значение [мс].
  uint64_t Uptime_ms = 0;         // Время в работе [мс].
};

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
