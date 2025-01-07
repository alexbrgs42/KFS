#include "../../INCL/tty.h"

void terminal_set_color(uint8_t color) { terminal_color[current_window - 1] = color; }
