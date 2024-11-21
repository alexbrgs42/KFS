FROM debian:latest

RUN apt update && apt upgrade && apt install -y \
    clang \
    mtools \
    make \
    gcc \
    grub2-common \
    xorriso \
    grub-pc-bin 

COPY . .

RUN clang --target=i386-unknown-none -c boot.asm -o boot.o
RUN clang --target=i386-unknown-none -c main.c -o main.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
RUN clang --target=i386-unknown-none -T linker.ld -o kfs.bin -ffreestanding -O2 -nostdlib boot.o main.o

RUN mkdir -p isodir/boot/grub
RUN cp kfs.bin isodir/boot/kfs.bin
RUN cp grub.cfg isodir/boot/grub/grub.cfg
RUN grub-mkrescue -o kfs.iso isodir