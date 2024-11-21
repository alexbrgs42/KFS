#include "../../../INCL/libc.h"

/// @brief      Compares two buffers
/// @param s1   Assumed to be terminated by /0, null is accepted 
/// @param s2   Assumed to be terminated by /0, null is accepted
/// @return     0 if equal, 1 if s1 greater, -1 if s2 greater
uint16_t    strcmp(const char *s1, const char *s2) {
    
    if (s1 == NULL && s2 == NULL) {
        return (0);
    }
    else if (s2 == NULL) {
        return (1);
    }
    else if (s1 == NULL) {
        return (-1);
    }

    uint16_t iter = 0;

    while (s1[iter] && s2[iter]) {
        if (s1[iter] != s2[iter]) {
            break ;
        }
        iter++;
    }

    if (s1[iter] > s2[iter]) {
        return (1);
    }
    else if (s1[iter] < s2[iter]) {
        return (-1);
    }

    return (0);
}