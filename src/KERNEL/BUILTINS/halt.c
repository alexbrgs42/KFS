#include "../../INCL/libc.h"

void halt(void) {

    while (1) {
        char c = 0;
        if (inb(0x60) != c) // Read from the keyboard port
        {
          c = inb(0x60);

          if (c == 0x1D) {
            break ;
          }
        }
    }
}