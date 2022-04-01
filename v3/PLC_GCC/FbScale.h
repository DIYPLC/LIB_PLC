//Масштабирование InMin...InMax -> OutMin...OutMax.
//       DbScale
//    +-----------+
//    |  FbScale  |
// ->-|In      Out|->-
//   -|InMax      |
//   -|InMin      |
//   -|OutMax     |
//   -|OutMin     |
//    +-----------+
/*
  Пример вызова программы.
  static struct DbScale DbScale1 = {0};
  DbScale1.In     = 0.0         ; //Вход до масштабирования.
  DbScale1.InMax  = 20.0        ; //Максимум входного диапазона.
  DbScale1.InMin  = 4.0         ; //Минимум входного диапазона.
  DbScale1.OutMax = 100.0       ; //Максимум выходного диапазона.
  DbScale1.OutMin = 0.0         ; //Минимум выходного диапазона.
  FbScale(&DbScale1)            ; //Масштабирование InMin...InMax -> OutMin...OutMax.
  //              = DbScale1.Out; //Выход после масштабирования.
*/

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

struct DbScale
{
  //Входные переменные, сохраняемые.
  float In    ; //Вход до масштабирования.
  float InMax ; //Максимум входного диапазона.
  float InMin ; //Минимум входного диапазона.
  float OutMax; //Максимум выходного диапазона.
  float OutMin; //Минимум выходного диапазона.
  //Выходные переменные, сохраняемые.
  float Out   ; //Выход после масштабирования.
};

void FbScale(struct DbScale *p);

#ifdef __cplusplus
}
#endif
