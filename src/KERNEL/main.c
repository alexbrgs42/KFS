#include "../INCL/tty.h"
#include "../INCL/libc.h"

size_t		terminal_row;
size_t		terminal_column;
uint8_t		terminal_color;
uint16_t*	terminal_buffer;

void kernel_main(void) 
{
	/* Initialize terminal interface */
	terminal_initialize();

	/* Newline support is left as an exercise. */
	print_welcome_screen();
	handle_keyboard();
}
