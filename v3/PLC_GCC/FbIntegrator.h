//Интегратор W(s)=1/s.
//      DbIntegrator
//    +--------------+
//    | FbIntegrator |
// ->-|In         Out|->-
//   -|OutMax        |
//   -|OutMin        |
//   -|InitValue     |
//   -|Ts            |
//   -|Reset         |
//    +--------------+
/*
  Пример вызова программы. Выполнять код каждые Ts = 0.1 с.
  static struct DbIntegrator DbIntegrator1 = {0};
  DbIntegrator1.In        = 0.0              ; //Входной сигнал интегратора.
  DbIntegrator1.OutMax    = 1000000.0        ; //Максимальное значение выхода.
  DbIntegrator1.OutMin    = -1000000.0       ; //Минимальное значение выхода.
  DbIntegrator1.InitValue = 0.0              ; //Начальные условия интегрирования для Reset
  DbIntegrator1.Ts        = 0.1              ; //Шаг дискретизации по времени [с].
  DbIntegrator1.Reset     = false            ; //Сброс при перезагрузке.
  FbIntegrator(&DbIntegrator1)               ; //Интегратор W(s)=1/s.
  //                      = DbIntegrator1.Out; //Выходной сигнал интегратора.
*/

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

struct DbIntegrator
{
  //Входные переменные, сохраняемые.
  float In        ; //Входной сигнал интегратора.
  float OutMax    ; //Максимальное значение выхода.
  float OutMin    ; //Минимальное значение выхода.
  float InitValue ; //Начальные условия интегрирования для Reset
  float Ts        ; //Шаг дискретизации по времени [с].
  bool  Reset     ; //Сброс при перезагрузке.
  //Выходные переменные, сохраняемые.
  float Out       ; //Выходной сигнал интегратора.
  //Внутренние переменные, сохраняемые.
  float InPrevious; //Предидущее значение входа только для трапециидального интегратора.
};

void FbIntegrator(struct DbIntegrator *p);

#ifdef __cplusplus
}
#endif
