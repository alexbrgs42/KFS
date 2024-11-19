#ifndef _STDLIB_H
#define _STDLIB_H 1

#include <sys/cdefs.h>

// GCC keyword to indicate that the following function will never return
__attribute__((__noreturn__))
void abort(void);

#endif
