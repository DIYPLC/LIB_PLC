//Регулятор двухпозиционный.
//       Db2PosControl
//     +---------------+
//     | Fb2PosControl |
//  ->-|PV           OP|->-
//    -|SP             |
//    -|HYST           |
//     +---------------+
/*
  Пример вызова программы.
  static struct Db2PosControl Db2PosControl1 = {0};
  Db2PosControl1.PV   = 0.0               ; //Измеренное значение регулируемого параметра.
  Db2PosControl1.SP   = 0.0               ; //Заданное значение регулируемого параметра.
  Db2PosControl1.HYST = 5.0               ; //Гистерезис > 0.
  Fb2PosControl(&Db2PosControl1)          ; //Регулятор двухпозиционный.
  //                   = Db2PosControl1.OP; //Выход управляющего сигнала.
*/

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

struct Db2PosControl
{
  //Входные переменные, сохраняемые.
  float PV  ; //Измеренное значение регулируемого параметра.
  float SP  ; //Заданное значение регулируемого параметра.
  float HYST; //Гистерезис > 0.
  //Выходные переменные, сохраняемые.
  bool OP   ; //Выход управляющего сигнала.
  //Внутренние переменные, сохраняемые.
  float ER  ; //Ошибка регулирования.
};

void Fb2PosControl(struct Db2PosControl *p);

#ifdef __cplusplus
}
#endif
