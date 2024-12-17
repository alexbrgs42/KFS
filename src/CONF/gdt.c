#include "../INCL/gdt.h"

extern void gdt_flush(struct gdt_ptr_struct *);

struct gdt_entry_struct gdt_entries[7];
struct gdt_ptr_struct gdt_ptr;

void init_gdt() {
	gdt_ptr.limit = (sizeof(struct gdt_entry_struct) * 7) - 1;
	gdt_ptr.base = (unsigned int) &gdt_entries;

	set_gdt_gate(0, 0, 0, 0, 0); // entry 0 must be set to 0 by convention
	
	set_gdt_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // kcode
	set_gdt_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // kdata
	set_gdt_gate(3, 0, 0xFFFFFFFF, 0x97, 0xCF); // kstack

	set_gdt_gate(4, 0, 0xFFFFFFFF, 0xFA, 0xCF); // ucode
	set_gdt_gate(5, 0, 0xFFFFFFFF, 0xF2, 0xCF); // udata
	set_gdt_gate(6, 0, 0xFFFFFFFF, 0xF7, 0xCF); // ustack

	gdt_flush(&gdt_ptr);
}

void set_gdt_gate(uint32_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran) {
	gdt_entries[num].base_low = (base & 0xFFFF);
	gdt_entries[num].base_middle = (base >> 16) & 0xFF;
	gdt_entries[num].base_high = (base >> 24) & 0xFF;

	gdt_entries[num].limit = (limit & 0xFFFF);
	gdt_entries[num].flags = (limit >> 16) & 0x0F;
	gdt_entries[num].flags |= (gran & 0xF0);

	gdt_entries[num].access = access;
}
