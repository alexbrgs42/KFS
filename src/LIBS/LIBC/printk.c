#include "../INCL/libc.h"
#include "../INCL/tty.h"

int printk(uint16_t log_level, const char *string) {

    switch (log_level) {

        case 1:
            terminal_write_buffer("CRITICAL ERROR: ");
            terminal_write_buffer(string);
            break ;
        
        case 2:
            terminal_write_buffer("ERROR: ");
            terminal_write_buffer(string);
            break ;

        case 3:
            terminal_write_buffer("WARNING: ");
            terminal_write_buffer(string);
            break ;

        case 4:
            terminal_write_buffer("INFO: ");
            terminal_write_buffer(string);
            break ;

        default:
            terminal_write_buffer(string);
    }

    terminal_write_buffer("\n");
    return (0);
}
