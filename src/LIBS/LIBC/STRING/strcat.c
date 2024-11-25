#include "../../../INCL/libc.h"

/// @brief      Concatenates two string into a previously allocated larger buffer
/// @param dest Assumed to be large enough to contain s1 and s2
/// @param s1   Assumed to be terminated by /0
/// @param s2   Assumed to be terminated by /0
/// @return     The destination buffer
char *strcat(char *dest, const char *s1, const char *s2) {

    if (s1 == NULL || s2 == NULL) {
        return (NULL);
    }

    uint16_t s1_iter = 0;

    while (s1[s1_iter]) {
        dest[s1_iter] = s1[s1_iter];
        s1_iter++;
    }

    uint16_t s2_iter = 0;

    while (s2[s2_iter]) {
        dest[s1_iter + s2_iter] = s2[s2_iter];
        s2_iter++;
    }

    dest[s1_iter + s2_iter] = 0;

    return (dest);
}