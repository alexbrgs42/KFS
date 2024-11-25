#include "../../INCL/tty.h"

void terminal_initialize(void)
{
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	terminal_buffer = (uint16_t*) 0xB8000;

    // // Empty all screen buffers :
    // clear_buffer(screen_buffer_a);
    // clear_buffer(screen_buffer_b);
    // clear_buffer(screen_buffer_c);

    // // Load the first buffer
    // load_buffer(screen_buffer_a);
    // current_screen_buffer = screen_buffer_a;

    for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}

    // enable_cursor(0, 0);
}
