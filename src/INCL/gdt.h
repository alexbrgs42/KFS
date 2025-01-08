#ifndef GDT_H
# define GDT_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

struct gdt_entry_struct {
	uint16_t limit;		   // largest addressable unit of memory
	uint16_t base_low;	   // begin of the segment
	uint8_t base_middle;
	uint8_t access;		   // privilege, segment type, ...
	uint8_t flags;		   // granularity, size flag and long mode code flage
	uint8_t base_high;
} __attribute__((packed)); // makes sure the memory is stored the exact same way we defined it

struct gdt_ptr_struct {
	uint16_t limit;
	unsigned int base;
} __attribute((packed));

void init_gdt(void);
void set_gdt_gate(uint32_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran);

void enter_protected(void);

#endif
