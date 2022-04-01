#include <stdint.h>         //uint8_t...uint64_t int8_t...int64_t
#include <stdbool.h>        //bool true false
#include <iso646.h>         //and or not
#include "FcTaskCyclic2.h"   //Задача вызывается циклически.
#include "GlobalVar.h"      //Глобальные переменные.
//LibPlc
#include "FbGSS.h"          //Генератор сигналов и псевдослучайных чисел.
#include "FbModeSelector.h" //Переключатель режимов работы.
#include "FbWordToBits.h"   //Преобразование слова в 16 бит.
#include "FbBitsToWord.h"   //Преобразование 16 бит в слово.
#include "FbTimerTof.h"     //Таймер TOF.
#include "FbTimerTon.h"     //Таймер TON.
#include "FbPIDcontrol.h"   //Регулятор ПИД.
#include "FbFilterA.h"      //Апериодическое звено первого порядка.
#include "FbLimit.h"        //Амплитудный ограничитель.
#include "FbRamp.h"         //Рампа разгона торможения.
#include "FbScale.h"        //Линейное преобразование.
#include "Fb2PosControl.h"  //Регулятор двухпозиционный.
#include "Fb3PosControl.h"  //Регулятор трехпозиционный.
#include "FbCounter.h"      //Счетчик импульсов.
#include "FbDeadBand.h"     //Зона нечувствительности.
#include "FbDelayN.h"       //Задержка на N тактов.
#include "FbDeriveF.h"      //Производная с фильтрацией.
#include "FbEdgeNeg.h"      //Детектор ниспадающего фронта.
#include "FbEdgePos.h"      //Детектор нарастающего фронта.
#include "FbFilterNaN.h"    //Фильтр NaN и Inf для чисел REAL.
#include "FbIntegrator.h"   //Интегратор W(s)=1/s.
#include "FbSoftPWM.h"      //ШИМ генератор двухканальный.
#include "FbTriggerRS.h"    //Триггер RS.

extern struct GlobalVar GV;

void FcTaskCyclic2(void)
{

  //Генератор сигналов и псевдослучайных чисел.
  //             DbGSS
  //    +---------------------+
  //    |        FbGSS        |
  //   -|Amplitude        Sine|->-
  //   -|Period         Cosine|->-
  //   -|Phase      RectangleR|->-
  //   -|Offset       ctangleB|->-
  //   -|PulseTime    Triangle|->-
  //   -|Ts               Prnd|->-
  //    +---------------------+
  static struct DbGSS DbGSS1 = {0};
  DbGSS1.Amplitude = 1.0              ; //Амплитуда выходного сигнала.
  DbGSS1.Period    = 1.0              ; //Период выходного сигнала [с].
  DbGSS1.Phase     = 0.0              ; //Фаза выходного сигнала [рад].
  DbGSS1.Offset    = 0.0              ; //Постоянная составляющая выходного сигнала.
  DbGSS1.PulseTime = 0.5              ; //Время импульса [с].
  DbGSS1.Ts        = GV.Ts            ; //Шаг дискретизации по времени [с].
  FbGSS(&DbGSS1)                      ;
  //               = DbGSS1.Sine      ; //Синусоидальный сигнал.
  //               = DbGSS1.Cosine    ; //Косинусоидальный сигнал.
  GV.tmp_floats[0] = DbGSS1.RectangleR; //Прямоугольный сигнал вещественный.
  GV.Do0           = DbGSS1.RectangleB; //Прямоугольный сигнал булевый.
  //               = DbGSS1.Triangle  ; //Треугольный, линейно нарастающий и убывающий сигнал.
  //               = DbGSS1.Prnd      ; //Псевдослучайные числа в диапазоне 0...1.

  GV.tmp_floats[1] = GV.Ts;

  //ПИД-регулятор.
  //         DbPIDcontrol
  //    +--------------------+
  //    |    FbPIDcontrol    |
  // ->-|ProcessVariable  Out|->-
  //   -|Setpoint            |
  //   -|Kp                  |
  //   -|Ki                  |
  //   -|Kd                  |
  //   -|Kdf                 |
  //   -|DBmax               |
  //   -|DBmin               |
  //   -|OutMax              |
  //   -|OutMin              |
  //   -|Ts                  |
  //   -|Manual              |
  //   -|ManOn               |
  //    +--------------------+
  static struct DbPIDcontrol DbPIDcontrol1 = {0};
  DbPIDcontrol1.ProcessVariable = 0.0              ; //Измеренное значение регулируемого параметра.
  DbPIDcontrol1.Setpoint        = 0.0              ; //Заданное значение регулируемого параметра.
  DbPIDcontrol1.Kp              = 0.001            ; //Коэффициент усиления пропорциональный.
  DbPIDcontrol1.Ki              = 0.001            ; //Коэффициент усиления интегральный.
  DbPIDcontrol1.Kd              = 0.0              ; //Коэффициент усиления дифференциальный.
  DbPIDcontrol1.Kdf             = 1.0              ; //Коэффициент фильтрации дифференциальный Kdf=1/Tdf.
  DbPIDcontrol1.DBmax           =  0.001           ; //Зона нечувствительности к ошибке регулирования, максимум.
  DbPIDcontrol1.DBmin           = -0.001           ; //Зона нечувствительности к ошибке регулирования, минимум.
  DbPIDcontrol1.OutMax          = 100.0            ; //Максимальное значение сигнала управления.
  DbPIDcontrol1.OutMin          = 0.0              ; //Минимальное значение сигнала управления.
  DbPIDcontrol1.Ts              = 0.1              ; //Шаг дискретизации по времени в секундах.
  DbPIDcontrol1.Manual          = 25.0             ; //Сигнал управления в ручном режиме работы.
  DbPIDcontrol1.ManOn           = false            ; //Включить ручной режим работы регулятора.
  FbPIDcontrol(&DbPIDcontrol1)                     ; //ПИД-регулятор.
  //                            = DbPIDcontrol1.Out; //Сигнал управления на исполнительный механизм.

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
  static struct DbScale DbScale1 = {0};
  DbScale1.In     = 0.0         ; //Вход до масштабирования.
  DbScale1.InMax  = 20.0        ; //Максимум входного диапазона.
  DbScale1.InMin  = 4.0         ; //Минимум входного диапазона.
  DbScale1.OutMax = 100.0       ; //Максимум выходного диапазона.
  DbScale1.OutMin = 0.0         ; //Минимум выходного диапазона.
  FbScale(&DbScale1)            ; //Масштабирование InMin...InMax -> OutMin...OutMax.
  //              = DbScale1.Out; //Выход после масштабирования.

  //Регулятор двухпозиционный.
  //       Db2PosControl
  //     +---------------+
  //     | Fb2PosControl |
  //  ->-|PV           OP|->-
  //    -|SP             |
  //    -|HYST           |
  //     +---------------+
  static struct Db2PosControl Db2PosControl1 = {0};
  Db2PosControl1.PV   = 0.0               ; //Измеренное значение регулируемого параметра.
  Db2PosControl1.SP   = 0.0               ; //Заданное значение регулируемого параметра.
  Db2PosControl1.HYST = 5.0               ; //Гистерезис > 0.
  Fb2PosControl(&Db2PosControl1)          ; //Регулятор двухпозиционный.
  //                   = Db2PosControl1.OP; //Выход управляющего сигнала.

  //Регулятор трехпозиционный.
  //       Db3PosControl
  //     +---------------+
  //     | Fb3PosControl |
  //  ->-|PV        OpPos|->-
  //    -|SP        OpNeg|->-
  //    -|DBand          |
  //    -|HystPos        |
  //    -|HystNeg        |
  //     +---------------+
  static struct Db3PosControl Db3PosControl1 = {0};
  Db3PosControl1.PV      = 0.0                  ; //Измеренное значение регулируемого параметра.
  Db3PosControl1.SP      = 0.0                  ; //Заданное значение регулируемого параметра.
  Db3PosControl1.DBand   = 2.0                  ; //Зона нечувствительности > 0.
  Db3PosControl1.HystPos = 1.0                  ; //Гистерезис > 0.
  Db3PosControl1.HystNeg = 1.0                  ; //Гистерезис > 0.
  Fb3PosControl(&Db3PosControl1)                ; //Регулятор трехпозиционный.
  //                     = Db3PosControl1.OpPos ; //Выход управляющего сигнала положительный.
  //                     = Db3PosControl1.OpNeg ; //Выход управляющего сигнала отрицательный.

  //Преобразование 16 бит в слово.
  //      DbBitsToWord
  //    +--------------+
  //    | FbBitsToWord |
  // ->-|In0        Out|->-
  // ->-|In1           |
  // ->-|In2           |
  // ->-|In3           |
  // ->-|In4           |
  // ->-|In5           |
  // ->-|In6           |
  // ->-|In7           |
  // ->-|In8           |
  // ->-|In9           |
  // ->-|In10          |
  // ->-|In11          |
  // ->-|In12          |
  // ->-|In13          |
  // ->-|In14          |
  // ->-|In15          |
  //    +--------------+
  static struct DbBitsToWord DbBitsToWord1 = {0};
  DbBitsToWord1.In0  = false            ; //Входной сигнал бит0.
  DbBitsToWord1.In1  = false            ; //Входной сигнал бит1.
  DbBitsToWord1.In2  = false            ; //Входной сигнал бит2.
  DbBitsToWord1.In3  = false            ; //Входной сигнал бит3.
  DbBitsToWord1.In4  = false            ; //Входной сигнал бит4.
  DbBitsToWord1.In5  = false            ; //Входной сигнал бит5.
  DbBitsToWord1.In6  = false            ; //Входной сигнал бит6.
  DbBitsToWord1.In7  = false            ; //Входной сигнал бит7.
  DbBitsToWord1.In8  = false            ; //Входной сигнал бит8.
  DbBitsToWord1.In9  = false            ; //Входной сигнал бит9.
  DbBitsToWord1.In10 = false            ; //Входной сигнал бит10.
  DbBitsToWord1.In11 = false            ; //Входной сигнал бит11.
  DbBitsToWord1.In12 = false            ; //Входной сигнал бит12.
  DbBitsToWord1.In13 = false            ; //Входной сигнал бит13.
  DbBitsToWord1.In14 = false            ; //Входной сигнал бит14.
  DbBitsToWord1.In15 = false            ; //Входной сигнал бит15.
  FbBitsToWord(&DbBitsToWord1)          ; //Преобразование 16 бит в слово.
  //                 = DbBitsToWord1.Out; //Выходной сигнал.

  //Преобразование слова в 16 бит.
  //      DbWordToBits
  //    +--------------+
  //    | FbWordToBits |
  // ->-|In        Out0|->-
  //    |          Out1|->-
  //    |          Out2|->-
  //    |          Out3|->-
  //    |          Out4|->-
  //    |          Out5|->-
  //    |          Out6|->-
  //    |          Out7|->-
  //    |          Out8|->-
  //    |          Out9|->-
  //    |         Out10|->-
  //    |         Out11|->-
  //    |         Out12|->-
  //    |         Out13|->-
  //    |         Out14|->-
  //    |         Out15|->-
  //    +--------------+
  static struct DbWordToBits DbWordToBits1 = {0};
  DbWordToBits1.In = 0                  ; //Входной сигнал.
  FbWordToBits(&DbWordToBits1)          ; //Преобразование слова в 16 бит.
  //               = DbWordToBits1.Out0 ; //Выходной сигнал бит0.
  //               = DbWordToBits1.Out1 ; //Выходной сигнал бит1.
  //               = DbWordToBits1.Out2 ; //Выходной сигнал бит2.
  //               = DbWordToBits1.Out3 ; //Выходной сигнал бит3.
  //               = DbWordToBits1.Out4 ; //Выходной сигнал бит4.
  //               = DbWordToBits1.Out5 ; //Выходной сигнал бит5.
  //               = DbWordToBits1.Out6 ; //Выходной сигнал бит6.
  //               = DbWordToBits1.Out7 ; //Выходной сигнал бит7.
  //               = DbWordToBits1.Out8 ; //Выходной сигнал бит8.
  //               = DbWordToBits1.Out9 ; //Выходной сигнал бит9.
  //               = DbWordToBits1.Out10; //Выходной сигнал бит10.
  //               = DbWordToBits1.Out11; //Выходной сигнал бит11.
  //               = DbWordToBits1.Out12; //Выходной сигнал бит12.
  //               = DbWordToBits1.Out13; //Выходной сигнал бит13.
  //               = DbWordToBits1.Out14; //Выходной сигнал бит14.
  //               = DbWordToBits1.Out15; //Выходной сигнал бит15.

  //Счетчик импульсов.
  //         DbCounter
  //    +-----------------+
  //    |    FbCounter    |
  // ->-|Inc           Cnt|->-
  //   -|Dec           Ovf|-
  //   -|Reset            |
  //   -|SetValue         |
  //   -|Value            |
  //    +-----------------+
  static struct DbCounter DbCounter1 = {0};
  DbCounter1.Inc      = false         ; //Вход импульсов +1.
  DbCounter1.Dec      = false         ; //Вход импульсов -1.
  DbCounter1.Reset    = false         ; //Сбросить счетчик на 0.
  DbCounter1.SetValue = false         ; //Установить на выходе значение VALUE.
  DbCounter1.Value    = 0             ; //Предустановленное значение счета.
  FbCounter(&DbCounter1)              ; //Счетчик импульсов.
  //                  = DbCounter1.Cnt; //Выход счетчика.
  //                  = DbCounter1.Ovf; //Флаг переполнения счетчика.


  //Зона нечувствительности.
  //      DbDeadBand
  //    +------------+
  //    | FbDeadBand |
  // ->-|In       Out|->-
  //   -|DBmax       |
  //   -|DBmin       |
  //    +------------+
  static struct DbDeadBand DbDeadBand1 = {0};
  DbDeadBand1.In    =  0.0  ; //Вход зоны нечувствительности.
  DbDeadBand1.DBmax =  0.001; //dead band - Зона нечувствительности верхняя граница.
  DbDeadBand1.DBmin = -0.001; //dead band - Зона нечувствительности нижняя граница.
  FbDeadBand(&DbDeadBand1)  ; //Зона нечувствительности.
  //       = DbDeadBand1.Out; //Выход зоны нечувствительности.

  //Производная с фильтром.
  //      DbDeriveF
  //    +-----------+
  //    | FbDeriveF |
  // ->-|In      Out|->-
  //   -|Kdf        |
  //   -|Ts         |
  //    +-----------+
  static struct DbDeriveF DbDeriveF1 = {0};
  DbDeriveF1.In    = 0.0           ; //Входной сигнал.
  DbDeriveF1.Kdf   = 1.0           ; //Коэффициент фильтрации дифференциальный Kdf=1/Tdf.
  DbDeriveF1.Ts    = 0.1           ; //Шаг дискретизации по времени [с].
  FbDeriveF(&DbDeriveF1)           ; //Производная с фильтром.
  //               = DbDeriveF1.Out; //Выходной сигнал.

  //Детектор ниспадающего фронта (среза).
  //       DbEdgeNeg
  //     +-----------+
  //     | FbEdgeNeg |
  //  ->-|In      Out|->-
  //     +-----------+
  static struct DbEdgeNeg DbEdgeNeg1 = {0};
  DbEdgeNeg1.In = false         ; //Вход.
  FbEdgeNeg(&DbEdgeNeg1)        ; //Детектор ниспадающего фронта (среза).
  //            = DbEdgeNeg1.Out; //Выход.

  //Детектор нарастающего фронта.
  //       DbEdgePos
  //     +-----------+
  //     | FbEdgePos |
  //  ->-|In      Out|->-
  //     +-----------+
  static struct DbEdgePos DbEdgePos1 = {0};
  DbEdgePos1.In = false         ; //Вход.
  FbEdgePos(&DbEdgePos1)        ; //Детектор нарастающего фронта.
  //            = DbEdgePos1.Out; //Выход.

  //Фильтр апериодический.
  //      DbFilterA
  //    +-----------+
  //    | FbFilterA |
  // ->-|In      Out|->-
  //   -|Tf         |
  //   -|Ts         |
  //    +-----------+
  static struct DbFilterA DbFilterA1 = {0};
  DbFilterA1.In = 0.0           ; //Входной сигнал до фильтрации.
  DbFilterA1.Tf = 1.0           ; //Постоянная времени фильтра [с].
  DbFilterA1.Ts = 0.1           ; //Шаг дискретизации по времени [с].
  FbFilterA(&DbFilterA1)        ; //Фильтр апериодический.
  //            = DbFilterA1.Out; //Выходной сигнал после фильтрации.

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
  static struct DbIntegrator DbIntegrator1 = {0};
  DbIntegrator1.In        = 0.0              ; //Входной сигнал интегратора.
  DbIntegrator1.OutMax    = 1000000.0        ; //Максимальное значение выхода.
  DbIntegrator1.OutMin    = -1000000.0       ; //Минимальное значение выхода.
  DbIntegrator1.InitValue = 0.0              ; //Начальные условия интегрирования для Reset
  DbIntegrator1.Ts        = 0.1              ; //Шаг дискретизации по времени [с].
  DbIntegrator1.Reset     = false            ; //Сброс при перезагрузке.
  FbIntegrator(&DbIntegrator1)               ; //Интегратор W(s)=1/s.
  //                      = DbIntegrator1.Out; //Выходной сигнал интегратора.

  //Амплитудный ограничитель.
  //       DbLimit
  //    +-----------+
  //    |  FbLimit  |
  // ->-|In      Out|->-
  //   -|OutMax     |
  //   -|OutMin     |
  //    +-----------+
  static struct DbLimit DbLimit1 = {0};
  DbLimit1.In     = 0.0         ; //Вход амплитудного ограничителя.
  DbLimit1.OutMax = 100.0       ; //Максимальное значение выхода.
  DbLimit1.OutMin = 0.0         ; //Минимальное значение выхода.
  FbLimit(&DbLimit1)            ; //Амплитудный ограничитель.
  //              = DbLimit1.Out; //Выход амплитудного ограничителя.

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
  DbModeSelector1.ButtonStop   = false                     ; //Кнопка "Стоп".
  DbModeSelector1.ButtonManual = false                     ; //Кнопка "Ручной режим".
  DbModeSelector1.ButtonAuto   = false                     ; //Кнопка "Автоматический режим".
  DbModeSelector1.Error        = false                     ; //Отсутствие готовности системы к работе.
  DbModeSelector1.Reset        = false                     ; //Сброс при перезагрузке.
  FbModeSelector(&DbModeSelector1)                         ; //Переключатель режимов работы.
  //                           = DbModeSelector1.LampStop  ; //Флаг "Активен режим СТОП".
  //                           = DbModeSelector1.LampManual; //Флаг "Активен РУЧНОЙ режим".
  //                           = DbModeSelector1.LampAuto  ; //Флаг "Активен АВТОМАТИЧЕСКИЙ режим.

  //Рампа разгона / торможения.
  //        DbRamp
  //    +------------+
  //    |   FbRamp   |
  // ->-|In       Out|->-
  //   -|TAcc        |
  //   -|TDec        |
  //   -|Ts          |
  //    +------------+
  static struct DbRamp DbRamp1 = {0};
  DbRamp1.In   = 0.0        ; //Входной сигнал.
  DbRamp1.TAcc = 1.0        ; //Время разгона на единицу [с].
  DbRamp1.TDec = 1.0        ; //Время торможения на единицу [c].
  DbRamp1.Ts   = 0.1        ; //Шаг дискретизации по времени [с].
  FbRamp(&DbRamp1)          ; //Рампа разгона / торможения.
  //           = DbRamp1.Out; //Выходной сигнал.

  //ШИМ генератор двухканальный.
  //            DbSoftPWM
  //     +---------------------+
  //     |      FbSoftPWM      |
  //  ->-|DutyCucle      PWMPOS|->-
  //    -|PeriodPositive PWMNEG|->-
  //    -|PeriodNegative       |
  //    -|DBMAX                |
  //    -|DBMIN                |
  //    -|Ts                   |
  //     +---------------------+
  static struct DbSoftPWM DbSoftPWM1 = {0};
  DbSoftPWM1.DutyCucle      = 50.0             ; //Коэффициент заполнения -100...0...100 [%].
  DbSoftPWM1.PeriodPositive = 10.0             ; //Период ШИМ для положительного коэффициента заполнения [с].
  DbSoftPWM1.PeriodNegative = 10.0             ; //Период ШИМ для отрицательного коэффициента заполнения [с].
  DbSoftPWM1.DBMAX          = 0.001            ; //dead band - Зона нечувствительности, верхняя граница [%].
  DbSoftPWM1.DBMIN          = -0.001           ; //dead band - Зона нечувствительности, нижняя граница [%].
  DbSoftPWM1.Ts             = 0.1              ; //Шаг дискретизации по времени [с].
  FbSoftPWM(&DbSoftPWM1)                       ; //ШИМ генератор двухканальный.

  //                        = DbSoftPWM1.PWMPOS; //Выход ШИМ для положительных значений входа.
  //                        = DbSoftPWM1.PWMNEG; //Выход ШИМ для отрицательных значений входа.
  //RS- Триггер с приоритетом на сброс.
  //       DbTriggerRS
  //     +-------------+
  //     | FbTriggerRS |
  //  ->-|S           Q|->-
  //  ->-|R            |
  //     +-------------+
  static struct DbTriggerRS DbTriggerRS1 = {0};
  DbTriggerRS1.S = false         ; //Set — установить единицу.
  DbTriggerRS1.R = false         ; //Reset — сбросить на ноль.
  FbTriggerRS(&DbTriggerRS1)     ; //RS- Триггер с приоритетом на сброс.
  //             = DbTriggerRS1.Q; //Выход триггера.

  //Фильтр NaN и Inf для чисел REAL.
  //      DbFilterNaN
  //    +-------------+
  //    | FbFilterNaN |
  // ->-|In        Out|->-
  //    |        Alarm|-
  //    +-------------+
  static struct DbFilterNaN DbFilterNaN1 = {0};
  DbFilterNaN1.In = 0.0               ; //Вход.
  FbFilterNaN(&DbFilterNaN1)          ; //Фильтр NaN и Inf для чисел REAL.
  //              = DbFilterNaN1.Out  ; //Выход.
  //              = DbFilterNaN1.Alarm; //Флаг ошибки.

  // Блок задержки сигнала на 100 тактов.
  //      DbDelayN
  //    +----------+
  //    | FbDelayN |
  // ->-|In     Out|->-
  //    +----------+
  static struct DbDelayN DbDelayN1 = {0};
  DbDelayN1.In = 0.0          ; //Вход.
  FbDelayN(&DbDelayN1)        ; // Блок задержки сигнала на 100 тактов.
  //           = DbDelayN1.Out; //Выход.

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
