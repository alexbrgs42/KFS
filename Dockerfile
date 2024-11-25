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

RUN clang --target=i386-unknown-none -c /src/CONF/boot.asm -o boot.o
RUN make -C /src/BUILD

RUN mkdir -p isodir/boot/grub
RUN cp /src/BUILD/kfs.bin isodir/boot/kfs.bin
RUN cp /src/CONF/grub.cfg isodir/boot/grub/grub.cfg
RUN grub-mkrescue -o kfs.iso isodir