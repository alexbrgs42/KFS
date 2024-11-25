#include "../../INCL/tty.h"
#include "../../INCL/io.h"

/// @brief  Updates cursor's position
/// @param  If the char that was written is a \n, the logic changes a bit
void    update_cursor(bool line_break) {

    if (line_break == true) {
        terminal_row++;
        terminal_column = 0;
    }
    else {
        terminal_column++;
        if (terminal_column == VGA_WIDTH) {
            terminal_column = 0;
            terminal_row++;
        }
    }

    if (terminal_row == VGA_HEIGHT - 1) {
        terminal_row = 1;
    }

    // Updates the blinking cursor position
    // TODO: Currently updates after every char written, probaby a good idea to only do it after 
    // TODO: writing a chunk of data to optimize
    // ! OR : always keep it at the bottom of the screen and separate the input block from the display block
    uint16_t pos = terminal_row * VGA_WIDTH + terminal_column;

	outb(0x3D4, 0x0F);
	outb(0x3D5, (uint8_t) (pos & 0xFF));
	outb(0x3D4, 0x0E);
	outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}

void enable_cursor(uint8_t cursor_start, uint8_t cursor_end)
{
	outb(0x3D4, 0x0A);
	outb(0x3D5, (inb(0x3D5) & 0xC0) | cursor_start);

	outb(0x3D4, 0x0B);
	outb(0x3D5, (inb(0x3D5) & 0xE0) | cursor_end);
}
