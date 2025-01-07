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

// #include "../INCL/cpu.h"

// void test_cpu_mode(void) {
//     if (check_protected_mode()) {
//         printk(0, "CPU is in protected mode\n");
//     } else {
//         printk(0, "CPU is in real mode\n");
//     }
// }

#endif