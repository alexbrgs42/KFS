#include "../../INCL/tty.h"

static inline uint8_t vga_entry_color(vga_color fg, vga_color bg)
{
	return (fg | (bg << 4));
}

static inline uint16_t vga_entry(unsigned char uc, uint8_t color)
{
	return ((uint16_t) uc | ((uint16_t) color << 8));
}

void terminal_initialize(void)
{
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	terminal_buffer = (uint16_t*) 0xB8000;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}
