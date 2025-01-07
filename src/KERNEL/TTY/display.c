#include "../../INCL/libc.h"
#include "../../INCL/tty.h"

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y) {
  const size_t index = y * VGA_WIDTH + x;
  terminal_buffer[index] = vga_entry(c, color);

  // Also save in the correct window's memory
  terminal_windows[current_window - 1][index] = vga_entry(c, color);
}

void terminal_putchar(char c) {
  uint16_t index = current_window - 1;

  if (c == '\n') {
    update_cursor(true);
  } else {
    terminal_putentryat(c, terminal_color[current_window - 1], terminal_column[index],
                        terminal_row[index]);
    update_cursor(false);
  }
}

void terminal_write_buffer(const char *data) {
  size_t size = strlen(data);
  for (size_t i = 0; i < size; i++) {
    terminal_putchar(data[i]);
  }
}

/// @brief    Erase the last character (replace by space)
void terminal_backspace(void) {
    if (terminal_is_empty_command() == false) {
      move_cursor_back();
      terminal_putchar(' ');
      move_cursor_back();
    }
}

bool terminal_is_empty_command(void) {
    uint16_t index = current_window - 1;
    uint16_t pos = terminal_row[index] * VGA_WIDTH + terminal_column[index];
  
    char cmd[3];
    cmd[0] = terminal_buffer[pos - 2];
    cmd[1] = terminal_buffer[pos - 1];
    cmd[2] = '\0';
    if (strcmp(cmd, "$>") == 0)
      return true;
    return false;
}

void terminal_empty_screen(void) {
    reset_cursor();
    for (uint64_t i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
        printk(0, " ");
    }
    reset_cursor();
}
