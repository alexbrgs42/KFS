#include "../../INCL/libc.h"
#include "../../INCL/gdt.h"

static void hex_to_string(uint32_t num, char *str);

extern struct gdt_entry_struct gdt_entries[7];

void  print_gdt() {

    printk(0, "--------- Global Descriptor Table ---------\n");
    printk(0, " limit | base_low | base_mid | access | flags | base_high\n"); 

    char hex[9]; 
    for (int i = 0; i < 7; i ++) {
        hex_to_string(gdt_entries[i].limit, hex);
        printk(0, hex);
        printk(0, " ");
        hex_to_string(gdt_entries[i].base_low, hex);
        printk(0, hex);
        printk(0, " ");
        hex_to_string(gdt_entries[i].base_middle, hex);
        printk(0, hex);
        printk(0, " ");
        hex_to_string(gdt_entries[i].access, hex);
        printk(0, hex);
        printk(0, " ");
        hex_to_string(gdt_entries[i].flags, hex);
        printk(0, hex);
        printk(0, " ");
        hex_to_string(gdt_entries[i].base_high, hex);
        printk(0, hex);
        printk(0, "\n");
    }
    printk(0, "-------------------------------------------\n");
}

static void hex_to_string(uint32_t num, char *str) {
    const char hex_digits[] = "0123456789ABCDEF";
    for (int i = 0; i < 8; i++) {
        str[7 - i] = hex_digits[num & 0xF];
        num >>= 4;
    }
    str[8] = '\0';
}
