#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

// Информация о аппаратной платформе.
#define CPU_ATMEGA168P (0)
#define CPU_ATMEGA32   (0)
#define CPU_ATMEGA328P (1)
#define CPU_ATMEGA128A (0)
#define CPU_ATMEGA2560 (0)
#define CPU_STM32F103C6T6 (0)
#define CPU_STM32F103C8T6 (0)
#define CPU_STM32F401CCU6 (0)
#define CPU_STM32F411CEU6 (0)
#define CPU_STM32F407GVT6 (0)
#define CPU_STM32F407VET6 (0)
#define CPU_ESP8266MOD   (0)
#define CPU_ESP_WROOM_32 (0)
#define CPU_WT32_S1      (0)
#define CPU_Raspberry_Pi     (0)
#define CPU_SOFT_PLC_PYTHON3 (0)
#define FREQUENCY_PROCESSOR_HZ (16*1000*1000)
#define AVR_Studio   (0)
#define Arduino_IDE  (1)
#define STM32CubeIDE (0)
#define MAKEFILE     (0)
#define MODBUS_RTU_SLAVE_EN (1)
#define RTC_DS3231_EN (0)

// Бибилиотека блоков для ПЛК LIB_PLC.
#include "GlobalVar.h"

// Базовые блоки обработки аналоговых сигналов, упорядочил по частоте использования.
#include "FbPIDcontrol.h"       // LIB_PLC Регулятор ПИД.
#include "Fb2PosControl.h"      // LIB_PLC Регулятор двухпозиционный.
#include "Fb3PosControl.h"      // LIB_PLC Регулятор трехпозиционный.
#include "FbScale.h"            // LIB_PLC Линейное преобразование.
#include "FbLimit.h"            // LIB_PLC Амплитудный ограничитель.
#include "FbRamp.h"             // LIB_PLC Рампа разгона торможения.
#include "FbFilterA.h"          // LIB_PLC Апериодическое звено первого порядка.
#include "FbDeriveF.h"          // LIB_PLC Производная с фильтрацией.
#include "FbGSS.h"              // LIB_PLC Генератор сигналов и псевдослучайных чисел.
#include "FbFilterNaN.h"        // LIB_PLC Фильтр NaN и Inf для чисел REAL.
#include "FbSoftPWM.h"          // LIB_PLC ШИМ генератор двухканальный.
#include "FbDelayN.h"           // LIB_PLC Задержка на N тактов.
#include "FbIntegrator.h"       // LIB_PLC Интегратор W(s)=1/s.
#include "FbDeadBand.h"         // LIB_PLC Зона нечувствительности.

// Базовые дискретные блоки, упорядочил по частоте использования.
#include "FbModeSelector.h"     // LIB_PLC Переключатель режимов работы.
#include "FbTriggerRS.h"        // LIB_PLC Триггер RS.
#include "FbEdgeNeg.h"          // LIB_PLC Детектор ниспадающего фронта.
#include "FbEdgePos.h"          // LIB_PLC Детектор нарастающего фронта.
#include "FbTimerTon.h"         // LIB_PLC Таймер TON.
#include "FbTimerTof.h"         // LIB_PLC Таймер TOF.
#include "FbWordToBits.h"       // LIB_PLC Преобразование слова в 16 бит.
#include "FbBitsToWord.h"       // LIB_PLC Преобразование 16 бит в слово.
#include "FbBlink.h"            // LIB_PLC Мигающий светодиод.
#include "FbCounter.h"          // LIB_PLC Счетчик импульсов.

#ifdef __cplusplus
}
#endif

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
