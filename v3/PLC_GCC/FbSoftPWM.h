//ШИМ генератор двухканальный.
//            DbSoftPWM
//     +---------------------+
//     |      FbSoftPWM      |
//  ->-|DutyCucle      PWMPOS|->-
//    -|PeriodPositive PWMNEG|->-
//    -|PeriodNegative       |
//    -|DBMAX                |
//    -|DBMIN                |
//    -|Ts                   |
//     +---------------------+
/*
  Пример вызова программы. Выполнять код каждые Ts = 0.1 с.
  static struct DbSoftPWM DbSoftPWM1 = {0};
  DbSoftPWM1.DutyCucle      = 50.0             ; //Коэффициент заполнения -100...0...100 [%].
  DbSoftPWM1.PeriodPositive = 10.0             ; //Период ШИМ для положительного коэффициента заполнения [с].
  DbSoftPWM1.PeriodNegative = 10.0             ; //Период ШИМ для отрицательного коэффициента заполнения [с].
  DbSoftPWM1.DBMAX          = 0.001            ; //dead band - Зона нечувствительности, верхняя граница [%].
  DbSoftPWM1.DBMIN          = -0.001           ; //dead band - Зона нечувствительности, нижняя граница [%].
  DbSoftPWM1.Ts             = 0.1              ; //Шаг дискретизации по времени [с].
  FbSoftPWM(&DbSoftPWM1)                       ; //ШИМ генератор двухканальный.
  //                        = DbSoftPWM1.PWMPOS; //Выход ШИМ для положительных значений входа.
  //                        = DbSoftPWM1.PWMNEG; //Выход ШИМ для отрицательных значений входа.
*/

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

struct DbSoftPWM
{
  //Входные переменные, сохраняемые.
  float DutyCucle     ; //Коэффициент заполнения -100...0...100 [%].
  float PeriodPositive; //Период ШИМ для положительного коэффициента заполнения [с].
  float PeriodNegative; //Период ШИМ для отрицательного коэффициента заполнения [с].
  float DBMAX         ; //dead band - Зона нечувствительности, верхняя граница [%].
  float DBMIN         ; //dead band - Зона нечувствительности, нижняя граница [%].
  float Ts            ; //Шаг дискретизации по времени [с].
  //Выходные переменные, сохраняемые.
  bool  PWMPOS        ; //Выход ШИМ для положительных значений входа.
  bool  PWMNEG        ; //Выход ШИМ для отрицательных значений входа.
  //Внутренние переменные, сохраняемые.
  float TimerPositive ; //Таймер для положительного коэффициента заполнения [с].
  float TimerNegative ; //Таймер для отрицательного коэффициента заполнения [с].
};

void FbSoftPWM(struct DbSoftPWM *p);

#ifdef __cplusplus
}
#endif
