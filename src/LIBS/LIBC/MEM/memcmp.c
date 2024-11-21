#include "../../../INCL/libc.h"

/// @brief      Compares the first n bytes of s1 and s2
/// @param s1   Assumed to be at least n long, can contain any number of /0
/// @param s2   Assumed to be at least n long, can contain any number of /0
/// @param n    
/// @return     0 if equal, 1 if s1 greater, -1 if s2 greater
uint16_t memcmp(const void *s1, const void *s2, size_t n) {

    if ((s1 == NULL && s2 == NULL) || n == 0) {
        return (0);
    }
    else if (s2 == NULL) {
        return (1);
    }
    else if (s1 == NULL) {
        return (-1);
    }

    unsigned const char *c1 = s1;
    unsigned const char *c2 = s2;

    size_t iter = 0;

    while (iter < n) {
        if (*(c1 + iter) != *(c2 + iter)) {
            break ;
        }
        iter++;
    }

    if (*(c1 + iter) > *(c2 + iter)) {
        return (1);
    }
    else if (*(c2 + iter) > *(c1 + iter)) {
        return (-1);
    }

    return (0);
}