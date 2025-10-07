#!/usr/bin/python3
# -*- coding: utf-8 -*-

# Рампа разгона / торможения.
#         DbRamp
#    +--------------+
#    |    FbRamp    |
# ->-|In         Out|->-
#   -|Scale         |
#   -|TAcc          |
#   -|TDec          |
#   -|Ts            |
#    +--------------+

class FbRamp(object):
    
    def __init__(self) -> None:
        # VAR_INPUT
        self.In    = float(0.0)   # Входной сигнал.
        self.Scale = float(100.0) # Диапазон времени разгона и торможения.
        self.TAcc  = float(5.0)   # Время разгона от 0 до Scale [с].
        self.TDec  = float(5.0)   # Время торможения от Scale до 0 [c].
        self.Ts    = float(0.1)   # Шаг дискретизации по времени [с].
        # VAR_OUTPUT
        self.Out = float(0.0) # Выходной сигнал.
        return
    
    def __call__(self) -> None:
        # VAR_TEMP
        AccMode = bool(False) # Активен режим ускорения.
        DecMode = bool(False) # Активен режим замедления.
        # Режим байпаса интегратора рампы с безударным переходом.
        if (self.Scale <= 0.0):
            self.Out = self.In
        else: # Штатный режим работы.
            # Состояние Out до отработки шага интегрирования.
            # Оптимизировать и переместить сравнения нельзя.
            AccMode = (self.In > self.Out) # Активен режим ускорения.
            DecMode = (self.In < self.Out) # Активен режим замедления.
            # Режим ускорения рампы.
            if (AccMode):
                if (self.TAcc <= 0.0):
                    self.Out = self.In
                else:
                    self.Out = self.Out + ((self.Ts * self.Scale) / self.TAcc)
            # Режим замедления рампы.
            if (DecMode):
                if (self.TDec <= 0.0):
                    self.Out = self.In
                else:
                    self.Out = self.Out - ((self.Ts * self.Scale) / self.TDec)
            # Установившийся режим рампы.
            # Состояние Out после отработки шага интегрирования.
            if ( ((AccMode) and (self.Out >= self.In)) or ((DecMode) and (self.Out <= self.In)) or (self.In == self.Out) ):
                self.Out = self.In
        return
    
    def __del__(self) -> None:
        del self
        return


def _unit_test_() -> None:
    DbRamp = FbRamp()
    DbRamp.In    = 50.0  # Входной сигнал.
    DbRamp.Scale = 100.0 # Диапазон времени разгона и торможения.
    DbRamp.TAcc  = 5.0   # Время разгона от 0 до Scale [с].
    DbRamp.TDec  = 5.0   # Время торможения от Scale до 0 [c].
    DbRamp.Ts    = 0.1   # Шаг дискретизации по времени [с].
    timer1 = 0.0
    print("Time;","In;","Out")
    for i in range(70):
        print(timer1, ";", DbRamp.In, ";", DbRamp.Out)
        DbRamp()
        timer1 = timer1 + 0.1
        if timer1 >= 4.0:
            DbRamp.In = 0.0


if __name__ == "__main__":
    _unit_test_()
    input("press any key for exit...")

# Пример использования №1.
# Скорость открытия парового клапана от 0 до 100 процентов за 90  секунд.
# Скорость закрытия парового клапана от 100 до 0 процентов за 150 секунд.
# Параметры рампы для решения этой задачи:
# DbRamp1.Scale := 100.0; //Диапазон времени разгона и торможения.
# DbRamp1.TAcc  := 90.0 ; //Время разгона от 0 до Scale [с].
# DbRamp1.TDec  := 150.0; //Время торможения от Scale до 0 [c].

# Пример использования №2.
# Скорость разгона частотного привода от 0 до 50 Герц за 20 секунд.
# Скорость торможения частотного привода от 50 до 0 Герц за 15 секунд. 
# Параметры рампы для решения этой задачи:
# DbRamp2.Scale := 50.0; //Диапазон времени разгона и торможения.
# DbRamp2.TAcc  := 20.0; //Время разгона от 0 до Scale [с].
# DbRamp2.TDec  := 15.0; //Время торможения от Scale до 0 [c].

# Пример использования №3.
# Необходимо отключть рампу и передать сигнал напрямую с входа на выход. 
# Параметры рампы для решения этой задачи:
# DbRamp3.Scale := 0.0; //Диапазон времени разгона и торможения.

# Временная характеристика.

# ^ In
# |
# 100 *************
# |   *           *
# |   *           *
# |   *           *
# 0---------------------------------> t[s]

# ^ Out
# |
# |   TAcc         TDec
# |    10s          5s
# |  <----->       <-->
# 100       *******     ^
# |       *        *    | Scale 100%
# |     *           *   |
# |   *              *  v
# 0---------------------------------> t[s]

# Угол наклона рампы.
# tg(a) = Scale / TAcc

# Блок схема.

# Константы    Переключатель    Интегратор
# +-------+     +-----------+
# | Scale |     | In > Out  |
# | ----- |-->--|--+        |
# | TAcc  |     |   \       |
# +-------+     |    \      |
#               |     \     |
# +-------+     |      \    |     +-----+
# |       |     |       \   |     |  1  |
# |   0   |-->--|--+     +--|-->--| --- |-->-- Out
# |       |     | In ~= Out |     |  s  |
# +-------+     |           |     +-----+
#               |           |
# +-------+     |           |
# | Scale |     |           |
# | ----- |-->--|--+        |
# | TDec  |     | In < Out  |
# +-------+     +-----------+

# @COPYLEFT ALL WRONGS RESERVED :)
# Author: VA
# Contacts: DIY.PLC.314@gmail.com
# Date start LIB_PLC: 2014
# License: GNU GPL-2.0-or-later
# https://www.gnu.org/licenses/old-licenses/gpl-2.0.html
# https://www.youtube.com/watch?v=n1F_MfLRlX0
# https://www.youtube.com/@DIY_PLC
# https://github.com/DIYPLC/LIB_PLC
# https://oshwlab.com/diy.plc.314/PLC_HW1_SW1
# https://3dtoday.ru/3d-models/mechanical-parts/body/korpus-na-din-reiku
# https://t.me/DIY_PLC

# Спасибо за лекции.
# https://www.youtube.com/@unx7784/playlists
# https://www.youtube.com/@tkhirianov/playlists
