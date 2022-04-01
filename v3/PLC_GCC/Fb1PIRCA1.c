#include <stdint.h>         //uint8_t...uint64_t int8_t...int64_t
#include <stdbool.h>        //bool true false
#include <iso646.h>         //and or not
#include "Fb1PIRCA1.h"      //ПИД- регулятор давления.
//PLC:
#include "GlobalVar.h"      //Глобальные переменные.
//LibPlc:
#include "FbModeSelector.h" //Переключатель режимов работы.
#include "FbWordToBits.h"   //Преобразование слова в 16 бит.
#include "FbBitsToWord.h"   //Преобразование 16 бит в слово.
#include "FbPIDcontrol.h"   //Регулятор ПИД.
#include "FbFilterA.h"      //Апериодическое звено первого порядка.
#include "FbLimit.h"        //Амплитудный ограничитель.
#include "FbRamp.h"         //Рампа разгона торможения.
#include "FbScale.h"        //Линейное преобразование.
#include "FbFilterNaN.h"    //Фильтр NaN и Inf для чисел REAL.

#define AiSensorPressure       p->AiSensorPressure
#define DiDriveReady           p->DiDriveReady
#define HmiSetpoint            p->HmiSetpoint
#define HmiControlSignalManual p->HmiControlSignalManual
#define HmiControlWord         p->HmiControlWord
#define PLC_Ts                 p->PLC_Ts
#define PLC_Reset              p->PLC_Reset
#define AoDriveFrequency       p->AoDriveFrequency
#define DoDriveStart           p->DoDriveStart
#define HmiProcessVariable     p->HmiProcessVariable
#define HmiControlSignal       p->HmiControlSignal
#define HmiStatusWord          p->HmiStatusWord
#define HmiErrorWord           p->HmiErrorWord

void Fb1PIRCA1(struct Db1PIRCA1 *p)
{
  //Внутренние переменные, не сохраняемые.
  float Ts; //Шаг дискретизации по времени [с].
  float ProcessVariable    ; //
  float Setpoint           ; //
  float ControlSignal      ; //
  float ControlSignalManual; //
  bool  HmiButtonStop  ; //
  bool  HmiButtonManual; //
  bool  HmiButtonAuto  ; //
  bool  HmiModeStop    ; //
  bool  HmiModeManual  ; //
  bool  HmiModeAuto    ; //
  bool  ErrorProcessVariableLo; //
  bool  ErrorProcessVariableHi; //
  bool  ErrorControlSignalLo  ; //
  bool  ErrorControlSignalHi  ; //
  bool  ErrorDrive            ; //

  //Раскладываем слово управления от HMI на 16 бит.
  //                    DbWordToBits
  //                  +--------------+
  //                  | FbWordToBits |
  // HmiControlWord->-|In        Out0|->-HmiButtonStop
  //                  |          Out1|->-HmiButtonManual
  //                  |          Out2|->-HmiButtonAuto
  //                  |          Out3|->-
  //                  |          Out4|->-
  //                  |          Out5|->-
  //                  |          Out6|->-
  //                  |          Out7|->-
  //                  |          Out8|->-
  //                  |          Out9|->-
  //                  |         Out10|->-
  //                  |         Out11|->-
  //                  |         Out12|->-
  //                  |         Out13|->-
  //                  |         Out14|->-
  //                  |         Out15|->-
  //                  +--------------+
  static struct DbWordToBits DbWordToBits_CW = {0};
  DbWordToBits_CW.In = HmiControlWord       ; //Входной сигнал.
  FbWordToBits(&DbWordToBits_CW)            ; //Преобразование слова в 16 бит.
  HmiButtonStop      = DbWordToBits_CW.Out0 ; //Выходной сигнал бит0.
  HmiButtonManual    = DbWordToBits_CW.Out1 ; //Выходной сигнал бит1.
  HmiButtonAuto      = DbWordToBits_CW.Out2 ; //Выходной сигнал бит2.
  //                 = DbWordToBits_CW.Out3 ; //Выходной сигнал бит3.
  //                 = DbWordToBits_CW.Out4 ; //Выходной сигнал бит4.
  //                 = DbWordToBits_CW.Out5 ; //Выходной сигнал бит5.
  //                 = DbWordToBits_CW.Out6 ; //Выходной сигнал бит6.
  //                 = DbWordToBits_CW.Out7 ; //Выходной сигнал бит7.
  //                 = DbWordToBits_CW.Out8 ; //Выходной сигнал бит8.
  //                 = DbWordToBits_CW.Out9 ; //Выходной сигнал бит9.
  //                 = DbWordToBits_CW.Out10; //Выходной сигнал бит10.
  //                 = DbWordToBits_CW.Out11; //Выходной сигнал бит11.
  //                 = DbWordToBits_CW.Out12; //Выходной сигнал бит12.
  //                 = DbWordToBits_CW.Out13; //Выходной сигнал бит13.
  //                 = DbWordToBits_CW.Out14; //Выходной сигнал бит14.
  //                 = DbWordToBits_CW.Out15; //Выходной сигнал бит15.

  //Если есть неисправность датчика то не смотря на это можно работать в ручном режиме.
  //В автоматическом режиме с ошибками работать нельзя.
  //Переключатель режимов работы.
  //          DbModeSelector
  //    +------------------------+
  //    |     FbModeSelector     |
  // ->-|ButtonStop      LampStop|->-
  // ->-|ButtonManual  LampManual|->-
  // ->-|ButtonAuto      LampAuto|->-
  //   -|Error                   |
  //   -|Reset                   |
  //    +------------------------+
  static struct DbModeSelector DbModeSelector1 = {0};
  DbModeSelector1.ButtonStop   = HmiButtonStop             ; //Кнопка "Стоп".
  DbModeSelector1.ButtonManual = HmiButtonManual           ; //Кнопка "Ручной режим".
  DbModeSelector1.ButtonAuto   = HmiButtonAuto             ; //Кнопка "Автоматический режим".
  DbModeSelector1.Error        = not(DiDriveReady)         ; //Отсутствие готовности системы к работе.
  DbModeSelector1.Reset        = PLC_Reset                 ; //Сброс при перезагрузке.
  FbModeSelector(&DbModeSelector1)                         ; //Переключатель режимов работы.
  HmiModeStop                  = DbModeSelector1.LampStop  ; //Флаг "Активен режим СТОП".
  HmiModeManual                = DbModeSelector1.LampManual; //Флаг "Активен РУЧНОЙ режим".
  HmiModeAuto                  = DbModeSelector1.LampAuto  ; //Флаг "Активен АВТОМАТИЧЕСКИЙ режим.

  //Включение привода.
  DoDriveStart = DiDriveReady and (HmiModeAuto or HmiModeAuto) and not(HmiModeStop);

  //Масштабирование аналогово входа 0...1000 в давление 0...10Бар.
  //       DbScale
  //    +-----------+
  //    |  FbScale  |
  // ->-|In      Out|->-
  //   -|InMax      |
  //   -|InMin      |
  //   -|OutMax     |
  //   -|OutMin     |
  //    +-----------+
  static struct DbScale DbScalePV = {0};
  DbScalePV.In     = (float)AiSensorPressure; //Вход до масштабирования.
  DbScalePV.InMax  = 1000.0                 ; //Максимум входного диапазона.
  DbScalePV.InMin  = 0.0                    ; //Минимум входного диапазона.
  DbScalePV.OutMax = 10.0                   ; //Максимум выходного диапазона.
  DbScalePV.OutMin = 0.0                    ; //Минимум выходного диапазона.
  FbScale(&DbScalePV)                       ; //Масштабирование InMin...InMax -> OutMin...OutMax.
  //               = DbScalePV.Out          ; //Выход после масштабирования.

  //Фильтр апериодический.
  //      DbFilterA
  //    +-----------+
  //    | FbFilterA |
  // ->-|In      Out|->-
  //   -|Tf         |
  //   -|Ts         |
  //    +-----------+
  static struct DbFilterA DbFilterA_PV = {0};
  DbFilterA_PV.In = DbScalePV.Out   ; //Входной сигнал до фильтрации.
  DbFilterA_PV.Tf = 0.1             ; //Постоянная времени фильтра [с].
  DbFilterA_PV.Ts = PLC_Ts          ; //Шаг дискретизации по времени [с].
  FbFilterA(&DbFilterA_PV)          ; //Фильтр апериодический.
  //              = DbFilterA_PV.Out; //Выходной сигнал после фильтрации.

  //Амплитудный ограничитель 0...10[Бар].
  //       DbLimit
  //    +-----------+
  //    |  FbLimit  |
  // ->-|In      Out|->-
  //   -|OutMax     |
  //   -|OutMin     |
  //    +-----------+
  static struct DbLimit DbLimit_PV = {0};
  DbLimit_PV.In     = DbFilterA_PV.Out; //Вход амплитудного ограничителя.
  DbLimit_PV.OutMax = 10.0            ; //Максимальное значение выхода.
  DbLimit_PV.OutMin = 0.0             ; //Минимальное значение выхода.
  FbLimit(&DbLimit_PV)                ; //Амплитудный ограничитель.
  ProcessVariable   = DbLimit_PV.Out  ; //Выход амплитудного ограничителя.

  //Индикация в HMI 0...1000 (0...10[Бар]).
  HmiProcessVariable = (uint16_t)(ProcessVariable * 100.0);

  //Ограничение заданного значения давления 0...10[Бар].
  //       DbLimit
  //    +-----------+
  //    |  FbLimit  |
  // ->-|In      Out|->-
  //   -|OutMax     |
  //   -|OutMin     |
  //    +-----------+
  static struct DbLimit DbLimit_SP = {0};
  DbLimit_SP.In     = ((float)HmiSetpoint) / 100.0; //Вход амплитудного ограничителя.
  DbLimit_SP.OutMax = 10.0                        ; //Максимальное значение выхода.
  DbLimit_SP.OutMin = 0.0                         ; //Минимальное значение выхода.
  FbLimit(&DbLimit_SP)                            ; //Амплитудный ограничитель.
  Setpoint           = DbLimit_SP.Out             ; //Выход амплитудного ограничителя.

  //Управление в ручном режиме от HMI 0...5000 (0...50[Гц])
  ControlSignalManual = ((float)HmiControlSignalManual) * 100.0;

  //Стабилизация давления жидкости 0...10[Бар] -> 0...50[Гц].
  //                          DbPIDcontrol
  //                     +--------------------+
  //                     |    FbPIDcontrol    |
  //   ProcessVariable->-|ProcessVariable  Out|->-ControlSignal
  //            Setpoint-|Setpoint            |
  //                    -|Kp                  |
  //                    -|Ki                  |
  //                    -|Kd                  |
  //                    -|Kdf                 |
  //                    -|DBmax               |
  //                    -|DBmin               |
  //                    -|OutMax              |
  //                    -|OutMin              |
  //                    -|Ts                  |
  // ControlSignalManual-|Manual              |
  //                    -|ManOn               |
  //                     +--------------------+
  static struct DbPIDcontrol DbPIDcontrol1 = {0};
  DbPIDcontrol1.ProcessVariable = ProcessVariable    ; //Измеренное значение регулируемого параметра.
  DbPIDcontrol1.Setpoint        = Setpoint           ; //Заданное значение регулируемого параметра.
  DbPIDcontrol1.Kp              = 0.5               ; //Коэффициент усиления пропорциональный.
  DbPIDcontrol1.Ki              = 2.0               ; //Коэффициент усиления интегральный.
  DbPIDcontrol1.Kd              = 0.0                ; //Коэффициент усиления дифференциальный.
  DbPIDcontrol1.Kdf             = 1.0                ; //Коэффициент фильтрации дифференциальный Kdf=1/Tdf.
  DbPIDcontrol1.DBmax           = 0.0001             ; //Зона нечувствительности к ошибке регулирования, максимум.
  DbPIDcontrol1.DBmin           = -0.0001            ; //Зона нечувствительности к ошибке регулирования, минимум.
  DbPIDcontrol1.OutMax          = 50.0               ; //Максимальное значение сигнала управления.
  DbPIDcontrol1.OutMin          = 0.0                ; //Минимальное значение сигнала управления.
  DbPIDcontrol1.Ts              = PLC_Ts             ; //Шаг дискретизации по времени в секундах.
  DbPIDcontrol1.Manual          = ControlSignalManual; //Сигнал управления в ручном режиме работы.
  DbPIDcontrol1.ManOn           = not(HmiModeAuto)   ; //Включить ручной режим работы регулятора.
  FbPIDcontrol(&DbPIDcontrol1)                       ; //ПИД-регулятор.
  //                            = DbPIDcontrol1.Out  ; //Сигнал управления на исполнительный механизм.

  //Ограничение величины ускорения / замедления привода 0...50[Гц].
  //        DbRamp
  //    +------------+
  //    |   FbRamp   |
  // ->-|In       Out|->-
  //   -|TAcc        |
  //   -|TDec        |
  //   -|Ts          |
  //    +------------+
  static struct DbRamp DbRamp1 = {0};
  DbRamp1.In    = DbPIDcontrol1.Out; //Входной сигнал.
  DbRamp1.TAcc  = 0.1              ; //Время разгона на единицу [с].
  DbRamp1.TDec  = 0.1              ; //Время торможения на единицу [c].
  DbRamp1.Ts    = PLC_Ts           ; //Шаг дискретизации по времени [с].
  FbRamp(&DbRamp1)                 ; //Рампа разгона / торможения.
  ControlSignal = DbRamp1.Out      ; //Выходной сигнал.

  //Скорость на частотный привод 0...5000 (0...50[Гц])
  AoDriveFrequency = (uint16_t)(ControlSignal * 100.0);

  //Индикация в HMI 0...5000 (0...50[Гц])
  HmiControlSignal = (uint16_t)(ControlSignal * 100.0);

  //Сборка слова состояния SW из 16 бит для передачи в HMI.
  //Слово состояния SW влияет на отображение кнопок в HMI.
  //                   DbBitsToWord
  //                 +--------------+
  //                 | FbBitsToWord |
  //   HmiModeStop->-|In0        Out|->-StatusWord
  // HmiModeManual->-|In1           |
  //   HmiModeAuto->-|In2           |
  //              ->-|In3           |
  //              ->-|In4           |
  //              ->-|In5           |
  //              ->-|In6           |
  //              ->-|In7           |
  //              ->-|In8           |
  //              ->-|In9           |
  //              ->-|In10          |
  //              ->-|In11          |
  //              ->-|In12          |
  //              ->-|In13          |
  //              ->-|In14          |
  //              ->-|In15          |
  //                 +--------------+
  static struct DbBitsToWord DbBitsToWord_SW = {0};
  DbBitsToWord_SW.In0  = HmiModeStop        ; //Входной сигнал бит0.
  DbBitsToWord_SW.In1  = HmiModeManual      ; //Входной сигнал бит1.
  DbBitsToWord_SW.In2  = HmiModeAuto        ; //Входной сигнал бит2.
  DbBitsToWord_SW.In3  = false              ; //Входной сигнал бит3.
  DbBitsToWord_SW.In4  = false              ; //Входной сигнал бит4.
  DbBitsToWord_SW.In5  = false              ; //Входной сигнал бит5.
  DbBitsToWord_SW.In6  = false              ; //Входной сигнал бит6.
  DbBitsToWord_SW.In7  = false              ; //Входной сигнал бит7.
  DbBitsToWord_SW.In8  = false              ; //Входной сигнал бит8.
  DbBitsToWord_SW.In9  = false              ; //Входной сигнал бит9.
  DbBitsToWord_SW.In10 = false              ; //Входной сигнал бит10.
  DbBitsToWord_SW.In11 = false              ; //Входной сигнал бит11.
  DbBitsToWord_SW.In12 = false              ; //Входной сигнал бит12.
  DbBitsToWord_SW.In13 = false              ; //Входной сигнал бит13.
  DbBitsToWord_SW.In14 = false              ; //Входной сигнал бит14.
  DbBitsToWord_SW.In14 = false              ; //Входной сигнал бит14.
  DbBitsToWord_SW.In15 = false              ; //Входной сигнал бит15.
  FbBitsToWord(&DbBitsToWord_SW)            ; //Преобразование 16 бит в слово.
  HmiStatusWord        = DbBitsToWord_SW.Out; //Выходной сигнал.

  //Ошибки.
  ErrorProcessVariableLo = HmiProcessVariable <= 1.0 ; //Минимум  1  [Бар]
  ErrorProcessVariableHi = HmiProcessVariable >= 9.0 ; //Максимум 9  [Бар]
  ErrorControlSignalLo   = HmiControlSignal   <= 5.0 ; //Минимум  5  [Гц]
  ErrorControlSignalHi   = HmiControlSignal   >= 49.0; //Минимум  49 [Гц]
  ErrorDrive             = not(DiDriveReady);

  //Сборка слова активных ошибок и аварий EW из 16 бит, для передачи в HMI.
  //Слово активных ошибок и аварий EW используется для предупреждения оператора.
  //                            DbBitsToWord
  //                          +--------------+
  //                          | FbBitsToWord |
  // ErrorProcessVariableLo->-|In0        Out|->-ErrorWord
  // ErrorProcessVariableHi->-|In1           |
  //   ErrorControlSignalLo->-|In2           |
  //   ErrorControlSignalHi->-|In3           |
  //             ErrorDrive->-|In4           |
  //                       ->-|In5           |
  //                       ->-|In6           |
  //                       ->-|In7           |
  //                       ->-|In8           |
  //                       ->-|In9           |
  //                       ->-|In10          |
  //                       ->-|In11          |
  //                       ->-|In12          |
  //                       ->-|In13          |
  //                       ->-|In14          |
  //                       ->-|In15          |
  //                          +--------------+
  static struct DbBitsToWord DbBitsToWord_EW = {0};
  DbBitsToWord_EW.In0  = ErrorProcessVariableLo; //Входной сигнал бит0.
  DbBitsToWord_EW.In1  = ErrorProcessVariableHi; //Входной сигнал бит1.
  DbBitsToWord_EW.In2  = ErrorControlSignalLo  ; //Входной сигнал бит2.
  DbBitsToWord_EW.In3  = ErrorControlSignalHi  ; //Входной сигнал бит3.
  DbBitsToWord_EW.In4  = ErrorDrive            ; //Входной сигнал бит4.
  DbBitsToWord_EW.In5  = false                 ; //Входной сигнал бит5.
  DbBitsToWord_EW.In6  = false                 ; //Входной сигнал бит6.
  DbBitsToWord_EW.In7  = false                 ; //Входной сигнал бит7.
  DbBitsToWord_EW.In8  = false                 ; //Входной сигнал бит8.
  DbBitsToWord_EW.In9  = false                 ; //Входной сигнал бит9.
  DbBitsToWord_EW.In10 = false                 ; //Входной сигнал бит10.
  DbBitsToWord_EW.In11 = false                 ; //Входной сигнал бит11.
  DbBitsToWord_EW.In12 = false                 ; //Входной сигнал бит12.
  DbBitsToWord_EW.In13 = false                 ; //Входной сигнал бит13.
  DbBitsToWord_EW.In14 = false                 ; //Входной сигнал бит14.
  DbBitsToWord_EW.In14 = false                 ; //Входной сигнал бит14.
  DbBitsToWord_EW.In15 = false                 ; //Входной сигнал бит15.
  FbBitsToWord(&DbBitsToWord_EW)               ; //Преобразование 16 бит в слово.
  HmiErrorWord         = DbBitsToWord_EW.Out   ; //Выходной сигнал.

  return;
}

//  +---------+
//  | GNU GPL |
//  +---------+
//  |
//  |
//  .= .-_-. =.
// ((_/)o o(\_))
//  `-'(. .)`-'
//  |/| \_/ |\
//  ( |     | )
//  /"\_____/"\
//  \__)   (__/
// @COPYLEFT ALL WRONGS RESERVED :)
// Author: VA
// Contacts: DIY.PLC.314@gmail.com
// License: GNU GPL v2
