#include "../../INCL/io.h"
#include "../../INCL/tty.h"

/// @brief  Updates cursor's position
/// @param  line_break If the char that was written is a \n, the logic changes a
/// bit
void update_cursor(bool line_break) {
    uint16_t index = current_window - 1;

    if (line_break == true) {
        if (terminal_row[index] == VGA_HEIGHT - 2) {
            scroll_buffer();
        } else {
            terminal_row[index]++;
        }
        terminal_column[index] = 0;
    } else {
        terminal_column[index]++;
        if (terminal_column[index] == VGA_WIDTH) {
            if (terminal_row[index] == VGA_HEIGHT - 2) {
                scroll_buffer();
                } else {
                    terminal_row[index]++;
                }
            terminal_column[index] = 0;
        }
    }
    update_blinking_cursor();
}

/// @brief   Moves the cursor back from one column or row if we're at col 0
void move_cursor_back(void) {
    uint16_t index = current_window - 1;

    if (terminal_column[index] == 0) {
        if (terminal_row[index] != 0) {
            terminal_row[index]--;
            terminal_column[index] = VGA_WIDTH - 1;
        }
    } else {
    terminal_column[index]--;
    }
    update_blinking_cursor();
}

void update_blinking_cursor(void) {
    uint16_t index = current_window - 1;
    uint16_t pos = terminal_row[index] * VGA_WIDTH + terminal_column[index];

    outb(0x3D4, 0x0F); // 0x3D4 is a port that selects a screen's register, which
                        // is 0x0F (x position of cursor)
    outb(0x3D5,
        (uint8_t)(pos &
                    0xFF)); // 0x3D5 is a port that reads/writes to the selected
                            // register, we write the new x position of the cursor
    outb(0x3D4, 0x0E);     // we select 0X0E register (y position of cursor)
    outb(0x3D5, (uint8_t)((pos >> 8) &
                            0xFF)); // we write the new y position of the cursor
}

/// @brief                  Enable showing of blinking cursor
/// @param cursor_start     Change how large the cursor is
/// @param cursor_end       //
void enable_cursor(uint8_t cursor_start, uint8_t cursor_end) {
    outb(0x3D4, 0x0A);
    outb(0x3D5, (inb(0x3D5) & 0xC0) | cursor_start);

    outb(0x3D4, 0x0B);
    outb(0x3D5, (inb(0x3D5) & 0xE0) | cursor_end);
}

void reset_cursor(void) {
    terminal_row[current_window - 1] = 0;
    terminal_column[current_window - 1] = 0;
    update_blinking_cursor();
}
