#include "../../INCL/io.h"
#include "../../INCL/keyboard.h"
#include "../../INCL/libc.h"
#include "../../INCL/tty.h"
#include "../../INCL/builtins.h"

char get_char_from_input(char c) { return (scan_codes[(uint16_t)c]); }

void terminal_putinput(char c) {
  char a = get_char_from_input(c);
  terminal_write_buffer(&a);
}

bool ctrl_pressed = false;

void handle_keyboard() {
  char c = 0;
  do {
    if (inb(0x60) != c) // Read from the keyboard port
    {
      c = inb(0x60);

      // Ignore Shift, Ctrl, Alt, and other non-printable keys
      if (c == KEYCODE_SHIFT_L || c == KEYCODE_SHIFT_R || c == KEYCODE_CTRL_L ||
          c == KEYCODE_CTRL_R || c == KEYCODE_ALT_L || c == KEYCODE_ALT_R ||
          c == KEYCODE_CAPS_LOCK) {
        continue;
      }

      if (c == KEYCODE_BACKSPACE) {
        terminal_backspace(); // Erase last character and move cursor back
        remove_from_command_buffer(1);
      } else if (c == KEYCODE_ENTER) {
        printk(0, "\n");
        check_for_builtin();
        clear_command_buffer();
        printk(0, "$>");
      } else if (c == KEYCODE_1) {
        switch_window(1);
      } else if (c == KEYCODE_2) {
        switch_window(2);
      } else if (c == KEYCODE_3) {
        switch_window(3);
      // } else if (c == KEYCODE_4) {
      //   test_cpu_mode();
      } else if (c > 0) {
        terminal_putinput(c & 0x7F);
        append_to_command_buffer(c & 0x7F);
      }
    }
  } while (c != 1); // 1 = ESCAPE

  reboot();
}
