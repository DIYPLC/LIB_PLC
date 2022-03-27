#include <stdint.h>        //uint8_t...uint64_t int8_t...int64_t
#include <stdbool.h>       //bool true false
#include <iso646.h>        //and or not
#include "FcTaskCyclic1.h" //Задача вызывается циклически.
#include "GlobalVar.h"     //Глобальные переменные.
#include "Fb1PIRCA1.h"     //ПИД - регулятор давления.

extern struct GlobalVar GV;

void FcTaskCyclic1(void)
{
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
  //    GV ->-|PLC_Ts_ms                                |
  //    GV ->-|PLC_Reset                                |
  //          +-----------------------------------------+
  GV.MW[0] = 500; //P = 5 Bar
  GV.MW[1] = 4000; //F = 40 Hz
  GV.MW[2] = 0b100; //AUTO MODE
  GV.Di1 = true;
  static struct Db1PIRCA1 Db_1PIRCA1 = {0};
  Db_1PIRCA1.AiSensorPressure       = Db_1PIRCA1.AoDriveFrequency  ; //Датчик давления сигнал с аналогово входа PLC 0...1000 (0...10[Бар]).
  Db_1PIRCA1.DiDriveReady           = GV.Di1                       ; //Нет ошибок привода сигнал с дискретного входа PLC.
  Db_1PIRCA1.HmiSetpoint            = GV.MW[0]                     ; //Заданное значение давления 0...1000 (0...10[Бар]) от HMI.
  Db_1PIRCA1.HmiControlSignalManual = GV.MW[1]                     ; //Сигнал управления в ручном режиме работы 0...5000 (0...50[Гц]) от HMI.
  Db_1PIRCA1.HmiControlWord         = GV.MW[2]                     ; //Слово управления передается от HMI.
  Db_1PIRCA1.PLC_Ts                 = GV.Ts;                       ; //Шаг дискретизации по времени [мс].
  Db_1PIRCA1.PLC_Reset              = GV.Reset                     ; //Сброс при перезагрузке.
  Fb1PIRCA1(&Db_1PIRCA1)                                           ; //ПИД- регулятор давления.
  GV.Ao0                            = Db_1PIRCA1.AoDriveFrequency  ; //Сигнал управления скорости привода 0...5000 (0...50[Гц]) на аналоговый выход PLC.
  GV.Do0                            = Db_1PIRCA1.DoDriveStart      ; //Пуск частотного привода на дискретный выход PLC.
  GV.MW[3]                          = Db_1PIRCA1.HmiProcessVariable; //Измеренное значение регулируемого параметра. 0...1000 (0...10[Бар]) на HMI.
  GV.MW[4]                          = Db_1PIRCA1.HmiControlSignal  ; //Сигнал управления скорости привода 0...5000 (0...50[Гц]) на HMI.
  GV.MW[5]                          = Db_1PIRCA1.HmiStatusWord     ; //Слово состояния на HMI.
  GV.MW[6]                          = Db_1PIRCA1.HmiErrorWord      ; //Слово ошибок на HMI.

  GV.tmp_floats[0] = (float)Db_1PIRCA1.HmiSetpoint;
  GV.tmp_floats[1] = (float)Db_1PIRCA1.HmiProcessVariable;

  return;
}
