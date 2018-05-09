// license:BSD-3-Clause
// copyright-holders:Vas Crabb
/******************************************************************************
 *
 *  kay_kbd.cpp
 *
 *  Kaypro Serial Keyboards
 *
 ******************************************************************************/

#include "emu.h"
#include "machine/kay_kbd.h"

#define LOG_GENERAL (1U << 0)
#define LOG_TXD     (1U << 1)

//#define VERBOSE (LOG_GENERAL | LOG_TXD)
#include "logmacro.h"

#define LOGTXD(...) LOGMASKED(LOG_TXD, __VA_ARGS__)


/*
 * The KAYPRO keyboard has roughly the following layout:
 *
 *                                                                  [up] [down] [left] [right]
 *         [ESC] [1!] [2@] [3#] [4$] [5%] [6^] [7&] [8*] [9(] [0)] [-_] [=+] [`~] [BACK SPACE]
 *           [TAB] [qQ] [wW] [eE] [rR] [tT] [yY] [uU] [iI] [oO] [pP] [[{] []}]       [DEL]
 *[CTRL] [CAPS LOCK] [aA] [sS] [dD] [fF] [gG] [hH] [jJ] [kK] [lL] [;:] ['"] [RETURN] [\|]
 *            [SHIFT] [zZ] [xX] [cC] [vV] [bB] [nN] [mM] [,<] [.>] [/?] [SHIFT] [LINE FEED]
 *                      [                 SPACE                     ]
 *
 * [7] [8] [9] [-]
 * [4] [5] [6] [,]
 * [1] [2] [3]
 * [  0  ] [.] [ENTER]
 *
 * Notes on Appearance
 * -------------------
 * The RETURN key is shaped like a backwards "L". The keypad ENTER key is actually
 * oriented vertically, not horizontally. The alpha keys are marked with the uppercase letters
 * only. Other keys with two symbols have the shifted symbol printed above the unshifted symbol.
 * The keypad is actually located to the right of the main keyboard; it is shown separately here
 * as a convenience to users of narrow listing windows. The arrow keys are actually marked with
 * arrow graphics pointing in the appropriate directions. The F and J keys are specially shaped,
 * since they are the "home keys" for touch-typing. The CAPS LOCK key has a build-in red indicator
 * which is lit when CAPS LOCK is pressed once, and extinguished when the key is pressed again.
 */


/*
Kaypro 10 keyboard

This is a TTL-level asynchronous serial keyboard using mask-programmed
MCS-48 MCU.  Serial transmission and reception are handled in software
using the onboard timer/counter interrupt.  The frame format is 1 start
bit, 8 data bits, no parity, and 1 stop bit.

Active components:
* Mitsubishi M5L8049-109P-6 (MCS-48 MCU with 2KiB mask ROM)
* SN74154N (4-to-16 demultiplexer)
* DM7406N (hex inverter with open collector outputs)
* SN75451BP (dual high-speed, high-current line driver with AND inputs)
* 6.000MHz crystal

D0-D3 select the key matrix row, only 0x0..0xE are used (0x0F ignored).

D4 is the CAPS LOCK LED output.

P1 is connected to the key matrix columns.

P2.1, P2.2 and P2.3 are CTRL, CAPS LOCK, and SHIFT inputs.

P2.5 drives the speaker (1.5625kHz tone generated using timer/counter).

P2.7 is the serial data output to the host.

T1 is the serial data input from the host.

The program appears to be able to support "typewriter shift" and
"bitshift" layouts, and both ASCII and Kaypro control codes for the
numeric keypad, depending on how the matrix is wired.  All positions in
the key matrix will produce characters, although it's not clear whether
all of them are designed to serve a purpose - some may just be emergent
behaviour from the decoding algorithm.

The serial rate is generated by reloading the T register with 0xfe and
transfering a bit every 21 interrupts, giving a rate within 1% of the
desired 300 Baud:
6MHz / 15 / 32 / (0x100 - 0xfe) / 21 = 297.62 Baud

This scheme allows only 64 machine cycles between interrupts, and more
than half of thse are consumed by the timer service routine itself.

The program ROM checksum routine is supposed to compute the sum of all
program ROM bytes modulo 256 and the XOR of all program ROM bytes, but
due to bugs it omits the first byte of each page (0x000, 0x100, 0x200,
0x300, 0x400, 0x500, 0x600 and 0x700).

The serial command processing is quite lax in what it accepts:
xxxx xxx1   ignored
xxxx Mx10   short beep, set keyclick mute to M
xxxx M100   long beep, set keyclick mute to M
xxx1 M000   answer back with 0xAA?, set keyclick mute to M
xxx0 M000   set keyclick mute to M

The Kaypro II was sold with a different keyboard using an 8751 (MCS-51)
MCU, but we don't have a dump for it.
*/
#include "cpu/mcs48/mcs48.h"
#include "speaker.h"


DEFINE_DEVICE_TYPE(KAYPRO_10_KEYBOARD, kaypro_10_keyboard_device, "kaypro10kbd", "Kaypro 10 Keyboard")


namespace {

ROM_START(kaypro_10_keyboard)
	ROM_REGION(0x0800, "mcu", 0)
	ROM_LOAD("m5l8049.bin", 0x0000, 0x0800, CRC(dc772f80) SHA1(aa7cd3f476466203294675d56098dff45952b9b0))
ROM_END

INPUT_PORTS_START(kaypro_keyboard_typewriter)
	PORT_START("ROW.0")
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_0_PAD)      PORT_CHAR(UCHAR_MAMEKEY(0_PAD))     PORT_NAME("Pad 0")
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_4)          PORT_CHAR('4')  PORT_CHAR('$')
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_H)          PORT_CHAR('h')  PORT_CHAR('H')
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_V)          PORT_CHAR('v')  PORT_CHAR('V')
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_3_PAD)      PORT_CHAR(UCHAR_MAMEKEY(3_PAD))     PORT_NAME("Pad 3")
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_6_PAD)      PORT_CHAR(UCHAR_MAMEKEY(6_PAD))     PORT_NAME("Pad 6")
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_9_PAD)      PORT_CHAR(UCHAR_MAMEKEY(9_PAD))     PORT_NAME("Pad 9")
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_UNKNOWN) // 0xf8

	PORT_START("ROW.1")
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_UNKNOWN) // 0xa5
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_5)          PORT_CHAR('5')  PORT_CHAR('%')
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_R)          PORT_CHAR('r')  PORT_CHAR('R')
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_B)          PORT_CHAR('b')  PORT_CHAR('B')
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_2_PAD)      PORT_CHAR(UCHAR_MAMEKEY(2_PAD))     PORT_NAME("Pad 2")
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_5_PAD)      PORT_CHAR(UCHAR_MAMEKEY(5_PAD))     PORT_NAME("Pad 5")
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_8_PAD)      PORT_CHAR(UCHAR_MAMEKEY(8_PAD))     PORT_NAME("Pad 8")
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_UNKNOWN) // 0xf7

	PORT_START("ROW.2")
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_UNKNOWN) // 0xa4
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_6)          PORT_CHAR('6')  PORT_CHAR('^')
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_T)          PORT_CHAR('t')  PORT_CHAR('T')
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_N)          PORT_CHAR('n')  PORT_CHAR('N')
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_1_PAD)      PORT_CHAR(UCHAR_MAMEKEY(1_PAD))     PORT_NAME("Pad 1")
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_4_PAD)      PORT_CHAR(UCHAR_MAMEKEY(4_PAD))     PORT_NAME("Pad 4")
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_7_PAD)      PORT_CHAR(UCHAR_MAMEKEY(7_PAD))     PORT_NAME("Pad 7")
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_UNKNOWN) // 0xf6

	PORT_START("ROW.3")
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_RALT)       PORT_CHAR(10)                       PORT_NAME("LINE FEED")
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_7)          PORT_CHAR('7')  PORT_CHAR('&')
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_Y)          PORT_CHAR('y')  PORT_CHAR('Y')
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_M)          PORT_CHAR('m')  PORT_CHAR('M')
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_BACKSLASH)  PORT_CHAR('\\') PORT_CHAR('|')
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_DEL)        PORT_CHAR(UCHAR_MAMEKEY(DEL))       PORT_NAME("DEL")
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_UNKNOWN) // 0xe0
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_UNKNOWN) // 0xf5

	PORT_START("ROW.4")
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_UNKNOWN) // 0xa3
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_8)          PORT_CHAR('8')  PORT_CHAR('*')
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_U)          PORT_CHAR('u')  PORT_CHAR('U')
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_COMMA)      PORT_CHAR(',')  PORT_CHAR('<')
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_ENTER)      PORT_CHAR(13)                       PORT_NAME("RETURN")
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_UNKNOWN) // 0xd4
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_BACKSPACE)  PORT_CHAR(8)                        PORT_NAME("BACK SPACE")
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_RIGHT)      PORT_CHAR(UCHAR_MAMEKEY(RIGHT))

	PORT_START("ROW.5")
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_Z)          PORT_CHAR('z')  PORT_CHAR('Z')
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_W)          PORT_CHAR('w')  PORT_CHAR('W')
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_K)          PORT_CHAR('k')  PORT_CHAR('K')
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_S)          PORT_CHAR('s')  PORT_CHAR('S')
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_QUOTE)      PORT_CHAR('\'') PORT_CHAR('"')
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_CLOSEBRACE) PORT_CHAR(']')  PORT_CHAR('}')
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_TILDE)      PORT_CHAR('`')  PORT_CHAR('~')
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_LEFT)       PORT_CHAR(UCHAR_MAMEKEY(LEFT))

	PORT_START("ROW.6")
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_SPACE)      PORT_CHAR(' ')
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_9)          PORT_CHAR('9')  PORT_CHAR('(')
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_I)          PORT_CHAR('i')  PORT_CHAR('I')
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_STOP)       PORT_CHAR('.')  PORT_CHAR('>')
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_L)          PORT_CHAR('l')  PORT_CHAR('L')
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_P)          PORT_CHAR('p')  PORT_CHAR('P')
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_MINUS)      PORT_CHAR('-')  PORT_CHAR('_')
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_UP)         PORT_CHAR(UCHAR_MAMEKEY(UP))

	PORT_START("ROW.7")
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_UNKNOWN) // 0xa2
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_0)          PORT_CHAR('0')  PORT_CHAR(')')
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_O)          PORT_CHAR('o')  PORT_CHAR('O')
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_SLASH)      PORT_CHAR('/')  PORT_CHAR('?')
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_COLON)      PORT_CHAR(';')  PORT_CHAR(':')
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_OPENBRACE)  PORT_CHAR('[')  PORT_CHAR('{')
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_EQUALS)     PORT_CHAR('=')  PORT_CHAR('+')
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_DOWN)       PORT_CHAR(UCHAR_MAMEKEY(DOWN))

	PORT_START("ROW.8")
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_UNKNOWN) // 0xa1
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_2)          PORT_CHAR('2')  PORT_CHAR('@')
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_F)          PORT_CHAR('f')  PORT_CHAR('F')
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_X)          PORT_CHAR('x')  PORT_CHAR('X')
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_A)          PORT_CHAR('a')  PORT_CHAR('A')
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_Q)          PORT_CHAR('q')  PORT_CHAR('Q')
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_1)          PORT_CHAR('1')  PORT_CHAR(';')
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_UNKNOWN) // 0xf0

	PORT_START("ROW.9")
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_UNKNOWN) // 0xa0
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_E)          PORT_CHAR('e')  PORT_CHAR('E')
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_J)          PORT_CHAR('j')  PORT_CHAR('J')
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_D)          PORT_CHAR('d')  PORT_CHAR('D')
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_UNKNOWN) // 0xb0
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_TAB)        PORT_CHAR('\t')
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_ESC)        PORT_CHAR(UCHAR_MAMEKEY(ESC))
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_UNKNOWN) // 0xfe

	PORT_START("ROW.A")
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_DEL_PAD)    PORT_CHAR(UCHAR_MAMEKEY(DEL_PAD))   PORT_NAME("Pad .")
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_3)          PORT_CHAR('3')  PORT_CHAR('#')
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_G)          PORT_CHAR('g')  PORT_CHAR('G')
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_C)          PORT_CHAR('c')  PORT_CHAR('C')
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_ENTER_PAD)  PORT_CHAR(UCHAR_MAMEKEY(ENTER_PAD)) PORT_NAME("Pad ENTER")
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_PLUS_PAD)                                       PORT_NAME("Pad ,")
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_MINUS_PAD)  PORT_CHAR(UCHAR_MAMEKEY(MINUS_PAD)) PORT_NAME("Pad -")
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_UNKNOWN) // 0xf9

	PORT_START("ROW.B")
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_UNUSED) // 2 for ASCII keypad
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_UNUSED) // 1 for ASCII keypad
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_UNUSED) // 0 for "bitshift" layout or ASCII keypad
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_UNUSED) // 7 for ASCII keypad
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_UNUSED) // 0 for "bitshift" layout or ASCII keypad
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_UNUSED) // 9 for ASCII keypad
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_UNUSED) // 8 for ASCII keypad
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_UNUSED) // . for ASCII keypad

	PORT_START("ROW.C")
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_UNUSED) // 6 & for "bitshift" layout
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_UNUSED) // 3 # for "bitshift" layout?  identical to "typewriter shift" anyway
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_UNUSED) // 2 " for "bitshift" layout
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_UNUSED) // "typewriter shift" 2 @ duplicated here
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_UNUSED) // 6 for ASCII keypad
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_UNUSED) // 5 for ASCII keypad
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_UNUSED) // 4 for ASCII keypad
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_UNUSED) // 3 for ASCII keypad

	PORT_START("ROW.D")
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_UNUSED) // ` @ for "bitshift" layout
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_UNUSED) // - = for "bitshift" layout
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_UNUSED) // : * for "bitshift" layout
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_UNUSED) // ~ ^ for "bitshift" layout
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_UNUSED) // "typewriter shift" 6 ^ duplicated here
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_UNUSED) // 9 ) for "bitshift" layout
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_UNUSED) // 8 ( for "bitshift" layout
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_UNUSED) // 7 ' for "bitshift" layout

	PORT_START("ROW.E")
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_UNKNOWN) // 0xe0
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_UNKNOWN) // 0x90
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_UNKNOWN) // 0xa0
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_UNKNOWN) // 0x00
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_UNKNOWN) // 0xe0
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_UNKNOWN) // 0xc0
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_UNKNOWN) // 0x54
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_UNUSED) // ; + for "bitshift" layout

	PORT_START("ROW.F")
	PORT_BIT(0xff, IP_ACTIVE_LOW, IPT_UNUSED) // not scanned

	PORT_START("MOD")
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_LCONTROL) PORT_CODE(KEYCODE_RCONTROL) PORT_CHAR(UCHAR_SHIFT_2)           PORT_NAME("CTRL")
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_CAPSLOCK)                             PORT_CHAR(UCHAR_MAMEKEY(CAPSLOCK)) PORT_NAME("CAPS LOCK")
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_LSHIFT) PORT_CODE(KEYCODE_RSHIFT)     PORT_CHAR(UCHAR_SHIFT_1)           PORT_NAME("SHIFT")
INPUT_PORTS_END

INPUT_PORTS_START(kaypro_keyboard_bitshift)
	PORT_INCLUDE(kaypro_keyboard_typewriter)

	PORT_MODIFY("ROW.2")
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_UNUSED) // 6 ^ for "typewriter shift" layout

	PORT_MODIFY("ROW.3")
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_UNUSED) // 7 & for "typewriter shift" layout

	PORT_MODIFY("ROW.4")
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_UNUSED) // 8 * for "typewriter shift" layout

	PORT_MODIFY("ROW.5")
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_UNUSED) // ' " for "typewriter shift" layout
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_UNUSED) // ` ~ for "typewriter shift" layout

	PORT_MODIFY("ROW.6")
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_UNUSED) // 9 ) for "typewriter shift" layout
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_UNUSED) // - _ for "typewriter shift" layout

	PORT_MODIFY("ROW.7")
	PORT_BIT(0x10, IP_ACTIVE_LOW, IPT_UNUSED) // ; : for "typewriter shift" layout
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_UNUSED) // = + for "typewriter shift" layout

	PORT_MODIFY("ROW.8")
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_UNUSED) // 2 @ for "typewriter shift" layout

	PORT_MODIFY("ROW.C")
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_6)          PORT_CHAR('6')  PORT_CHAR('&')
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_2)          PORT_CHAR('2')  PORT_CHAR('"')

	PORT_MODIFY("ROW.D")
	PORT_BIT(0x01, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_EQUALS)     PORT_CHAR('`')  PORT_CHAR('@')
	PORT_BIT(0x02, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_MINUS)      PORT_CHAR('-')  PORT_CHAR('=')
	PORT_BIT(0x04, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_QUOTE)      PORT_CHAR(':')  PORT_CHAR('*')
	PORT_BIT(0x08, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_TILDE)      PORT_CHAR('~')  PORT_CHAR('^')
	PORT_BIT(0x20, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_9)          PORT_CHAR('9')  PORT_CHAR(')')
	PORT_BIT(0x40, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_8)          PORT_CHAR('8')  PORT_CHAR('(')
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_7)          PORT_CHAR('7')  PORT_CHAR('\'')

	PORT_MODIFY("ROW.E")
	PORT_BIT(0x80, IP_ACTIVE_LOW, IPT_KEYBOARD) PORT_CODE(KEYCODE_COLON)      PORT_CHAR(';')  PORT_CHAR('+')
INPUT_PORTS_END

} // anonymous namespace


kaypro_10_keyboard_device::kaypro_10_keyboard_device(
		machine_config const &mconfig,
		char const *tag,
		device_t *owner,
		std::uint32_t clock)
	: device_t(mconfig, KAYPRO_10_KEYBOARD, tag, owner, clock)
	, m_mcu(*this, "mcu")
	, m_bell(*this, "bell")
	, m_matrix(*this, "ROW.%X", 0)
	, m_modifiers(*this, "MOD")
	, m_rxd_cb(*this)
	, m_txd(1U)
	, m_bus(0U)
{
}

tiny_rom_entry const *kaypro_10_keyboard_device::device_rom_region() const
{
	return ROM_NAME(kaypro_10_keyboard);
}

MACHINE_CONFIG_START(kaypro_10_keyboard_device::device_add_mconfig)
	MCFG_DEVICE_ADD("mcu", I8049, 6_MHz_XTAL)
	MCFG_MCS48_PORT_P1_IN_CB(READ8(*this, kaypro_10_keyboard_device, p1_r))
	MCFG_MCS48_PORT_P2_IN_CB(READ8(*this, kaypro_10_keyboard_device, p2_r))
	MCFG_MCS48_PORT_P2_OUT_CB(WRITE8(*this, kaypro_10_keyboard_device, p2_w))
	MCFG_MCS48_PORT_T1_IN_CB(READLINE(*this, kaypro_10_keyboard_device, t1_r))
	MCFG_MCS48_PORT_BUS_IN_CB(READ8(*this, kaypro_10_keyboard_device, bus_r))
	MCFG_MCS48_PORT_BUS_OUT_CB(WRITE8(*this, kaypro_10_keyboard_device, bus_w))

	SPEAKER(config, "keyboard").front_center();
	MCFG_DEVICE_ADD("bell", SPEAKER_SOUND)
	MCFG_SOUND_ROUTE(ALL_OUTPUTS, "keyboard", 0.25)
MACHINE_CONFIG_END

ioport_constructor kaypro_10_keyboard_device::device_input_ports() const
{
	(void)&INPUT_PORTS_NAME(kaypro_keyboard_bitshift);
	return INPUT_PORTS_NAME(kaypro_keyboard_typewriter);
}

void kaypro_10_keyboard_device::device_start()
{
	m_rxd_cb.resolve_safe();

	save_item(NAME(m_txd));
	save_item(NAME(m_bus));
}

READ8_MEMBER(kaypro_10_keyboard_device::p1_r)
{
	return m_matrix[m_bus & 0x0f]->read();
}

READ8_MEMBER(kaypro_10_keyboard_device::p2_r)
{
	return m_modifiers->read() | 0xf8U;
}

WRITE8_MEMBER(kaypro_10_keyboard_device::p2_w)
{
	if ((VERBOSE & LOG_TXD) && (0x0014U >= m_mcu->pc()))
	{
		auto const suppressor(machine().disable_side_effects());
		address_space &mcu_ram(m_mcu->space(AS_DATA));
		std::uint8_t const txd_time(mcu_ram.read_byte(0x1cU));
		std::uint8_t const serial_flags(mcu_ram.read_byte(0x1eU));
		bool const txd_active(BIT(serial_flags, 6));
		if ((21U == txd_time) && txd_active)
		{
			std::uint8_t const txd_bit(mcu_ram.read_byte(0x1bU));
			LOGTXD(
					(9U == txd_bit) ? "serial transmit: start bit = %1$u (cycles = %3$u)\n" : "serial transmit: bit %2$u = %1$u (cycles = %3$u)\n",
					BIT(data, 7),
					8U - txd_bit,
					m_mcu->total_cycles());
		}
	}

	m_bell->level_w(BIT(data, 5));
	m_rxd_cb(BIT(data, 7));
}

READ_LINE_MEMBER(kaypro_10_keyboard_device::t1_r)
{
	return m_txd ? 1 : 0;
}

READ8_MEMBER(kaypro_10_keyboard_device::bus_r)
{
	return m_bus;
}

WRITE8_MEMBER(kaypro_10_keyboard_device::bus_w)
{
	if (BIT(m_bus ^ data, 4))
		machine().output().set_value("led_caps_lock", BIT(data, 4));
	m_bus = data;
}
