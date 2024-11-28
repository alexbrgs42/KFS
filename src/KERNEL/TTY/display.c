#include "../../INCL/tty.h"
#include "../../INCL/libc.h"

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y)
{
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
    current_screen_buffer[index] = vga_entry(c, color);
}

void terminal_putchar(char c)
{
    update_buffer(current_screen_buffer);
    if (c == '\n') {
        update_cursor(true);
    }
    else {
        terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
        update_cursor(false);
    }
}

void terminal_write_buffer(const char* data)
{
	size_t size = strlen(data);
	for (size_t i = 0; i < size; i++)
		terminal_putchar(data[i]);
}

/// @brief    Erase the last character (replace by space)
void terminal_backspace(void) {

    move_cursor_back();
    terminal_putchar(' ');
    move_cursor_back();
}