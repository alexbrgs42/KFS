#include "../../../INCL/libc.h"

/// @brief      Copies the first n bytes of src into dest, memory areas may
/// overlap
/// @param dest Assumed to be large enough to contain src
/// @param src  Assumed to be at least n long
/// @param n
/// @return     dest or NULL
void *memmove(void *dest, const void *src, size_t n) {
    if (src == NULL) {
        return (NULL);
    }

    unsigned char buffer[n];

    memcpy(buffer, src, n);
    memcpy(dest, buffer, n);

    return (dest);
}
