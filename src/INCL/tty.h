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

//TODO : once memory is configured, malloc the required size only
static char         command_buffer[1024];

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

void    clear_command_buffer(void);
void    append_to_command_buffer(unsigned char c);
void    remove_from_command_buffer(uint16_t count);
void    check_for_builtin(void);

void	terminal_initialize(void);
void	terminal_set_color(uint8_t color);
void	terminal_write_buffer(const char* data);
void	terminal_putentryat(char c, uint8_t color, size_t x, size_t y);
void    terminal_backspace(void);

void 	print_welcome_screen(void);

uint8_t vga_entry_color(vga_color fg, vga_color bg);
uint16_t vga_entry(unsigned char uc, uint8_t color);

void    enable_cursor(uint8_t cursor_start, uint8_t cursor_end);
void    update_cursor(bool line_break);
void 	move_cursor_back(void); 
void    update_blinking_cursor(void);

void    scroll_buffer(void);
void    clear_buffer(uint16_t *screen_buffer);

char 	get_char_from_input(unsigned char c);
void	handle_keyboard();

#endif