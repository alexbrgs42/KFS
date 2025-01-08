#include "../INCL/gdt.h"

extern void gdt_flush(struct gdt_ptr_struct *);

struct gdt_entry_struct gdt_entries[7];
struct gdt_ptr_struct gdt_ptr;

/// @brief Sets each entries of our gdt and flushes it.
// Each entry has a specific structure.
// The base defines where the segment begins
void init_gdt(void) {
	gdt_ptr.limit = (sizeof(struct gdt_entry_struct) * 7) - 1;
	gdt_ptr.base = (unsigned int) &gdt_entries;

	set_gdt_gate(0, 0, 0, 0, 0); // null segment : entry 0 must be set to 0 by convention
	
	set_gdt_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // kcode
	set_gdt_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // kdata
	set_gdt_gate(3, 0, 0xFFFFFFFF, 0x97, 0xCF); // kstack

	set_gdt_gate(4, 0, 0xFFFFFFFF, 0xFA, 0xCF); // ucode
	set_gdt_gate(5, 0, 0xFFFFFFFF, 0xF2, 0xCF); // udata
	set_gdt_gate(6, 0, 0xFFFFFFFF, 0xF7, 0xCF); // ustack

	gdt_flush(&gdt_ptr);
}

/// @brief Sets each field of the structure of a gdt entry.
/// @param num The number of the entry inside of our gdt table
/// @param base The base defines where the segment begins (devided into 3 pieces inside of the structure)
/// @param limit The limit is a 20 bit value the represents the largest addressable unit of memory (used for kB pages mode)
/// @param access The access byte defines the accessibilty, privilege, ... in a particular order and set of rules
//  7 : P   -> Present bit that tells if it is a vide segment if set to 1
//6,5 : DPL -> Descriptor privilege level field (CPU privilege level of the segment)
//			   0 = highest privilege (kernel) and 3 = lowest privilege (user applications)
//  4 : S   -> Descriptor type bit. 0 = system segment or 1 = code or data segment
//  3 : E   -> Executable bit. 0 = data segment or 1 = code segment (which can be executed from)
//  2 : DC  -> Direction bit. For data selector: tells if it growns up or down
//             Confirming bit. For code selector: 0 = executable only from the ring set in DPL
//                                             or 1 = executable for an equal or lower privilege
//  1 : RW  -> Readable bit. For code segments: 0 = read access not allowed or 1 = read access allowed
//             Writable bit. For data segments: 0 = write access not allowed or 1 = write access allowed
//  0 : A   -> Accessed bit. Should be set to 1.
/// @param gran Granularity indicates scale of the size of the limit value. 0 = bytes blocks or 1 = 4 KiB blocks
void set_gdt_gate(uint32_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran) {
	gdt_entries[num].base_low = (base & 0xFFFF);
	gdt_entries[num].base_middle = (base >> 16) & 0xFF;
	gdt_entries[num].base_high = (base >> 24) & 0xFF;

	gdt_entries[num].limit = (limit & 0xFFFF);
	gdt_entries[num].flags = (limit >> 16) & 0x0F;
	gdt_entries[num].flags |= (gran & 0xF0);

	gdt_entries[num].access = access;
}
