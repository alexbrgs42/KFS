#include "../../INCL/libc.h"
#include "../../INCL/tty.h"

void clear_screen(void) {
    terminal_empty_screen();
    clear_buffer(terminal_windows[current_window - 1]);
    clear_command_buffer();
    print_info_line();

    if (current_window == 1) {
        print_welcome_screen(VGA_COLOR_CYAN);
    } else if (current_window == 2) {
        print_welcome_screen(VGA_COLOR_LIGHT_RED);
    } else {
        print_welcome_screen(VGA_COLOR_GREEN);
    }
}
