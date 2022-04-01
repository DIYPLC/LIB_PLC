#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

struct GlobalVar
{
  //Системные переменные ПЛК
  uint32_t Uptime_ms; //Время работы [мс].
  uint32_t Ts_ms    ; //Время предидущего скана [мс].
  uint32_t Ts_max_ms; //Максимальное время скана [мс].
  float    Ts       ; //Время предидущего скана [с].
  bool     Reset    ; //Флаг первого скана.
  uint32_t ErrorCode; //Код ошибки.
  uint16_t MW[32]   ; //MODBUS HOLDING REGISTERS

  //Ввод вывод
  bool Di0;
  bool Di1;
  bool Do0;
  bool Do1;
  uint16_t Ai0;
  uint16_t Ai1;
  uint16_t Ao0;
  uint16_t Ao1;

  //Переменные для отладки.
  bool     tmp_bool;
  char     tmp_char;
  uint8_t  tmp_uint8;
  uint16_t tmp_uint16;
  uint32_t tmp_uint32;
  uint64_t tmp_uint64;
  int8_t   tmp_int8;
  int16_t  tmp_int16;
  int32_t  tmp_int32;
  int64_t  tmp_int64;
  float    tmp_float;
  double   tmp_double;
  float    tmp_floats[8];

  /*
    //Битовое поле для отладки.
    struct
    {
      uint8_t bit0: 1;
      uint8_t bit1: 1;
      uint8_t bit2: 1;
      uint8_t bit3: 1;
      uint8_t bit4: 1;
      uint8_t bit5: 1;
      uint8_t bit6: 1;
      uint8_t bit7: 1;
    } BitMap;

    //Объединение 32бит  для отладки.
    union
    {
      float    float32;
      uint32_t uint32;
      uint16_t uint16[2];
      uint8_t  uint8[4];
    } Convertor;

      //Часы
      struct
      {
      uint8_t Year;
      uint8_t Month;
      uint8_t Day;
      uint8_t Weekday;
      uint8_t Hour;
      uint8_t Minutes;
      uint8_t Seconds;
      uint16_t Millisecond;
      uint64_t UnixTime;
      } RTC;

  */
};

#ifdef __cplusplus
}
#endif

//  +---------+
//  | GNU GPL |
//  +---------+
//  |
//  |
//  .= .-_-. =.
// ((_/)o o(\_))
//  `-'(. .)`-'
//  |/| \_/ |\
//  ( |     | )
//  /"\_____/"\
//  \__)   (__/
// @COPYLEFT ALL WRONGS RESERVED :)
// Author: VA
// Contacts: DIY.PLC.314@gmail.com
// License: GNU GPL v2
