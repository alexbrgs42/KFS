#include "../../INCL/builtins.h"
#include "../../INCL/libc.h"
#include <stdint.h>

uint16_t stack_trace(uint32_t *addresses, size_t max_len);
static void hex_to_string(uint32_t num, char *str);

// Print the return addresses of stack frames (up to MAX_STACK_LEN)
// It is currently impossible to associate these frames with a function name
// as it would require being able to open and read files
// We can only do it outside of the program, see Dockerfile for that

void print_stack() {

  uint32_t addresses[MAX_STACK_LEN];

  // Store addresses in the array and returns how many it found
  uint16_t stack_len = stack_trace(addresses, MAX_STACK_LEN);

  char hex[9];

  printk(0, "-------- STACK FRAMES --------\n");

  for (uint16_t i = 0; i < stack_len; i++) {
    hex_to_string(addresses[i], hex);         // Store the str representation in 'hex'
    printk(0, "stack frame begin: 0x");
    printk(0, hex);
    printk(0, "\n");
  }

  printk(0, "------------------------------\n");
}

static void hex_to_string(uint32_t num, char *str) {
  const char hex_digits[] = "0123456789ABCDEF";
  for (int i = 0; i < 8; i++) {
    str[7 - i] = hex_digits[num & 0xF];
    num >>= 4;
  }
  str[8] = '\0';
}
