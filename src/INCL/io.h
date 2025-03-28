#ifndef IO_H
#define IO_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

void outb(uint16_t port, uint8_t val);
uint8_t inb(uint16_t port);

#endif
