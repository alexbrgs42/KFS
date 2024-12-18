global enter_protected

enter_protected:

    ; Set protection enable bit in CR0
    mov eax, cr0
    or eax, 1
    mov cr0, eax
    
    ; Far jump to flush CPU pipeline
    jmp 0x08:protected_mode

protected_mode:
    ; Load segment registers with kernel data segment
    mov ax, 0x10    ; 0x10 is the kernel data segment
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    
    ret