#include "../../INCL/tty.h"
#include "../../INCL/libc.h"

/* x86 Real Mode Memory Map : 0x000B8000 - 0x000BFFFF - Color Video Memory */

/// @brief Initializes the terminal by initializing its associated global variables
// 			and displaying the space char for every characters to display an empty terminal.
/// @param  None
void terminal_initialize(void)
{

	terminal_row[0] = 0;
	terminal_row[1] = 0;
	terminal_row[2] = 0;
	terminal_column[0] = 0;
	terminal_column[1] = 0;
	terminal_column[2] = 0;

	terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	terminal_buffer = (uint16_t *) 0xB8000;

	current_window = 1;

	clear_and_prepare_buffers();

    clear_command_buffer();

    enable_cursor(0x0A, 0x0C);
}

void clear_and_prepare_buffers(void) {

	// Make sure our buffers memory is clear
	clear_buffer(terminal_buffer);
    clear_buffer(terminal_windows[0]);
	clear_buffer(terminal_windows[1]);
	clear_buffer(terminal_windows[2]);
	
	// For each window, clear the command buffer and print the info line and the prompt
	switch_window(2);
	clear_command_buffer();
	print_info_line();
	printk(0, "$>");

	switch_window(3);
	clear_command_buffer();
	print_info_line();
	printk(0, "$>");

	switch_window(1);
	clear_command_buffer();
	print_info_line();
	print_welcome_screen();
	printk(0, "$>");
}

/// @brief Prints the info line at the bottom of the screen indicating which window we're on
void print_info_line(void) {

    uint16_t index = current_window - 1;   	

	size_t	row_tmp = terminal_row[index];
	size_t	col_tmp = terminal_column[index];
	terminal_row[index] = VGA_HEIGHT - 1;
	terminal_column[index] = 0;

	terminal_set_color(VGA_COLOR_LIGHT_GREY);
	for (uint16_t i = 0; i < VGA_WIDTH - 10; i ++) {
		printk(0, "_");
	}

	printk(0, "/");
	if (current_window == 1) {
		terminal_set_color(VGA_COLOR_GREEN);
		printk(0, "1");
		terminal_set_color(VGA_COLOR_LIGHT_GREY);
	} else {
		printk(0, "1");
	}
	
	printk(0, "/");
	if (current_window == 2) {
		terminal_set_color(VGA_COLOR_GREEN);
		printk(0, "2");
		terminal_set_color(VGA_COLOR_LIGHT_GREY);
	} else {
		printk(0, "2");
	}

	printk(0, "/");
	if (current_window == 3) {
		terminal_set_color(VGA_COLOR_GREEN);
		printk(0, "3");
		terminal_set_color(VGA_COLOR_LIGHT_GREY);
	} else {
		printk(0, "3");
	}
	printk(0, "/___");

	terminal_row[index] = row_tmp;
	terminal_column[index] = col_tmp;

	terminal_set_color(VGA_COLOR_WHITE);
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