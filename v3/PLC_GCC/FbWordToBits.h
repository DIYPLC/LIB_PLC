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
/*
  Пример вызова программы.
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
*/

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

struct DbWordToBits
{
  //Входные переменные, сохраняемые.
  uint16_t In   ; //Входной сигнал.
  //Выходные переменные, сохраняемые.
  bool     Out0 ; //Выходной сигнал бит0.
  bool     Out1 ; //Выходной сигнал бит1.
  bool     Out2 ; //Выходной сигнал бит2.
  bool     Out3 ; //Выходной сигнал бит3.
  bool     Out4 ; //Выходной сигнал бит4.
  bool     Out5 ; //Выходной сигнал бит5.
  bool     Out6 ; //Выходной сигнал бит6.
  bool     Out7 ; //Выходной сигнал бит7.
  bool     Out8 ; //Выходной сигнал бит8.
  bool     Out9 ; //Выходной сигнал бит9.
  bool     Out10; //Выходной сигнал бит10.
  bool     Out11; //Выходной сигнал бит11.
  bool     Out12; //Выходной сигнал бит12.
  bool     Out13; //Выходной сигнал бит13.
  bool     Out14; //Выходной сигнал бит14.
  bool     Out15; //Выходной сигнал бит15.
};

void FbWordToBits(struct DbWordToBits *p);

#ifdef __cplusplus
}
#endif
