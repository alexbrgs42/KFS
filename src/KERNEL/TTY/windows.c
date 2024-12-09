#include "../../INCL/tty.h"

/// @brief              Switches to a specific window by setting the terminal buffer
/// @param new_window: The new window number (1 to 3)
void switch_window(uint16_t new_window) {

    if (new_window < 1 || new_window > 3) {
        return;
    }

    current_window = new_window;

    clear_buffer(terminal_buffer);
    clear_command_buffer();

    uint16_t offset = get_offset();

    for (uint16_t i = 0; i < VGA_HEIGHT; i ++) {
        for (uint16_t j = 0; j < VGA_WIDTH; j++) {
            size_t index = i * VGA_WIDTH + j;
            terminal_buffer[index] = terminal_buffer[index + offset];
        }
    }
}

/// @brief  returns the starting address of our different windows
uint16_t get_offset(void) {

    switch(current_window) {
        case 1:
            return (WINDOW1_BASE);
        case 2:
            return (WINDOW2_BASE);
        case 3:
            return (WINDOW3_BASE);
    }
}

/// @brief Moves all content of the buffer up one row
void scroll_buffer(void) {
    // Shift all rows up by one
    for (unsigned int i = 0; i < (VGA_HEIGHT - 2) * VGA_WIDTH; i++) {
        terminal_buffer[i] = terminal_buffer[i + VGA_WIDTH];
    }

    // Clear the last row (bottom-most row of the screen)
    for (unsigned int i = (VGA_HEIGHT - 2) * VGA_WIDTH; i < (VGA_HEIGHT - 1) * VGA_WIDTH; i++) {
        terminal_buffer[i] = vga_entry(' ', terminal_color);
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