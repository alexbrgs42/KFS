#include "../../INCL/builtins.h"
#include "../../INCL/libc.h"

/// @brief Builtin command to print the name of each builtin and a small description
void help(void) {
    printk(0, "Available commands :\n");
    printk(0, "  help   --> Displays informations about available commands\n");
    printk(0, "  color  --> Changes display color of text \n");
    printk(0, "  stack  --> Displays current stack information\n");
    printk(0, "  gdt    --> Displays gdt settings\n");
    printk(0, "  reboot --> .. it reboots\n");
    printk(0, "  halt   --> stops the program, ctrl to resume\n");
    printk(0, "  clear  --> Clears the kterminal screen\n");
}
