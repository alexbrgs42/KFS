#include "../../INCL/tty.h"

/* x86 Real Mode Memory Map : 0x000B8000 - 0x000BFFFF - Color Video Memory */

/// @brief Initializes the terminal by initializing its associated global variables
// 			and displaying the space char for every characters to display an empty terminal.
/// @param  None
void terminal_initialize(void)
{
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	terminal_buffer = (uint16_t*) 0xB8000;

    clear_buffer(terminal_buffer);

    enable_cursor(0x0A, 0x0C);
}
