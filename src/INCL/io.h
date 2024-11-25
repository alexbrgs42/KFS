#ifndef IO_H
# define IO_H

# include <stddef.h>
# include <stdint.h>
# include <stdbool.h>

void outb(uint16_t port, uint8_t val);

#endif