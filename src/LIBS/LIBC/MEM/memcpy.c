#include "../../../INCL/libc.h"
 
/// @brief      Copies the first n bytes of src into dest, memory areas cannot overlap,
///                 if they do, use memmove instead
/// @param dest Assumed to be large enough to contain src
/// @param src  Assumed to be at least n long
/// @param n
/// @return     dest or NULL
void *memcpy(void *dest, const void *src, size_t n) {

    if (src == NULL) {
        return (NULL);
    }

    unsigned char *d = dest;
    unsigned const char *s = src;

    size_t iter = 0;

    while (iter < n) {

        *(d + iter) =  *(s + iter);
        iter++;
    }

    return (dest);
}
