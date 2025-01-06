#include "../../INCL/builtins.h"
#include "../../INCL/libc.h"

void help(void) {

  printk(0, "Available commands :\n");
  printk(0, "  help   --> Displays informations about available commands\n");
  printk(0, "  color  --> Changes display color of text \n");
  printk(0, "  stack  --> Displays current stack information\n");
  printk(0, "  reboot --> .. it reboots\n");
  printk(0, "  halt   --> basically kills the machine\n");
}
