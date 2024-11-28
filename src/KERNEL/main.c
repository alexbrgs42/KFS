#include "../INCL/tty.h"
#include "../INCL/libc.h"

size_t		terminal_row;
size_t		terminal_column;
uint8_t		terminal_color;
uint16_t*	terminal_buffer;

void print_welcome_screen(void);

void kernel_main(void) 
{
	/* Initialize terminal interface */
	terminal_initialize();

	/* Newline support is left as an exercise. */
	print_welcome_screen();
	handle_keyboard();
}

/// @brief                  Displays mandatory 42 mention
void print_welcome_screen(void) {

	terminal_set_color(VGA_COLOR_CYAN);

	printk(0, "/* ************************************************************************* */\n");
	printk(0, "/*                                                       :::      ::::::::   */\n");
	printk(0, "/*   Welcome to KFS !                                  :+:      :+:    :+:   */\n");
	printk(0, "/*                                                   +:+ +:+         +:+     */\n");
	printk(0, "/*   By: iaschnei & abourgeo                       +#+  +:+       +#+        */\n");
	printk(0, "/*                                               +#+#+#+#+#+   +#+           */\n");
	printk(0, "/*   Use 'help' for commands                          #+#    #+#             */\n");
	printk(0, "/*                                                   ###   ########.fr       */\n");
	printk(0, "/* ************************************************************************* */\n");


	terminal_set_color(VGA_COLOR_WHITE);
}