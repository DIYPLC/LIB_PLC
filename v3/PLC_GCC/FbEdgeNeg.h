//Детектор ниспадающего фронта (среза).
//       DbEdgeNeg
//     +-----------+
//     | FbEdgeNeg |
//  ->-|In      Out|->-
//     +-----------+
/*
  Пример вызова программы.
  static struct DbEdgeNeg DbEdgeNeg1 = {0};
  DbEdgeNeg1.In = false         ; //Вход.
  FbEdgeNeg(&DbEdgeNeg1)        ; //Детектор ниспадающего фронта (среза).
  //            = DbEdgeNeg1.Out; //Выход.
*/

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

struct DbEdgeNeg
{
  //Входные переменные, сохраняемые.
  bool In        ; //Вход.
  //Выходные переменные, сохраняемые.
  bool Out       ; //Выход.
  //Внутренние переменные, сохраняемые.
  bool In_previos; //Предыдущее состояние входа.
};

void FbEdgeNeg(struct DbEdgeNeg *p);

#ifdef __cplusplus
}
#endif
