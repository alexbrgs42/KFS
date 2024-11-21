#include "../../INCL/tty.h"

static inline uint16_t vga_entry(unsigned char uc, uint8_t color)
{
	return ((uint16_t) uc | ((uint16_t) color << 8) | ((uint16_t) 1 << 16));
}

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y)
{
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}

void terminal_putchar(char c)
{
	terminal_putentryat(c, terminal_color, terminal_column, terminal_row);

	if (++terminal_column == VGA_WIDTH) {
		terminal_column = 0;
		if (++terminal_row == VGA_HEIGHT)
			terminal_row = 0;
	}
}

size_t strlen(const char *str)
{
	size_t i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

void terminal_write_buffer(const char* data)
{
	size_t size = strlen(data);
	for (size_t i = 0; i < size; i++)
		terminal_putchar(data[i]);
}
