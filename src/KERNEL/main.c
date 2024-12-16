#include "../INCL/libc.h"
#include "../INCL/tty.h"

size_t terminal_row[3];
size_t terminal_column[3];
uint8_t terminal_color;
uint16_t *terminal_buffer;
uint16_t current_window;

uint16_t terminal_windows[3][2000];

void kernel_main(void) {
  /* Initialize terminal interface */
  terminal_initialize();

  handle_keyboard();
}
