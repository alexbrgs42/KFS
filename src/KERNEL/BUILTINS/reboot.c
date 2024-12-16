
//TODO: Only works in real mode, protected mode reboot needs more work
void reboot(void) { 
  __asm__ volatile("jmpw $0xFFFF, $0x0");
}
