# KFS

The goal of this project was to create a minimalistic kernel from scratch. We implemented a simple shell-like interface that accepts basic keyboard input and with a few builtin commands. You can also switch between 3 independant terminals, acting like different 'windows'.

There is no use for it as it is and would still require A LOT of work to make it even remotely close to a practical OS, please do not try to use it on physical hardware.

Made in collaboration with [iaschnei](https://github.com/iaschnei) and with the awesome documentation of [OsDev](https://wiki.osdev.org/Expanded_Main_Page).

### Dependencies:
You will need kvm, QEMU and docker installed on a linux system.

### Usage:
```sh
make && make run
```
If the default `make run` does not work, you can do it yourself with `qemu-system-i386 -cdrom kfs.iso`

![image](https://github.com/user-attachments/assets/89653c5e-0ef3-4782-80c8-9339b07fe4b8)
