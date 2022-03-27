//ПИД- регулятор давления.
//Система стабилизации давления жидкости.
//Поддерживаем постоянное давление после насоса с частотных приводом.
//Нет: технологических блокировок, группового пуска, перхода на резервный насос, защиты от скачков напряжения.
//                           Db1PIRCA1
//          +-----------------------------------------+
//          |                Fb1PIRCA1                |
//    Ai ->-|AiSensorPressure         AoDriveFrequency|->- Ao
//    Di ->-|DiDriveReady                 DoDriveStart|->- Do
//          |                                         |
// MW[0] ->-|HmiSetpoint            HmiProcessVariable|->- MW[3]
// MW[1] ->-|HmiControlSignalManual   HmiControlSignal|->- MW[4]
//          |                                         |
// MW[2] ->-|HmiControlWord              HmiStatusWord|->- MW[5]
//          |                             HmiErrorWord|->- MW[6]
//          |                                         |
//    GV ->-|PLC_Ts                                   |
//    GV ->-|PLC_Reset                                |
//          +-----------------------------------------+
/*
  Пример вызова программы. Выполнять код каждые Ts = 0.1 с.
  static struct Db1PIRCA1 Db_1PIRCA1 = {0};
  //Db_1PIRCA1.AiSensorPressure        = GV.Ai0                       ; //Датчик давления сигнал с аналогово входа PLC 0...1000 (0...10[Бар]).
  //Db_1PIRCA1.DiDriveReady            = GV.Di1                       ; //Нет ошибок привода сигнал с дискретного входа PLC.
  //Db_1PIRCA1.HmiSetpoint             = GV.MW[0]                     ; //Заданное значение давления 0...1000 (0...10[Бар]) от HMI.
  //Db_1PIRCA1.HmiControlSignalManual  = GV.MW[1]                     ; //Сигнал управления в ручном режиме работы 0...5000 (0...50[Гц]) от HMI.
  //Db_1PIRCA1.HmiControlWord          = GV.MW[2]                     ; //Слово управления передается от HMI.
  //Db_1PIRCA1.PLC_Ts                  = GV.Ts                      ; //Шаг дискретизации по времени [мс].
  //Db_1PIRCA1.PLC_Reset               = GV.Reset                     ; //Сброс при перезагрузке.
  Db_1PIRCA1.AiSensorPressure        = Db_1PIRCA1.DriveFrequency    ; //DEBUG!!!
  Db_1PIRCA1.DiDriveReady            = true                         ; //DEBUG!!!
  Db_1PIRCA1.Setpoint                = 500                          ; //DEBUG!!!
  Db_1PIRCA1.FrequencyManual         = 4000                         ; //DEBUG!!!
  Db_1PIRCA1.ControlWord             = 4                            ; //DEBUG!!!
  Db_1PIRCA1.PLC_Ts_ms               = 100                          ; //DEBUG!!!
  Db_1PIRCA1.PLC_Reset               = false                        ; //DEBUG!!!
  Fb1PIRCA1(&Db_1PIRCA1)                                            ; //ПИД- регулятор давления.
  //GV.Ao0                           = Db_1PIRCA1.AoDriveFrequency  ; //Сигнал управления скорости привода 0...5000 (0...50[Гц]) на аналоговый выход PLC.
  //GV.Do0                           = Db_1PIRCA1.DoDriveStart      ; //Пуск частотного привода на дискретный выход PLC.
  //GV.MW[3]                         = Db_1PIRCA1.HmiProcessVariable; //Измеренное значение регулируемого параметра. 0...1000 (0...10[Бар]) на HMI.
  //GV.MW[4]                         = Db_1PIRCA1.HmiControlSignal  ; //Сигнал управления скорости привода 0...5000 (0...50[Гц]) на HMI.
  //GV.MW[5]                         = Db_1PIRCA1.HmiStatusWord     ; //Слово состояния на HMI.
  //GV.MW[6]                         = Db_1PIRCA1.HmiErrorWord      ; //Слово ошибок на HMI.
*/

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

struct Db1PIRCA1
{
  //Входные переменные, сохраняемые.
  uint16_t AiSensorPressure      ; //Датчик давления сигнал с аналогово входа PLC 0...1000 (0...10[Бар]).
  bool     DiDriveReady          ; //Нет ошибок привода сигнал с дискретного входа PLC.
  uint16_t HmiSetpoint           ; //Заданное значение давления 0...1000 (0...10[Бар]) от HMI.
  uint16_t HmiControlSignalManual; //Сигнал управления в ручном режиме работы 0...5000 (0...50[Гц]) от HMI.
  uint16_t HmiControlWord        ; //Слово управления передается от HMI.
  float    PLC_Ts                ; //Шаг дискретизации по времени [мс].
  bool     PLC_Reset             ; //Сброс при перезагрузке.
  //Выходные переменные, сохраняемые.
  uint16_t AoDriveFrequency      ; //Сигнал управления скорости привода 0...5000 (0...50[Гц]) на аналоговый выход PLC.
  bool     DoDriveStart          ; //Пуск частотного привода на дискретный выход PLC.
  uint16_t HmiProcessVariable    ; //Измеренное значение регулируемого параметра. 0...1000 (0...10[Бар]) на HMI.
  uint16_t HmiControlSignal      ; //Сигнал управления скорости привода 0...5000 (0...50[Гц]) на HMI.
  uint16_t HmiStatusWord         ; //Слово состояния на HMI.
  uint16_t HmiErrorWord          ; //Слово ошибок на HMI.
};

void Fb1PIRCA1(struct Db1PIRCA1 *p);

#ifdef __cplusplus
}
#endif
