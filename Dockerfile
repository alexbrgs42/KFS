FROM debian:latest

# Update package index and install necessary packages
RUN apt-get update && apt-get install -y \
    build-essential \
    bison \
    flex \
    libgmp3-dev \
    libmpc-dev \
    libmpfr-dev \
    texinfo \ 
    wget \
    grub2-common \
    xorriso

RUN mkdir /src && cd /src
RUN wget https://ftp.gnu.org/gnu/binutils/binutils-2.43.1.tar.xz
RUN tar -xvf binutils-2.43.1.tar.xz
RUN wget https://ftp.gnu.org/gnu/gcc/gcc-14.2.0/gcc-14.2.0.tar.gz
RUN tar -xvf gcc-14.2.0.tar.gz

RUN mkdir -p /usr/local/cross

# Set environment variables
ENV PREFIX="/usr/local/cross"
ENV TARGET=i386-elf
ENV PATH="$PREFIX/bin:$PATH"

RUN mkdir build-binutils && cd build-binutils
RUN ../binutils-2.43.1/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
RUN make && make install

RUN cd /src
RUN unset CFLAGS && unset LDFLAGS
RUN make distclean || true
RUN mkdir build-gcc && cd build-gcc
RUN ../gcc-14.2.0/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --disable-bootstrap --enable-languages=c,c++ --without-headers
RUN make all-gcc
RUN make all-target-libgcc
RUN make install-gcc
RUN make install-target-libgcc

ENV PATH="/usr/local/cross/bin:$PATH"

# Copy the necessary files into the container
COPY . .

# Ensure the script is executable
RUN chmod +x /build/clean.sh
RUN chmod +x /build/headers.sh
RUN chmod +x /build/iso.sh

# Specify the default command to run
CMD ["/bin/bash", "-c", "./build/clean.sh && ./build/headers.sh && ./build/iso.sh"]