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

    enable_cursor(0x0A, 0x0C);
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