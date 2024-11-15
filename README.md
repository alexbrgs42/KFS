# KFS

Assemble boot.s:
```
    i686-elf-as boot.s -o boot.o
```

Compile kernel.c:
```
    i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
```
IMPORTANT NOTE: the VGA text mode (as well as the BIOS) is deprecated on newer machines, and UEFI only supports pixel buffers. For forward compatibility you might want to start with that. Ask GRUB to set up a framebuffer using appropriate Multiboot flags or call VESA VBE yourself. Unlike VGA text mode, a framebuffer has pixels, so you have to draw each glyph yourself. This means you'll need a different terminal_putchar, and you'll need a font (bitmap images for each character). All Linux distro ships PC Screen Fonts that you can use, and the wiki article has a simple putchar() example. Otherwise everything else described here still stands (you have to keep track of the cursor position, implement line breaks and scrolling etc.) 

Link the kernel:
```
    i686-elf-gcc -T linker.ld -o myos.bin -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc
```

Generate the .iso:
``` 
    mkdir -p isodir/boot/grub
    cp myos.bin isodir/boot/myos.bin
    cp grub.cfg isodir/boot/grub/grub.cfg
    grub-mkrescue -o myos.iso isodir
```