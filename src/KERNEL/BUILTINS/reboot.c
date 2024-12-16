void reboot(void) { __asm__ volatile("jmpw $0xFFFF, $0x0"); }
