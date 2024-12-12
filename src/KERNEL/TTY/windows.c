#include "../../INCL/tty.h"

/// @brief              Switches to a specific window by setting the terminal buffer
/// @param new_window: The new window number (1 to 3)
void switch_window(uint16_t new_window) {

    if (new_window < 1 || new_window > 3) {
        return;
    }

    current_window = new_window;

    clear_buffer(terminal_buffer);

    for (uint16_t i = 0; i < VGA_HEIGHT; i ++) {
        for (uint16_t j = 0; j < VGA_WIDTH; j++) {
            size_t index = i * VGA_WIDTH + j;
            // Get the address for the current window and write to it
            terminal_buffer[index] = terminal_windows[current_window - 1][index];
        }
    }

    update_blinking_cursor();
}

/// @brief Moves all content of the buffer up one row
void scroll_buffer(void) {
    // Shift all rows up by one
    for (unsigned int i = 0; i < (VGA_HEIGHT - 2) * VGA_WIDTH; i++) {
        terminal_buffer[i] = terminal_buffer[i + VGA_WIDTH];
        terminal_windows[current_window - 1][i] = terminal_windows[current_window - 1][i + VGA_WIDTH];
    }

    // Clear the last row (bottom-most row of the screen)
    for (unsigned int i = (VGA_HEIGHT - 2) * VGA_WIDTH; i < (VGA_HEIGHT - 1) * VGA_WIDTH; i++) {
        terminal_buffer[i] = vga_entry(' ', terminal_color);
        terminal_windows[current_window - 1][i] = vga_entry(' ', terminal_color);
    }
}

/// @brief                  Replace all content of the video memory by spaces
/// @param screen_buffer    Pointer to the video memory 
void    clear_buffer(uint16_t *screen_buffer) {

    for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			screen_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}