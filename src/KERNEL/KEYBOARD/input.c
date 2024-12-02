#include "../../INCL/tty.h"
#include "../../INCL/io.h"
#include "../../INCL/libc.h"
#include "../../INCL/keyboard.h"

void terminal_putinput(unsigned char c)
{
	char a = scan_codes[(uint16_t) c];
    terminal_write_buffer(&a);
}

bool ctrl_pressed = false;

void handle_keyboard()
{
	char c = 0;
	do
	{
		if(inb(0x60) != c) 											//Read from the keyboard port
		{
			c = inb(0x60);

			if (c == KEYCODE_BACKSPACE) {
				terminal_backspace(); 								// Erase last character and move cursor back
			}
            else if (c == KEYCODE_CTRL_L || c == KEYCODE_CTRL_R) {
                if (c & 0x80) {  									// 0x80 is the break code, meaning key release
                    ctrl_pressed = false;
                } else {
                    ctrl_pressed = true;  							// Set ctrl_pressed to true when Ctrl key is pressed
                }
            }
			// TODO
			// else if (c == KEYCODE_1 && ctrl_pressed) {
			// 	switch_buffer(screen_buffer_a);
			// }
			// else if (c == KEYCODE_2 && ctrl_pressed) {
			// 	switch_buffer(screen_buffer_b);
			// }
			// else if (c == KEYCODE_3 && ctrl_pressed) {
			// 	switch_buffer(screen_buffer_c);
			// }
			else if (c > 0)
			{
				terminal_putinput(c & 0x7F);
				if (c == KEYCODE_ENTER) {
					printk(0, "$>");
					//TODO : Check if content entered is a command
				}
			}
		}
	}
	while (c != 1); // 1 = ESCAPE
}
