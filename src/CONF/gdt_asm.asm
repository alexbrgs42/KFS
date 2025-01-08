global gdt_flush

gdt_flush:
    mov eax, [esp+4]
    lgdt [eax]
    mov eax, 0x10       ; 0x10 is the offset to hat gdt
    mov ds, ax          ; data segment 16 bit register
    mov fs, ax          ; general purpose segment 16 bit register
    mov gs, ax          ; general purpose segment 16 bit register
    mov ss, ax          ; stack segment 16 bit register
    jmp 0x08:.flush     ; register for code segment. We're doing a far jump based on the offset
.flush:
    ret

; Segment registers (cs, ds, es, fs, gs, ss) are designed to store
; segment selectors (indexes to the GDT) while they are in use.

; Ex: a memory access such as [ebx] will be relative to the 
; segment base described by ds (equivalent to [ds:ebx])

; In real mode, this instruction will access the memorya address ds * 16 + ebx
; In protected mode, the base address is taken from the GDT
; and the offset ebx is added.