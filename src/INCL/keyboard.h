#ifndef KEYBOARD_H
#define KEYBOARD_H

#define KEYCODE_A 0x1E
#define KEYCODE_B 0x30
#define KEYCODE_C 0x2E
#define KEYCODE_D 0x20
#define KEYCODE_E 0x12
#define KEYCODE_F 0x21
#define KEYCODE_G 0x22
#define KEYCODE_H 0x23
#define KEYCODE_I 0x17
#define KEYCODE_J 0x24
#define KEYCODE_K 0x25
#define KEYCODE_L 0x26
#define KEYCODE_M 0x32
#define KEYCODE_N 0x31
#define KEYCODE_O 0x18
#define KEYCODE_P 0x19
#define KEYCODE_Q 0x10
#define KEYCODE_R 0x13
#define KEYCODE_S 0x1F
#define KEYCODE_T 0x14
#define KEYCODE_U 0x16
#define KEYCODE_V 0x2F
#define KEYCODE_W 0x11
#define KEYCODE_X 0x2D
#define KEYCODE_Y 0x15
#define KEYCODE_Z 0x2C

#define KEYCODE_BACKSPACE 0x0E
#define KEYCODE_TAB 0x0F
#define KEYCODE_ENTER 0x1C
#define KEYCODE_ESC 0x01
#define KEYCODE_SHIFT_L 0x2A
#define KEYCODE_SHIFT_R 0x36
#define KEYCODE_CTRL_L 0x1D
#define KEYCODE_CTRL_R 0x1D
#define KEYCODE_ALT_L 0x38
#define KEYCODE_ALT_R 0x38
#define KEYCODE_SPACE 0x39
#define KEYCODE_CAPS_LOCK 0x3A
#define KEYCODE_F1 0x3B
#define KEYCODE_F2 0x3C
#define KEYCODE_F3 0x3D
#define KEYCODE_F4 0x3E
#define KEYCODE_F5 0x3F
#define KEYCODE_F6 0x40
#define KEYCODE_F7 0x41
#define KEYCODE_F8 0x42
#define KEYCODE_F9 0x43
#define KEYCODE_F10 0x44
#define KEYCODE_F11 0x57
#define KEYCODE_F12 0x58
#define KEYCODE_SCROLL_LOCK 0x46
#define KEYCODE_PAUSE 0x45
#define KEYCODE_INSERT 0x52
#define KEYCODE_HOME 0x47
#define KEYCODE_PAGE_UP 0x49
#define KEYCODE_DELETE 0x53
#define KEYCODE_END 0x4F
#define KEYCODE_PAGE_DOWN 0x51
#define KEYCODE_ARROW_UP 0x72
#define KEYCODE_ARROW_DOWN 0x73
#define KEYCODE_ARROW_LEFT 0x75
#define KEYCODE_ARROW_RIGHT 0x74

#define KEYCODE_1 0x02
#define KEYCODE_2 0x03
#define KEYCODE_3 0x04
#define KEYCODE_4 0x05
#define KEYCODE_5 0x06
#define KEYCODE_6 0x07
#define KEYCODE_7 0x08
#define KEYCODE_8 0x09
#define KEYCODE_9 0x0A
#define KEYCODE_0 0x0B
#define KEYCODE_MINUS 0x0C
#define KEYCODE_EQUALS 0x0D
#define KEYCODE_LEFT_BRACKET 0x1A
#define KEYCODE_RIGHT_BRACKET 0x1B
#define KEYCODE_BACKSLASH 0x2B
#define KEYCODE_SEMICOLON 0x27
#define KEYCODE_APOSTROPHE 0x28
#define KEYCODE_GRAVE 0x29
#define KEYCODE_COMMA 0x33
#define KEYCODE_PERIOD 0x34
#define KEYCODE_SLASH 0x35

char scan_codes[128] = {
    0,
    27, // escape
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-',  '=', '\b', '\t',
    'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[',  ']', '\n',
    -11, // left ctrl
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', -12,  '\\',
    'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0,    '*', 0,    ' ',
    0,   -1,  -2,  -3,  -4,  -5,  -6,  -7,  -8,  -9,  -10,  0,   0,    '7',
    0,   '9', '-', -13, '5', -14, '+', '1', 0,   '3', '0',  '.', 0,    0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,   0,    0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,    0,   0,    0,
    0,   0};

#endif
