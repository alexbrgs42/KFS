#include "../../INCL/tty.h"

void    clear_buffer(char *screen_buffer) {

    for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			screen_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}

void load_buffer(char *screen_buffer) {

    for (int y = 0; y < 25; y ++) {
        for (int x = 0; x < 80; x ++) {
            const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = screen_buffer[index];
        }
    }
}

//TODO : allows user to change windows with keyboard input
//TODO : it must also change 'current_screen_buffer'