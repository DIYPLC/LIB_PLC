//RS- Триггер с приоритетом на сброс.
//       DbTriggerRS
//     +-------------+
//     | FbTriggerRS |
//  ->-|S           Q|->-
//  ->-|R            |
//     +-------------+
/*
  Пример вызова программы.
  static struct DbTriggerRS DbTriggerRS1 = {0};
  DbTriggerRS1.S = false         ; //Set — установить единицу.
  DbTriggerRS1.R = false         ; //Reset — сбросить на ноль.
  FbTriggerRS(&DbTriggerRS1)     ; //RS- Триггер с приоритетом на сброс.
  //             = DbTriggerRS1.Q; //Выход триггера.
*/

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

struct DbTriggerRS
{
  bool S; //Set — установить единицу.
  bool R; //Reset — сбросить на ноль.
  //Выходные переменные, сохраняемые.
  bool Q; //Выход триггера.
};

void FbTriggerRS(struct DbTriggerRS *p);

#ifdef __cplusplus
}
#endif
