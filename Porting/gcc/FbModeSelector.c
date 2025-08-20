#include <stdint.h>
#include <stdbool.h>
#include <iso646.h>
#include "FbModeSelector.h"

#define ButtonStop   p->ButtonStop
#define ButtonManual p->ButtonManual
#define ButtonAuto   p->ButtonAuto
#define Error        p->Error
#define Reset        p->Reset
#define LampStop     p->LampStop
#define LampManual   p->LampManual
#define LampAuto     p->LampAuto
#define State1       p->State1

enum STATES // Номера состояний.
{
  STATE_STOP   = 0, // Состояние "СТОП РЕЖИМ".
  STATE_MANUAL = 1, // Состояние "РУЧНОЙ РЕЖИМ".
  STATE_AUTO   = 2  // Состояние "АВТОМАТИЧЕСКИЙ РЕЖИМ".
};

void FbModeSelector(struct DbModeSelector *p)
{

  // Временные переменные, не сохраняемые.
  bool StateTaboo; // Флаг запрещенного состояния входов.

  // Запрещенное состояние: нажата может быть только одна кнопка.
  StateTaboo =
    ((ButtonStop and ButtonManual and ButtonAuto) or
     (not(ButtonStop) and ButtonManual and ButtonAuto) or
     (ButtonStop and not(ButtonManual) and ButtonAuto) or
     (ButtonStop and ButtonManual and not(ButtonAuto)) );

  // При перезагрузке контроллера режим СТОП.
  if (Reset or StateTaboo)
  {
    State1     = STATE_STOP;
    LampStop   = true ;
    LampManual = false;
    LampAuto   = false;
  }
  else
  {
    switch (State1)
    {

      case STATE_STOP: // Режим СТОП.
        LampStop   = true ;
        LampManual = false;
        LampAuto   = false;
        // Переход СТОП -> РУЧНОЙ.
        if (ButtonManual)
        {
          State1     = STATE_MANUAL;
          LampStop   = false;
          LampManual = true ;
          LampAuto   = false;
        }
        // Переход СТОП -> АВТОМАТ.
        if (ButtonAuto and not(Error))
        {
          State1     = STATE_AUTO;
          LampStop   = false;
          LampManual = false;
          LampAuto   = true ;
        }
        break;

      case STATE_MANUAL: // Режим РУЧНОЙ.
        LampStop   = false;
        LampManual = true ;
        LampAuto   = false;
        // Переход РУЧНОЙ -> СТОП.
        if (ButtonStop)
        {
          State1     = 0;
          LampStop   = true ;
          LampManual = false;
          LampAuto   = false;
        }
        // Преход РУЧНОЙ -> АВТОМАТ.
        if (ButtonAuto and not(Error))
        {
          State1     = STATE_AUTO;
          LampStop   = false;
          LampManual = false;
          LampAuto   = true ;
        }
        break;

      case STATE_AUTO: // Режим АВТОМАТ.
        LampStop   = false;
        LampManual = false;
        LampAuto   = true ;
        // Переход АВТОМАТ -> СТОП.
        if (ButtonStop or Error)
        {
          State1     = STATE_STOP;
          LampStop   = true ;
          LampManual = false;
          LampAuto   = false;
        }
        // Переход АВТОМАТ -> РУЧНОЙ.
        if (ButtonManual)
        {
          State1     = STATE_MANUAL;
          LampStop   = false;
          LampManual = true ;
          LampAuto   = false;
        }
        break;

      default: // СТОП при неопределенном состоянии.
        State1 = STATE_STOP;
        break;
    }
  }

  return;
}

// Граф сосотояний.
//
// Если ошибка Error активна можно работать только в ручном режиме.
// Reset должен срабатывать при перезагрузке или включении питания.
//
//                                  |
//                                 -+-Reset OR StateTaboo
//                                  |
//                                  V
//                        +-------------------+
//                        | State1 =          |
//            +---------->| STATE_STOP        |-----------+
//            |           | LampStop = 1      |           |
//            |           +-------------------+           |
//            |                |         ^                |
//            |                |         |                |
//            |   ButtonManual-+-       -+-ButtonStop     |
//            |                |         |                |
//            |                V         |                |
//            |           +-------------------+           |
// ButtonStop |           | State1 =          |           | ButtonAuto
//        OR -+-          | STATE_MANUAL      |          -+- AND
//      Error |           | LampManual = 1    |           | NOT(Error)
//            |           +-------------------+           |
//            |                |         ^                |
//            |     ButtonAuto |         |                |
//            |           AND -+-       -+-ButtonManual   |
//            |     NOT(Error) |         |                |
//            |                V         |                |
//            |           +-------------------+           |
//            |           | State1 =          |           |
//            +-----------| STATE_AUTO        |<----------+
//                        | LampAuto = 1      |
//                        +-------------------+

// Пример организации интерфейса пользователя для HMI.
// При нажатии кнопоки AUTO тег ButtonAuto = 1.
// В автоматическом режиме работы тег LampAuto = 1 дает эффект нажатия на кнопку AUTO.
// Кнопки MANUAL, STOP работают аналогично.
// Так как кнопки без фиксации то можно параллельно кнопкам на экране подключать физические кнопки.
//
// +--------------------------------------------------------+
// | MENU: "Errors"                                         |
// +--------------------------------------------------------+
// | 0. No Error (OK).                                      |
// |                                                        |
// |                                                        |
// |                                                        |
// |                                                        |
// |                                                        |
// |                                                        |
// +--------------------------------------------------------+
// | +--------+ +--------+ +--------+ +--------+ +--------+ |
// | | < MENU | |  AUTO  | | MANUAL | |  STOP  | | MENU > | |
// | +--------+ +--------+ +--------+ +--------+ +--------+ |
// +--------------------------------------------------------+

// @COPYLEFT ALL WRONGS RESERVED :)
// Author: VA
// Contacts: DIY.PLC.314@gmail.com
// Date start LIB_PLC: 2014
// License: GNU GPL-2.0-or-later
// https://www.gnu.org/licenses/old-licenses/gpl-2.0.html
// https://www.youtube.com/watch?v=n1F_MfLRlX0
// https://www.youtube.com/@DIY_PLC
// https://github.com/DIYPLC/LIB_PLC
// https://oshwlab.com/diy.plc.314/PLC_HW1_SW1
// https://3dtoday.ru/3d-models/mechanical-parts/body/korpus-na-din-reiku
// https://t.me/DIY_PLC
