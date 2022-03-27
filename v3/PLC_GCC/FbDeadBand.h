//Зона нечувствительности.
//      DbDeadBand
//    +------------+
//    | FbDeadBand |
// ->-|In       Out|->-
//   -|DBmax       |
//   -|DBmin       |
//    +------------+
/*
  Пример вызова программы.
  static struct DbDeadBand DbDeadBand1 = {0};
  DbDeadBand1.In    =  0.0  ; //Вход зоны нечувствительности.
  DbDeadBand1.DBmax =  0.001; //dead band - Зона нечувствительности верхняя граница.
  DbDeadBand1.DBmin = -0.001; //dead band - Зона нечувствительности нижняя граница.
  FbDeadBand(&DbDeadBand1)  ; //Зона нечувствительности.
  //       = DbDeadBand1.Out; //Выход зоны нечувствительности.
*/

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

struct DbDeadBand
{
  //Входные переменные, сохраняемые.
  float In   ; //Вход зоны нечувствительности.
  float DBmax; //dead band - Зона нечувствительности верхняя граница.
  float DBmin; //dead band - Зона нечувствительности нижняя граница.
  //Выходные переменные, сохраняемые.
  float Out  ; //Выход зоны нечувствительности.
};

void FbDeadBand(struct DbDeadBand *p);

#ifdef __cplusplus
}
#endif
