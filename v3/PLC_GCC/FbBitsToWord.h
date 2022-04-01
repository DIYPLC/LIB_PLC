//Преобразование 16 бит в слово.
//      DbBitsToWord
//    +--------------+
//    | FbBitsToWord |
// ->-|In0        Out|->-
// ->-|In1           |
// ->-|In2           |
// ->-|In3           |
// ->-|In4           |
// ->-|In5           |
// ->-|In6           |
// ->-|In7           |
// ->-|In8           |
// ->-|In9           |
// ->-|In10          |
// ->-|In11          |
// ->-|In12          |
// ->-|In13          |
// ->-|In14          |
// ->-|In15          |
//    +--------------+
/*
  Пример вызова программы.
  static struct DbBitsToWord DbBitsToWord1 = {0};
  DbBitsToWord1.In0  = false            ; //Входной сигнал бит0.
  DbBitsToWord1.In1  = false            ; //Входной сигнал бит1.
  DbBitsToWord1.In2  = false            ; //Входной сигнал бит2.
  DbBitsToWord1.In3  = false            ; //Входной сигнал бит3.
  DbBitsToWord1.In4  = false            ; //Входной сигнал бит4.
  DbBitsToWord1.In5  = false            ; //Входной сигнал бит5.
  DbBitsToWord1.In6  = false            ; //Входной сигнал бит6.
  DbBitsToWord1.In7  = false            ; //Входной сигнал бит7.
  DbBitsToWord1.In8  = false            ; //Входной сигнал бит8.
  DbBitsToWord1.In9  = false            ; //Входной сигнал бит9.
  DbBitsToWord1.In10 = false            ; //Входной сигнал бит10.
  DbBitsToWord1.In11 = false            ; //Входной сигнал бит11.
  DbBitsToWord1.In12 = false            ; //Входной сигнал бит12.
  DbBitsToWord1.In13 = false            ; //Входной сигнал бит13.
  DbBitsToWord1.In14 = false            ; //Входной сигнал бит14.
  DbBitsToWord1.In15 = false            ; //Входной сигнал бит15.
  FbBitsToWord(&DbBitsToWord1)          ; //Преобразование 16 бит в слово.
  //                 = DbBitsToWord1.Out; //Выходной сигнал.
*/

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

struct DbBitsToWord
{
  //Входные переменные, сохраняемые.
  bool In0    ; //Входной сигнал бит0.
  bool In1    ; //Входной сигнал бит1.
  bool In2    ; //Входной сигнал бит2.
  bool In3    ; //Входной сигнал бит3.
  bool In4    ; //Входной сигнал бит4.
  bool In5    ; //Входной сигнал бит5.
  bool In6    ; //Входной сигнал бит6.
  bool In7    ; //Входной сигнал бит7.
  bool In8    ; //Входной сигнал бит8.
  bool In9    ; //Входной сигнал бит9.
  bool In10   ; //Входной сигнал бит10.
  bool In11   ; //Входной сигнал бит11.
  bool In12   ; //Входной сигнал бит12.
  bool In13   ; //Входной сигнал бит13.
  bool In14   ; //Входной сигнал бит14.
  bool In15   ; //Входной сигнал бит15.
  //Выходные переменные, сохраняемые.
  uint16_t Out; //Выходной сигнал.
};

void FbBitsToWord(struct DbBitsToWord *p);

#ifdef __cplusplus
}
#endif
