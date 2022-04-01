//Амплитудный ограничитель.
//       DbLimit
//    +-----------+
//    |  FbLimit  |
// ->-|In      Out|->-
//   -|OutMax     |
//   -|OutMin     |
//    +-----------+
/*
  Пример вызова программы.
  static struct DbLimit DbLimit1 = {0};
  DbLimit1.In     = 0.0         ; //Вход амплитудного ограничителя.
  DbLimit1.OutMax = 100.0       ; //Максимальное значение выхода.
  DbLimit1.OutMin = 0.0         ; //Минимальное значение выхода.
  FbLimit(&DbLimit1)            ; //Амплитудный ограничитель.
  //              = DbLimit1.Out; //Выход амплитудного ограничителя.
*/

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

struct DbLimit
{
  //Входные переменные, сохраняемые.
  float In    ; //Вход амплитудного ограничителя.
  float OutMax; //Максимальное значение выхода.
  float OutMin; //Минимальное значение выхода.
  //Выходные переменные, сохраняемые.
  float Out   ; //Выход амплитудного ограничителя.
};

void FbLimit(struct DbLimit *p);

#ifdef __cplusplus
}
#endif
