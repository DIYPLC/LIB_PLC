// Блок задержки сигнала на 100 тактов.
//      DbDelayN
//    +----------+
//    | FbDelayN |
// ->-|In     Out|->-
//    +----------+
/*
  Пример вызова программы.
  static struct DbDelayN DbDelayN1 = {0};
  DbDelayN1.In = 0.0          ; //Вход.
  FbDelayN(&DbDelayN1)        ; // Блок задержки сигнала на 100 тактов.
  //           = DbDelayN1.Out; //Выход.
*/

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

struct DbDelayN
{
  //Входные переменные, сохраняемые.
  float    In        ; //Вход.
  //Выходные переменные, сохраняемые.
  float    Out       ; //Выход.
  //Внутренние переменные, сохраняемые.
  float    Buffer[98+1]; //Буфер задержки сигнала
};

void FbDelayN(struct DbDelayN *p);

#ifdef __cplusplus
}
#endif
