FROM debian:latest

RUN apt update && apt upgrade -y && apt install -y \
    clang \
    mtools \
    make \
    gcc \
    grub2-common \
    xorriso \
    nasm \
    grub-pc-bin 

COPY . .

RUN make -C /src/BUILD

RUN mkdir -p isodir/boot/grub
RUN cp /src/BUILD/kfs.bin isodir/boot/kfs.bin
# Include those to list the functions and their addresses
# Also include llvm in the package list and remove optimisation flag ( -O0) in the Makefile
#RUN llvm-objdump -d /src/BUILD/kfs.bin
#RUN llvm-nm /src/BUILD/kfs.bin
RUN cp /src/CONF/grub.cfg isodir/boot/grub/grub.cfg
RUN grub-mkrescue -o kfs.iso isodir
