# ---------------------------------------------------------------------------- #

KERNEL_SRCS	=	../KERNEL/main.c \
				../KERNEL/TTY/color.c ../KERNEL/TTY/display.c ../KERNEL/TTY/init.c \
				../KERNEL/TTY/vga.c ../KERNEL/TTY/cursor.c ../KERNEL/TTY/windows.c \
				../KERNEL/TTY/command.c \
				../KERNEL/KEYBOARD/input.c \
				../KERNEL/BUILTINS/help.c ../KERNEL/BUILTINS/color_change.c \
				../KERNEL/BUILTINS/reboot.c ../KERNEL/BUILTINS/halt.c \
				../KERNEL/BUILTINS/print_stack.c ../KERNEL/BUILTINS/clear.c

# ---------------------------------------------------------------------------- #

LIBS_SRCS	=	../LIBS/LIBC/printk.c \
				../LIBS/LIBC/STRING/strcat.c ../LIBS/LIBC/STRING/strcmp.c ../LIBS/LIBC/STRING/strcpy.c ../LIBS/LIBC/STRING/strlen.c \
				../LIBS/LIBC/MEM/memcmp.c ../LIBS/LIBC/MEM/memcpy.c ../LIBS/LIBC/MEM/memmove.c \
				../LIBS/IO/outb.c ../LIBS/IO/inb.c

# ---------------------------------------------------------------------------- #

C_BUILD_SRCS = ../CONF/gdt.c

# ---------------------------------------------------------------------------- #

ASM_SRCS =  ../CONF/boot.asm  ../CONF/protected_mode.asm ../CONF/gdt_asm.asm ../KERNEL/BUILTINS/stack_trace.asm

# ---------------------------------------------------------------------------- #

KERNEL_OBJS	=	$(KERNEL_SRCS:.c=.o)

LIBS_OBJS	=	$(LIBS_SRCS:.c=.o)

C_BUILD_OBJS	=	$(C_BUILD_SRCS:.c=.o)

ASM_OBJS	=	$(ASM_SRCS:.asm=.o) 

# ---------------------------------------------------------------------------- #

CLANG		=	clang

INCL		=	../INCL

NAME		=	kfs.bin

TARGET		=	--target=i386-unknown-none
FLAGS		=	-std=gnu99 -O2 -ffreestanding -Wall -Wextra -fno-builtin -fno-exceptions -fno-stack-protector -nostdlib -nodefaultlibs -g

COLOR_GREEN	=	\033[1;32m
COLOR_RED	=	\033[1;31m
COLOR_BLUE	=	\033[3;36m
COLOR_PURP	=	\033[1;35m
COLOR_END	=	\033[0m

# ---------------------------------------------------------------------------- #

%.o: %.c
	@$(CLANG) $(TARGET) $(FLAGS) -I $(INCL) -c $< -o $@
	@echo "$(COLOR_BLUE) || Compiling ($<)...$(COLOR_END)"

%.o: %.asm
	@$(CLANG) $(TARGET) -c ../CONF/boot.asm -o ../CONF/boot.o
	nasm -f elf32 ../CONF/gdt_asm.asm -o ../CONF/gdt_asm.o
	nasm -f elf32 ../CONF/protected_mode.asm -o ../CONF/protected_mode.o
	nasm -f elf32 ../KERNEL/BUILTINS/stack_trace.asm -o ../KERNEL/BUILTINS/stack_trace.o
	@echo "$(COLOR_BLUE) || Compiling ($<)...$(COLOR_END)"

all: $(NAME)

$(NAME): $(KERNEL_OBJS) $(LIBS_OBJS) $(C_BUILD_OBJS) $(ASM_OBJS)
	@$(CLANG) $(TARGET) -T ../CONF/linker.ld -I $(INCL) -o $(NAME) -ffreestanding -O2 -nostdlib $(ASM_OBJS) $(LIBS_OBJS) $(C_BUILD_OBJS) $(KERNEL_OBJS) 
	@echo "$(COLOR_GREEN) || Done !$(COLOR_END)"

# ---------------------------------------------------------------------------- #

clean:
	@rm -rf $(KERNEL_OBJS) $(LIBS_OBJS) $(C_BUILD_OBJS) $(ASM_OBJS)
	@echo "$(COLOR_RED) || Cleaning files...$(COLOR_END)"

fclean: clean
	@rm -rf kfs.bin
	@echo "$(COLOR_RED) || Cleaning library...$(COLOR_END)"

re: fclean all

.PHONY: re fclean all clean
