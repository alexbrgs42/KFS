#include "../../INCL/tty.h"

/// @brief Moves all content of the buffer up one row
void scroll_buffer(void) {
    // Shift all rows up by one
    for (unsigned int i = 0; i < (VGA_HEIGHT - 1) * VGA_WIDTH; i++) {
        terminal_buffer[i] = terminal_buffer[i + VGA_WIDTH];
    }

    // Clear the last row (bottom-most row of the screen)
    for (unsigned int i = (VGA_HEIGHT - 1) * VGA_WIDTH; i < VGA_HEIGHT * VGA_WIDTH; i++) {
        terminal_buffer[i] = vga_entry(' ', terminal_color);
    }
}

/// @brief                  Replace all content of a buffer by spaces
/// @param screen_buffer    The buffer to clear
void    clear_buffer(uint16_t *screen_buffer) {

    for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			screen_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}


//TODO : allows user to change windows with keyboard input
//TODO : it must also change 'current_screen_buffer'