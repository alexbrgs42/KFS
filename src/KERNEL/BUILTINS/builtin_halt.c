#include "../../INCL/io.h"

/* inb(0x60) reads from the keyboard port */

/// @brief Builtin command to halt (pause) the terminal
void halt(void) {
    while (1) {
        char c = 0;
        if (inb(0x60) != c) {
            c = inb(0x60);
            if (c == 0x1D) { break ; }
        }
    }
}
