#include "../../INCL/tty.h"

void    clear_buffer(uint16_t *screen_buffer) {

    for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			screen_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}

void load_buffer(uint16_t *screen_buffer) {

    for (int y = 0; y < 25; y ++) {
        for (int x = 0; x < 80; x ++) {
            const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = screen_buffer[index];
        }
    }
}

void update_buffer(uint16_t *screen_buffer) {
    
    const size_t index = terminal_row * VGA_WIDTH + terminal_column;

    screen_buffer[index] = terminal_buffer[index];
}

void switch_buffer(uint16_t *screen_buffer) {

    if (current_screen_buffer == screen_buffer) {
        return ;
    }

    // Save current cursor position to the right variable
    if (current_screen_buffer == screen_buffer_a) {
        cursor_pos_a = terminal_row * VGA_WIDTH + terminal_column;
    }
    else if (current_screen_buffer == screen_buffer_b) {
        cursor_pos_b = terminal_row * VGA_WIDTH + terminal_column;
    }
    else if (current_screen_buffer == screen_buffer_c) {
        cursor_pos_c = terminal_row * VGA_WIDTH + terminal_column;
    }

    load_buffer(screen_buffer);

    // Load the right cursor
    uint16_t pos;

    if (screen_buffer == screen_buffer_a) {
        pos = cursor_pos_a;
    }
    else if (screen_buffer == screen_buffer_b) {
        pos = cursor_pos_b;
    }
    else if (screen_buffer == screen_buffer_b) {
        pos = cursor_pos_c;
    }

    terminal_row = pos / VGA_WIDTH;
    terminal_column = pos % VGA_WIDTH;

    current_screen_buffer = screen_buffer;
}

//TODO : allows user to change windows with keyboard input
//TODO : it must also change 'current_screen_buffer'