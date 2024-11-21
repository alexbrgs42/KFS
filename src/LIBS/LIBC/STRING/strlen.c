#include "../../../INCL/libc.h"

/// @brief      
/// @param str  It is assumed that str terminates by a /0
/// @return     
size_t strlen(const char *str) {

    if (str == NULL) {
        return (0);
    }

    size_t i = 0;

    while (str[i]) {
        i++;
    }

    return (i);
}