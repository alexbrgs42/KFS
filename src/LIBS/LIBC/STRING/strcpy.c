#include "../../../INCL/libc.h"

/// @brief      Copies src into a previously allocated buffer dest
/// @param dest Assumed to be large enough to contain src
/// @param src  Assumed to be terminated by /0
/// @return     dest or NULL
char    *strcpy(char *dest, const char *src) {

    if (src == NULL) {
        return (NULL);
    }

    uint16_t iter = 0;

    while (src[iter] != 0) {
        dest[iter] = src[iter];
        iter++;
    }
    dest[iter] = src[iter];

    return (dest);
}