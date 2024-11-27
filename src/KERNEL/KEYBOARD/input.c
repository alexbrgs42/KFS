#include "../../INCL/tty.h"
#include "../../INCL/io.h"
#include "../../INCL/libc.h"
#include "../../INCL/keyboard.h"

void terminal_putinput(unsigned char c)
{
	char a = scan_codes[(uint16_t) c];
    terminal_write_buffer(&a);
}

void handle_keyboard()
{
	char c = 0;
	do
	{
		if(inb(0x60) != c) // PORT FROM WHICH WE READ
		{
			c = inb(0x60);

			// Check if the key is backspace
			if (c == 0x0E) {
				terminal_backspace(); // Erase last character and move cursor back
			}
			else if (c > 0)
			{
				terminal_putinput(c & 0x7F); // print on screen
			}
		}
	}
	while (c != 1); // 1 = ESCAPE
}
