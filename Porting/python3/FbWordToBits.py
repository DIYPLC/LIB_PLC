#!/usr/bin/python3
# -*- coding: utf-8 -*-

# Преобразование слова в 16 бит.
#      DbWordToBits
#    +--------------+
#    | FbWordToBits |
# ->-|In        Out0|->-
#    |          Out1|->-
#    |          Out2|->-
#    |          Out3|->-
#    |          Out4|->-
#    |          Out5|->-
#    |          Out6|->-
#    |          Out7|->-
#    |          Out8|->-
#    |          Out9|->-
#    |         Out10|->-
#    |         Out11|->-
#    |         Out12|->-
#    |         Out13|->-
#    |         Out14|->-
#    |         Out15|->-
#    +--------------+


class FbWordToBits(object):

    def __init__(self) -> None:
        # VAR_INPUT
        self.In: int = int(0)
        # VAR_OUTPUT
        self.Out0 = bool(False)
        self.Out1 = bool(False)
        self.Out2 = bool(False)
        self.Out3 = bool(False)
        self.Out4 = bool(False)
        self.Out5 = bool(False)
        self.Out6 = bool(False)
        self.Out7 = bool(False)
        self.Out8 = bool(False)
        self.Out9 = bool(False)
        self.Out10 = bool(False)
        self.Out11 = bool(False)
        self.Out12 = bool(False)
        self.Out13 = bool(False)
        self.Out14 = bool(False)
        self.Out15 = bool(False)
        return

    def __call__(self) -> None:
        self.Out0 = bool(self.In & 0b0000000000000001)
        self.Out1 = bool(self.In & 0b0000000000000010)
        self.Out2 = bool(self.In & 0b0000000000000100)
        self.Out3 = bool(self.In & 0b0000000000001000)
        self.Out4 = bool(self.In & 0b0000000000010000)
        self.Out5 = bool(self.In & 0b0000000000100000)
        self.Out6 = bool(self.In & 0b0000000001000000)
        self.Out7 = bool(self.In & 0b0000000010000000)
        self.Out8 = bool(self.In & 0b0000000100000000)
        self.Out9 = bool(self.In & 0b0000001000000000)
        self.Out10 = bool(self.In & 0b0000010000000000)
        self.Out11 = bool(self.In & 0b0000100000000000)
        self.Out12 = bool(self.In & 0b0001000000000000)
        self.Out13 = bool(self.In & 0b0010000000000000)
        self.Out14 = bool(self.In & 0b0100000000000000)
        self.Out15 = bool(self.In & 0b1000000000000000)
        return

    def __del__(self) -> None:
        del self
        return

    def set_in(self, value: int) -> None:
        self.In = int(value)
        return

    def get_out0(self) -> bool:
        return bool(self.Out0)

    def get_out1(self) -> bool:
        return bool(self.Out1)

    def get_out2(self) -> bool:
        return bool(self.Out2)

    def get_out3(self) -> bool:
        return bool(self.Out3)

    def get_out4(self) -> bool:
        return bool(self.Out4)

    def get_out5(self) -> bool:
        return bool(self.Out5)

    def get_out6(self) -> bool:
        return bool(self.Out6)

    def get_out7(self) -> bool:
        return bool(self.Out7)

    def get_out8(self) -> bool:
        return bool(self.Out8)

    def get_out9(self) -> bool:
        return bool(self.Out9)

    def get_out10(self) -> bool:
        return bool(self.Out10)

    def get_out11(self) -> bool:
        return bool(self.Out11)

    def get_out12(self) -> bool:
        return bool(self.Out12)

    def get_out13(self) -> bool:
        return bool(self.Out13)

    def get_out14(self) -> bool:
        return bool(self.Out14)

    def get_out15(self) -> bool:
        return bool(self.Out15)


def _unit_test_() -> None:
    print("Unit test start")
    from FbBitsToWord import FbBitsToWord
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
