#include <stdint.h>
#include <stdbool.h>
#include <iso646.h>
#include "FbScale.h"

#define In     p->In
#define InMax  p->InMax
#define InMin  p->InMin
#define OutMax p->OutMax
#define OutMin p->OutMin
#define Out    p->Out

void FbScale(struct DbScale *p)
{

  // Масштабирование сигнала.
  if (InMax == InMin) // Деление на 0 может остановить процессор.
  {
    // При ошибке исходных данных.
    Out = 0.0;
  }
  else
  {
    // Масштабирование.
    Out = (OutMax - OutMin) * ((In - InMin) / (InMax - InMin)) + OutMin;
  }

  return;
}

// Статическая характеристика.
//
//       ^ Out
//       |
// OutMax|<---------------*
//       |              * |
//       |            *   |
//    Out|<---------*     |
//       |        * |     |
//       |      *   |     |
// OutMin|<---*     |     |
//       |    |     |     |
//       |    |     |     |
//       +---------------------> In
//          InMin  In   InMax

// Выход сигнал
// Out = k * In + b
//
// Для расчета k, b надо решить систему двух линейных уравнений с двумя неизвестными.
// {OutMax = k * InMax + b
// {OutMin = k * InMin + b
//
// Усиление:
//      OutMax - OutMin
// k = -----------------
//       InMax - InMin
//
// Смещение:
// b = OutMax - k * InMax
//
// После подстановки в уравнение Out = k * In + b констант k, b,
// и сокращения числа арифметических операций до минимума получаем:
// Out := (OutMax - OutMin) * ((In - InMin)/(InMax - InMin)) + OutMin;

// Данное линейное преобразование на практике легко вывести через промежуточный диаппазон 0...1:
// InMin...InMax -> 0...(InMax-InMin) -> 0...1 -> 0...(OutMax-OutMin) -> OutMin...OutMax.
// Пример рассчета давления с датчика  4...20мА -> 0...10Бар.
// 4...20 -  4 = 0...16
// 0...16 / 16 = 0...1
// 0...1  * 10 = 0...10
// При токе 12мА
// 12  -   4 = 8
// 8   /  16 = 0.5
// 0.5 *  10 = 5Бар
// Давление 5Бар.

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
