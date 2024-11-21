#ifndef TTY_H
# define TTY_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/**********************************************************************************/
/*                                GLOBAL VARIABLES                                */
/**********************************************************************************/

static const size_t VGA_WIDTH = 80;						/* vga format */
static const size_t VGA_HEIGHT = 25;

extern size_t		terminal_row;						/* row of the cursor of the terminal */
extern size_t		terminal_column;					/* column of the cursor of the terminal */
extern uint8_t		terminal_color;						/* color of the text of the terminal */
extern uint16_t*	terminal_buffer;					/* vga buffer for writing on the terminal */

/**********************************************************************************/
/*                                     COLORS                                     */
/**********************************************************************************/

/* Hardware text mode color constants. */
enum vga_color {
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15,
};
typedef enum vga_color vga_color;

/**********************************************************************************/
/*                                   PROTOTYPES                                   */
/**********************************************************************************/

void	terminal_initialize(void);
void	terminal_set_color(uint8_t color);
void	terminal_write_buffer(const char* data);

#endif