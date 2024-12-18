#ifndef CPU_H
#define CPU_H

// Returns 1 if in protected mode, 0 if in real mode
static inline int check_protected_mode(void) {
    int mode;
    __asm__ volatile(
        "movl %%cr0, %%eax\n\t"
        "andl $1, %%eax"
        : "=a"(mode)  // Output to mode variable
        :             // No inputs
        : "cc"        // Clobbers condition codes
    );
    return mode;
}

#endif