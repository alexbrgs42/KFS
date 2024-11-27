#include "../../INCL/libc.h"

void color_change(char *color) {

    if (!strcmp(color, "red")) {
        terminal_set_color(VGA_COLOR_RED);
    }
    else if (!strcmp(color, "blue")) {
        terminal_set_color(VGA_COLOR_BLUE);
    }
    else if (!strcmp(color, "green")) {
        terminal_set_color(VGA_COLOR_GREEN);
    }
    else if (!strcmp(color, "white")) {
        terminal_set_color(VGA_COLOR_WHITE);
    }
    else if (!strcmp(color, "magenta")) {
        terminal_set_color(VGA_COLOR_MAGENTA);
    }
    else if (!strcmp(color, "brown")) {
        terminal_set_color(VGA_COLOR_BROWN);
    }
    else {
        printk(3, "error while parsing argument, available colors are : \n");
        printk(3, "red, blue, green, white, magenta, brown\n");
    }
}