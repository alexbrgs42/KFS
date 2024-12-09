#include "../INCL/tty.h"
#include "../INCL/libc.h"

size_t		terminal_row[3];
size_t		terminal_column[3];
uint8_t		terminal_color;
uint16_t*	terminal_buffer;
uint16_t	current_window;

void kernel_main(void) 
{
	/* Initialize terminal interface */
	terminal_initialize();

	/* Newline support is left as an exercise. */
	print_welcome_screen();
	handle_keyboard();
}
