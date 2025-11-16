#!/usr/bin/python3
# -*- coding: utf-8 -*-

# Преобразование 16 бит в слово.
#      DbBitsToWord
#    +--------------+
#    | FbBitsToWord |
# ->-|In0        Out|->-
# ->-|In1           |
# ->-|In2           |
# ->-|In3           |
# ->-|In4           |
# ->-|In5           |
# ->-|In6           |
# ->-|In7           |
# ->-|In8           |
# ->-|In9           |
# ->-|In10          |
# ->-|In11          |
# ->-|In12          |
# ->-|In13          |
# ->-|In14          |
# ->-|In15          |
#    +--------------+


class FbBitsToWord(object):

    def __init__(self) -> None:
        # VAR_INPUT
        self.In0 = bool(False)
        self.In1 = bool(False)
        self.In2 = bool(False)
        self.In3 = bool(False)
        self.In4 = bool(False)
        self.In5 = bool(False)
        self.In6 = bool(False)
        self.In7 = bool(False)
        self.In8 = bool(False)
        self.In9 = bool(False)
        self.In10 = bool(False)
        self.In11 = bool(False)
        self.In12 = bool(False)
        self.In13 = bool(False)
        self.In14 = bool(False)
        self.In15 = bool(False)
        # VAR_OUTPUT
        self.Out = int(0)
        return

    def __call__(self) -> None:
        self.Out = 0
        if self.In0:
            self.Out = (self.Out | 0b0000000000000001)
        if self.In1:
            self.Out = (self.Out | 0b0000000000000010)
        if self.In2:
            self.Out = (self.Out | 0b0000000000000100)
        if self.In3:
            self.Out = (self.Out | 0b0000000000001000)
        if self.In4:
            self.Out = (self.Out | 0b0000000000010000)
        if self.In5:
            self.Out = (self.Out | 0b0000000000100000)
        if self.In6:
            self.Out = (self.Out | 0b0000000001000000)
        if self.In7:
            self.Out = (self.Out | 0b0000000010000000)
        if self.In8:
            self.Out = (self.Out | 0b0000000100000000)
        if self.In9:
            self.Out = (self.Out | 0b0000001000000000)
        if self.In10:
            self.Out = (self.Out | 0b0000010000000000)
        if self.In11:
            self.Out = (self.Out | 0b0000100000000000)
        if self.In12:
            self.Out = (self.Out | 0b0001000000000000)
        if self.In13:
            self.Out = (self.Out | 0b0010000000000000)
        if self.In14:
            self.Out = (self.Out | 0b0100000000000000)
        if self.In15:
            self.Out = (self.Out | 0b1000000000000000)
        return

    def __del__(self) -> None:
        del self
        return

    def set_in0(self, value: bool) -> None:
        self.In0 = bool(value)
        return

    def set_in1(self, value: bool) -> None:
        self.In1 = bool(value)
        return

    def set_in2(self, value: bool) -> None:
        self.In2 = bool(value)
        return

    def set_in3(self, value: bool) -> None:
        self.In3 = bool(value)
        return

    def set_in4(self, value: bool) -> None:
        self.In4 = bool(value)
        return

    def set_in5(self, value: bool) -> None:
        self.In5 = bool(value)
        return

    def set_in6(self, value: bool) -> None:
        self.In6 = bool(value)
        return

    def set_in7(self, value: bool) -> None:
        self.In7 = bool(value)
        return

    def set_in8(self, value: bool) -> None:
        self.In8 = bool(value)
        return

    def set_in9(self, value: bool) -> None:
        self.In9 = bool(value)
        return

    def set_in10(self, value: bool) -> None:
        self.In10 = bool(value)
        return

    def set_in11(self, value: bool) -> None:
        self.In11 = bool(value)
        return

    def set_in12(self, value: bool) -> None:
        self.In12 = bool(value)
        return

    def set_in13(self, value: bool) -> None:
        self.In13 = bool(value)
        return

    def set_in14(self, value: bool) -> None:
        self.In14 = bool(value)
        return

    def set_in15(self, value: bool) -> None:
        self.In15 = bool(value)
        return

    def get_out(self) -> int:
        return int(self.Out)


def _unit_test_() -> None:
    print("Unit test start")
    from FbWordToBits import FbWordToBits
    word_to_bits = FbWordToBits()
    bits_to_word = FbBitsToWord()
    error_flag = False
    for i in range(65536):
        word_to_bits.In = i
        word_to_bits()
        bits_to_word.In0 = word_to_bits.Out0
        bits_to_word.In1 = word_to_bits.Out1
        bits_to_word.In2 = word_to_bits.Out2
        bits_to_word.In3 = word_to_bits.Out3
        bits_to_word.In4 = word_to_bits.Out4
        bits_to_word.In5 = word_to_bits.Out5
        bits_to_word.In6 = word_to_bits.Out6
        bits_to_word.In7 = word_to_bits.Out7
        bits_to_word.In8 = word_to_bits.Out8
        bits_to_word.In9 = word_to_bits.Out9
        bits_to_word.In10 = word_to_bits.Out10
        bits_to_word.In11 = word_to_bits.Out11
        bits_to_word.In12 = word_to_bits.Out12
        bits_to_word.In13 = word_to_bits.Out13
        bits_to_word.In14 = word_to_bits.Out14
        bits_to_word.In15 = word_to_bits.Out15
        bits_to_word()
        # print(hex(i), hex(bits_to_word.Out), hex(word_to_bits.In))
        if bits_to_word.Out != word_to_bits.In:
            error_flag = True
    if error_flag:
        print("Test ERROR")
    else:
        print("Test OK")
    return


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
