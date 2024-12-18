#include "../../INCL/tty.h"
#include "../../INCL/libc.h"
#include "../../INCL/gdt.h"


static void hex_to_string(uint32_t num, char* str) {
    const char hex_digits[] = "0123456789ABCDEF";
    for (int i = 0; i < 8; i++) {
        str[7 - i] = hex_digits[num & 0xF];
        num >>= 4;
    }
    str[8] = '\0';
}

void print_stack(void) {
    uint32_t* ebp;
    uint32_t* esp;
    char hex[9];

    // Get current stack pointers
    __asm__ volatile("mov %%ebp, %0" : "=r"(ebp));
    __asm__ volatile("mov %%esp, %0" : "=r"(esp));

    // Print header
    printk(0, "\n=== Current Stack Frame ===\n");
    
    // Print base and stack pointers
    printk(0, "Base Pointer (EBP): 0x");
    hex_to_string((uint32_t)ebp, hex);
    printk(0, hex);
    printk(0, "\n");

    printk(0, "Stack Pointer (ESP): 0x");
    hex_to_string((uint32_t)esp, hex);
    printk(0, hex);
    printk(0, "\n\n");

    // Print stack contents
    printk(0, "Stack Contents (ESP to EBP):\n");
    printk(0, "Address     | Value\n");
    printk(0, "-----------+-----------\n");

    uint32_t* current = esp;
    int count = 0;
    
    // Print up to 10 stack entries or until we reach EBP
    while (current <= ebp && count < 10) {
        // Print address
        hex_to_string((uint32_t)current, hex);
        printk(0, hex);
        printk(0, " | ");

        // Print value at address
        hex_to_string(*current, hex);
        printk(0, hex);
        printk(0, "\n");

        current++;
        count++;
    }

    if (current < ebp) {
        printk(0, "...\n");
    }
}