//Детектор нарастающего фронта.
//       DbEdgePos
//     +-----------+
//     | FbEdgePos |
//  ->-|In      Out|->-
//     +-----------+
/*
  Пример вызова программы.
  static struct DbEdgePos DbEdgePos1 = {0};
  DbEdgePos1.In = false         ; //Вход.
  FbEdgePos(&DbEdgePos1)        ; //Детектор нарастающего фронта.
  //            = DbEdgePos1.Out; //Выход.
*/

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

struct DbEdgePos
{
  //Входные переменные, сохраняемые.
  bool In        ; //Вход.
  //Выходные переменные, сохраняемые.
  bool Out       ; //Выход.
  //Внутренние переменные, сохраняемые.
  bool In_previos; //Предыдущее состояние входа.
};

void FbEdgePos(struct DbEdgePos *p);

#ifdef __cplusplus
}
#endif
