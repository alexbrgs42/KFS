#include "../../INCL/tty.h"

uint8_t vga_entry_color(vga_color fg, vga_color bg) { return (fg | (bg << 4)); }

/// @brief Text mode memory takes 2 bytes for every "character" on screen. One
/// is the ASCII code byte,
//			the other is the attribute byte (it carries the
// foreground color in its lowest 4 bits 			and the
// background color in its highest 3 bits, 			the
// interpretation of bit #7 depends on how you or the BIOS configured the
// hardware).
/// @param uc The unsigned character to display.
/// @param color The color of the character (foreground) and iths background.
/// @return Returns 2 bytes representing the character for text mode memory.
uint16_t vga_entry(unsigned char uc, uint8_t color) {
  return ((uint16_t)uc | ((uint16_t)color << 8));
}
