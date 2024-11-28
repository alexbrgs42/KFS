#include "../INCL/libc.h"
#include "../INCL/tty.h"


/// @brief              printf-like function that also accepts a log-level
/// @param log_level    How important the message is, 0 will only display the string
/// @param string       String to print
/// @return             0, TODO: 1 for error
int printk(uint16_t log_level, const char *string) {

    switch (log_level) {

        case 1:
            terminal_set_color(VGA_COLOR_RED);
            terminal_write_buffer("CRITICAL ERROR: ");
            terminal_write_buffer(string);
            terminal_set_color(VGA_COLOR_WHITE);
            break ;
        
        case 2:
            terminal_set_color(VGA_COLOR_LIGHT_RED);
            terminal_write_buffer("ERROR: ");
            terminal_write_buffer(string);
            terminal_set_color(VGA_COLOR_WHITE);
            break ;

        case 3:
            terminal_set_color(VGA_COLOR_LIGHT_MAGENTA);
            terminal_write_buffer("WARNING: ");
            terminal_write_buffer(string);
            terminal_set_color(VGA_COLOR_WHITE);
            break ;

        case 4:
            terminal_set_color(VGA_COLOR_CYAN);
            terminal_write_buffer("INFO: ");
            terminal_write_buffer(string);
            terminal_set_color(VGA_COLOR_WHITE);
            break ;

        default:
            terminal_write_buffer(string);
    }
    return (0);
}
