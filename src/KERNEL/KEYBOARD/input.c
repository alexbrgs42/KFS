#include "../../INCL/tty.h"
#include "../../INCL/io.h"
#include "../../INCL/libc.h"
#include "../../INCL/keyboard.h"

char get_char_from_input(unsigned char c) {
	return (scan_codes[(uint16_t) c]);
}

void terminal_putinput(unsigned char c)
{
	char a = get_char_from_input(c);
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
				remove_from_command_buffer(1);
			}
            else if (c == KEYCODE_ENTER) {
					printk(0, "\n");
                    check_for_builtin();
                    printk(0, "$>");
                    clear_command_buffer();
			}
			else if (c > 0) {
				terminal_putinput(c & 0x7F);
				append_to_command_buffer(c & 0x7F);
			}
		}
	}
	while (c != 1); // 1 = ESCAPE
}


// TODO : Code to handle ctrl + key events, but seems to need interrupts to work
// else if (c == KEYCODE_CTRL_L || c == KEYCODE_CTRL_R) {
//     if (c & 0x80) {  									// 0x80 is the break code, meaning key release
//         ctrl_pressed = false;
//     } else {
//         ctrl_pressed = true;  							// Set ctrl_pressed to true when Ctrl key is pressed
//     }
// }
// else if (c == KEYCODE_L && ctrl_pressed) {
// 	switch_buffer(screen_buffer_a);
// }
