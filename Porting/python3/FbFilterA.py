#!/usr/bin/python3
# -*- coding: utf-8 -*-

# Фильтр апериодический.
#      DbFilterA
#    +-----------+
#    | FbFilterA |
# ->-|In      Out|->-
#   -|Tf         |
#   -|Ts         |
#    +-----------+

class FbFilterA(object):

    def __init__(self) -> None:
        # VAR_INPUT
        self.In = float(0.0) # Входной сигнал до фильтрации.
        self.Tf = float(1.0) # Постоянная времени фильтра [с].
        self.Ts = float(0.1) # Шаг дискретизации по времени [с].
        # VAR_OUTPUT
        self.Out = float(0.0) # Выходной сигнал после фильтрации.
        return

    def __call__(self) -> None:
        # VAR_TEMP
        tmp = float(0.0)
        # W(s) = 1/(1+Tf*s) при Ts->0.
        if self.Tf <= 0.0:
            self.Out = self.In
        else:
            tmp = (self.In - self.Out) / self.Tf
            self.Out = self.Out + tmp * self.Ts
        return

    def __del__(self) -> None:
        del self
        return

def _unit_test_() -> None:
    DbFilterA1 = FbFilterA()
    DbFilterA1.In = 1.0
    timer1 = 0.0
    for i in range(11):
        print("Time s:",timer1,"Out:",DbFilterA1.Out)
        DbFilterA1()
        timer1 = timer1 + 0.1

if __name__ == "__main__":
    _unit_test_()
    input("press any key for exit...")

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
