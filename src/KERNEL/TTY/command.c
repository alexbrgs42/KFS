#include "../../INCL/builtins.h"
#include "../../INCL/libc.h"
#include "../../INCL/tty.h"

void clear_command_buffer(void) {

  for (int i = 0; i < 1024; i++) {
    command_buffer[current_window - 1][i] = 0;
  }
}

/// @brief      Adds c at the end of the command_buffer
/// @param c    Any char written to the terminal
void append_to_command_buffer(char c) {

  char a = get_char_from_input(c);

  int i = 0;

  while (i < 1023 && command_buffer[current_window - 1][i] != 0) {
    i++;
  }

  // command_buffer is limited to 1024 char for now
  if (i == 1023) {
    return;
  }

  command_buffer[current_window - 1][i] = a;
}

/// @brief          Remove count character(s) from command_buffer
/// @param count
void remove_from_command_buffer(uint16_t count) {

  int i = 0;

  while (i < 1024 && command_buffer[current_window - 1][i] != 0) {
    i++;
  }

  for (int j = 0; j < count; j++) {
    i--;
    command_buffer[current_window - 1][i] = 0;
  }
}

/// @brief Make sure our buffers are empty before calling split
void clear_command_and_args(void) {

  for (int i = 0; i < 512; i++) {
    split_command[i] = 0;
  }

  for (int i = 0; i < 256; i++) {
    split_arg1[i] = 0;
  }

  for (int i = 0; i < 256; i++) {
    split_arg2[i] = 0;
  }
}

/// @brief Splits the command and its arguments into global variables
// TODO : Once malloc is here, change split to a malloc
void split_command_and_args(void) {

  int i = 0;

  while (i < 512) {
    if (command_buffer[current_window - 1][i] == 0 ||
        command_buffer[current_window - 1][i] == ' ') {
      break;
    }
    split_command[i] = command_buffer[current_window - 1][i];
    i++;
  }

  i++;

  for (int j = 0; j < 256; j++) {
    if (command_buffer[current_window - 1][i] == 0 ||
        command_buffer[current_window - 1][i] == ' ') {
      break;
    }
    split_arg1[j] = command_buffer[current_window - 1][i];
    i++;
  }

  i++;

  for (int k = 0; k < 256; k++) {
    if (command_buffer[current_window - 1][i] == 0 ||
        command_buffer[current_window - 1][i] == ' ') {
      break;
    }
    split_arg2[k] = command_buffer[current_window - 1][i];
    i++;
  }
}

/// @brief  Will attempt to match command_buffer and a builtin, if it exists,
/// execute it
void check_for_builtin(void) {

  clear_command_and_args();
  split_command_and_args();

  if (strcmp(split_command, "hello") == 0) {
    printk(0, "Hello there, it's your kernel\n");
  } else if (strcmp(split_command, "help") == 0) {
    help();
  } else if (strcmp(split_command, "color") == 0) {
    color_change(split_arg1);
  } else if (strcmp(split_command, "reboot") == 0) {
    reboot();
  } else if (strcmp(split_command, "halt") == 0) {
    halt();
  } else if (strcmp(split_command, "stack") == 0) {
    print_stack();
}
}

