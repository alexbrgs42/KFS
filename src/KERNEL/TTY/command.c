#include "../../INCL/libc.h"
#include "../../INCL/builtins.h"
#include "../../INCL/tty.h"

void    clear_command_buffer(void) {

    for (int i = 0; i < 1024; i++) {
        command_buffer[i] = 0;
    }
}

/// @brief      Adds c at the end of the command_buffer
/// @param c    Any char written to the terminal
void    append_to_command_buffer(char c) {

    char a = get_char_from_input(c);

    int i = 0;

    while (i < 1023 && command_buffer[i] != 0) {
        i++;
    }

    // command_buffer is limited to 1024 char for now
    if (i == 1023) {
        return ;
    }

    command_buffer[i] = a;
}

/// @brief          Remove count character(s) from command_buffer
/// @param count    
void    remove_from_command_buffer(uint16_t count) {

    int i = 0;

    while (i < 1024 && command_buffer[i] != 0) {
        i++;
    }

    for (int j = 0; j < count; j ++) {
        i--;
        command_buffer[i] = 0;
    }
}

/// @brief  Will attempt to match command_buffer and a builtin, if it exists, execute it
// TODO : take arguments into account
void    check_for_builtin(void) {

    if (strcmp(command_buffer, "hello") == 0) {
        printk(0, "Hello there, it's your kernel\n");
    }
    else if (strcmp(command_buffer, "help") == 0) {
        help();
    }
}