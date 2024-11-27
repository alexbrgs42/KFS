#ifndef TTY_H
# define TTY_H

# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>

/**********************************************************************************/
/*                                GLOBAL VARIABLES                                */
/**********************************************************************************/

static const size_t VGA_WIDTH = 80;						/* vga format */
static const size_t VGA_HEIGHT = 25;

extern size_t		terminal_row;						/* row of the cursor of the terminal */
extern size_t		terminal_column;					/* column of the cursor of the terminal */
extern uint8_t		terminal_color;						/* color of the text of the terminal */
extern uint16_t*	terminal_buffer;					/* vga buffer for writing on the terminal */

static char     screen_buffer_a[2000];
static char     screen_buffer_b[2000];
static char     screen_buffer_c[2000];

static char *   current_screen_buffer;

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
void	terminal_putentryat(char c, uint8_t color, size_t x, size_t y);

uint8_t vga_entry_color(vga_color fg, vga_color bg);
uint16_t vga_entry(unsigned char uc, uint8_t color);

void    enable_cursor(uint8_t cursor_start, uint8_t cursor_end);
void    update_cursor(bool line_break);

void    clear_buffer(char *screen_buffer);
void    load_buffer(char *screen_buffer);

void	handle_keyboard();

#endif