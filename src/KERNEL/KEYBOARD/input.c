#include "../../INCL/tty.h"
#include "../../INCL/io.h"
#include "../../INCL/libc.h"
#include "../../INCL/keyboard.h"

char get_char_from_input(char c) {
	return (scan_codes[(uint16_t) c]);
}

void terminal_putinput(char c)
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
			else if (c == KEYCODE_1) {
				switch_window(1);
				print_info_line();
			}
			else if (c == KEYCODE_2) {
				switch_window(2);
				print_info_line();
			}
			else if (c == KEYCODE_3) {
				switch_window(3);
				print_info_line();
			}
			else if (c > 0) {
				terminal_putinput(c & 0x7F);
				append_to_command_buffer(c & 0x7F);
			}
		}
	}
	while (c != 1); // 1 = ESCAPE
}