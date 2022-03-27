//TON - Таймер с задержкой на включение.
//        DbTimerTon
//    +----------------+
//    |   FbTimerTon   |
// ->-|In           Out|->-
//   -|TimeDelayOn     |
//   -|Ts_ms           |
//    +----------------+
/*
  Пример вызова программы. Выполнять код каждые Ts_ms = 100 мс.
  static struct DbTimerTon DbTimerTon1 = {0};
  DbTimerTon1.In       = true           ; //Вход таймера.
  DbTimerTon1.TimeDela = 5000           ; //Время задержки включения [мс].
  DbTimerTon1.Ts_ms    = 100            ; //Шаг дискретизации по времени [мс].
  FbTimerTon(&DbTimerTon1)              ; //TON - Таймер с задержкой на включение.
  //                   = DbTimerTon1.Out; //Выход таймера.
*/

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

struct DbTimerTon
{
  //Входные переменные, сохраняемые.
  bool     In          ; //Вход таймера.
  uint32_t TimeDelayOn ; //Время задержки включения [мс].
  uint32_t Ts_ms       ; //Шаг дискретизации по времени [мс].
  //Выходные переменные, сохраняемые.
  bool Out             ; //Выход таймера.
  //Внутренние переменные, сохраняемые.
  uint32_t Timer1      ; //Текущее время таймер1 [мс].
};

void FbTimerTon(struct DbTimerTon *p);

#ifdef __cplusplus
}
#endif
