//Фильтр NaN и Inf для чисел REAL.
//      DbFilterNaN
//    +-------------+
//    | FbFilterNaN |
// ->-|In        Out|->-
//    |        Alarm|-
//    +-------------+
/*
  Пример вызова программы.
  static struct DbFilterNaN DbFilterNaN1 = {0};
  DbFilterNaN1.In = 0.0               ; //Вход.
  FbFilterNaN(&DbFilterNaN1)          ; //Фильтр NaN и Inf для чисел REAL.
  //              = DbFilterNaN1.Out  ; //Выход.
  //              = DbFilterNaN1.Alarm; //Флаг ошибки.
*/

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

struct DbFilterNaN
{
  //Входные переменные, сохраняемые.
  float In   ; //Вход.
  //Выходные переменные, сохраняемые.
  float Out  ; //Выход.
  bool  Alarm; //Флаг ошибки.
};

void FbFilterNaN(struct DbFilterNaN *p);

#ifdef __cplusplus
}
#endif
