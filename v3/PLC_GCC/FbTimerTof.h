//TOF - Таймер с задержкой на выключение.
//        DbTimerTof
//    +----------------+
//    |   FbTimerTof   |
// ->-|In           Out|->-
//   -|TimeDelayOff    |
//   -|Ts_ms           |
//    +----------------+
/*
  Пример вызова программы. Выполнять код каждые Ts_ms = 100 мс.
  static struct DbTimerTof DbTimerTof1 = {0};
  DbTimerTof1.In           = true           ; //Вход таймера.
  DbTimerTof1.TimeDelayOff = 5000           ; //Время задержки выключения [мс].
  DbTimerTof1.Ts_ms        = 100            ; //Шаг дискретизации по времени [мс].
  FbTimerTof(&DbTimerTof1)                  ; //TOF - Таймер с задержкой на выключение.
  //                       = DbTimerTof1.Out; //Выход таймера.
*/

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

struct DbTimerTof
{
  //Входные переменные, сохраняемые.
  bool     In           ; //Вход таймера.
  uint32_t TimeDelayOff ; //Время задержки выключения [мс].
  uint32_t Ts_ms        ; //Шаг дискретизации по времени [мс].
  //Выходные переменные, сохраняемые.
  bool Out              ; //Выход таймера.
  //Внутренние переменные, сохраняемые.
  uint32_t Timer1       ; //Текущее время таймер1 [мс].
};

void FbTimerTof(struct DbTimerTof *p);

#ifdef __cplusplus
}
#endif
