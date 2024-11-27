#ifndef KEYBOARD_H
# define KEYBOARD_H

unsigned char scan_codes[128] =
{
	0,
	27, // escape
	'1',
	'2',
	'3',
	'4', 
	'5',
	'6',
	'7',
	'8',
	'9',
	'0',
	'-',
	'=',
	'\b', // backslash
	'\t', // horizontal tab
	'q',
	'w',
	'e',
	'r',
	't',
	'y',
	'u',
	'i',
	'o',
	'p',
	'[',
	']',
	'\n', // enter
	-11, // left ctrl
	'a',
	's',
	'd',
	'f',
	'g',
	'h',
	'j',
	'k',
	'l',
	';',
	'\'',
	'`',
	-12, // left shift
	'\\',
	'z',
	'x',
	'c',
	'v',
	'b',
	'n',
	'm',
	',',
	'.',
	'/', // slash
	0, // right shift
	'*', // numpad asterisk
	0, // left alt
	' ', // space
	0,
	-1, // F1
	-2, // F2
	-3, // F3
	-4, // F4
	-5, // F5
	-6, // F6
	-7, // F7
	-8, // F8
	-9, // F9
	-10, // F10
	0,
	0, // scroll lock
	'7', // numpad 7, HOME key if preceded by keycode 224
	0, // numpad 8, up arrow if preceded by keycode 224
	'9', // numpad 9, PAGE UP key if preceded by keycode 224
	'-', // numpad hyphen
	-13, // numpad 4, left arrow if preceded by keycode 224
	'5', // numpad 5
	-14, // numpad 6, right arrow if preceded by keycode 224
	'+',
	'1', // numpad 1, END key if preceded by keycode 224
	0, // numpad 2, down arrow if preceded by keycode 224
	'3', // numpad 3, PAGE DOWN key if preceded by keycode 224
	'0', // numpad 0, INSERT key if preceded by keycode 224
	'.', // numpad dot, DELETE key if preceded by keycode 224
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
};

#endif