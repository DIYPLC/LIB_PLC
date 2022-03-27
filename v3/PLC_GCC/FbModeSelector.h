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
/*
  Пример вызова программы.
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
*/

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

struct DbModeSelector
{
  //Входные переменные, сохраняемые.
  bool ButtonStop  ; //Кнопка "Стоп".
  bool ButtonManual; //Кнопка "Ручной режим".
  bool ButtonAuto  ; //Кнопка "Автоматический режим".
  bool Error       ; //Отсутствие готовности системы к работе.
  bool Reset       ; //Сброс при перезагрузке.
  //Выходные переменные, сохраняемые.
  bool LampStop    ; //Флаг "Активен режим СТОП".
  bool LampManual  ; //Флаг "Активен РУЧНОЙ режим".
  bool LampAuto    ; //Флаг "Активен АВТОМАТИЧЕСКИЙ режим.
  //Внутренние переменные, сохраняемые.
  uint8_t State1   ; //Локальный граф состояний.
};

void FbModeSelector(struct DbModeSelector *p);

#ifdef __cplusplus
}
#endif
