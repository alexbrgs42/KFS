/// @brief Builtin command to reboot the kernel (and thus the terminal)
void reboot(void) {
    __asm__ volatile("jmpw $0xFFFF, $0x0");
}
