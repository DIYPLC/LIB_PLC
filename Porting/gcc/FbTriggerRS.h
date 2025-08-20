// RS- Триггер с приоритетом на сброс.
//       DbTriggerRS
//     +-------------+
//     | FbTriggerRS |
//  ->-|S           Q|->-
//  ->-|R            |
//     +-------------+
/*
  Пример вызова программы.
  static struct DbTriggerRS DbTriggerRS1 = {0};
  DbTriggerRS1.S = false         ; // Set — установить единицу.
  DbTriggerRS1.R = false         ; // Reset — сбросить на ноль.
  FbTriggerRS(&DbTriggerRS1)     ; // RS- Триггер с приоритетом на сброс.
  //             = DbTriggerRS1.Q; // Выход триггера.
*/

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

struct DbTriggerRS
{
  // Входные переменные, сохраняемые.
  bool S; // Set — установить единицу.
  bool R; // Reset — сбросить на ноль.
  // Выходные переменные, сохраняемые.
  bool Q; // Выход триггера.
};

void FbTriggerRS(struct DbTriggerRS *p);

#ifdef __cplusplus
}
#endif

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
