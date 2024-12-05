#include "../../INCL/tty.h"
#include "../../INCL/libc.h"

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
    clear_command_buffer();

	print_info_line(1);

    enable_cursor(0x0A, 0x0C);
}

void print_info_line(uint16_t window_num) {

	size_t	tmp = terminal_row;
	terminal_row = VGA_HEIGHT - 1;

	for (uint16_t i = 0; i < VGA_WIDTH - 10; i ++) {
		printk(0, "_");
	}

	printk(0, "/");
	if (window_num == 1) {
		terminal_set_color(VGA_COLOR_GREEN);
		printk(0, "1");
		terminal_set_color(VGA_COLOR_LIGHT_GREY);
	} else {
		printk(0, "1");
	}
	
	printk(0, "/");
	if (window_num == 2) {
		terminal_set_color(VGA_COLOR_GREEN);
		printk(0, "2");
		terminal_set_color(VGA_COLOR_LIGHT_GREY);
	} else {
		printk(0, "2");
	}

	printk(0, "/");
	if (window_num == 3) {
		terminal_set_color(VGA_COLOR_GREEN);
		printk(0, "3");
		terminal_set_color(VGA_COLOR_LIGHT_GREY);
	} else {
		printk(0, "3");
	}
	printk(0, "/___");

	terminal_row = tmp;
	terminal_column = 0;
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

	printk(0, "$>");
}