#include "../../INCL/libc.h"
#include "../../INCL/builtins.h"

void help(void) {

    printk(0, "Available commands :\n");
    printk(0, "  help  --> Displays informations about available commands\n");
    printk(0, "  color --> Changes display color of text \n");
}