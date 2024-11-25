# ---------------------------------------------------------------------------- #
SRCS		=	../KERNEL/main.c \
				../KERNEL/TTY/color.c \
				../KERNEL/TTY/display.c \
				../KERNEL/TTY/init.c \
				../KERNEL/TTY/vga.c 

# ---------------------------------------------------------------------------- #

OBJS		=	$(SRCS:.c=.o)

CLANG		=	clang

INCL		=	../INCL

LIBKFS		=	../LIBS/libkfs.a

TARGET		=	--target=i386-unknown-none

FLAGS		=	-std=gnu99 -O2 -ffreestanding -Wall -Wextra -fno-builtin -fno-exceptions -fno-stack-protector -nostdlib -nodefaultlibs

COLOR_GREEN	=	\033[1;32m
COLOR_RED	=	\033[1;31m
COLOR_BLUE	=	\033[3;36m
COLOR_PURP	=	\033[1;35m
COLOR_END	=	\033[0m

%.o: %.c
	@$(CLANG) $(TARGET) $(FLAGS) -I $(INCL) -c $< -o $@
	@echo "$(COLOR_BLUE) || Compiling ($<)...$(COLOR_END)"

all: $(LIBKFS) $(OBJS) 
	@$(CLANG) $(TARGET) -T ../CONF/linker.ld -I $(INCL) -L../LIBS -lkfs -o kfs.bin -ffreestanding -O2 -nostdlib ../../boot.o $(OBJS)
	@echo "$(COLOR_GREEN) || Done !$(COLOR_END)"

$(LIBKFS): $(INCL)
	@$(MAKE) -C ../LIBS
	@echo "$(COLOR_GREEN) || Compiled Libkfs! $(COLOR_END)"

clean:
	@rm -rf $(OBJS)
	@$(MAKE) --no-print-directory -C ../LIBS clean
	@echo "$(COLOR_RED) || Cleaning files...$(COLOR_END)"

fclean: clean
	@rm -rf kfs.bin
	@$(MAKE) --no-print-directory -C ../LIBS fclean
	@echo "$(COLOR_RED) || Cleaning library...$(COLOR_END)"

re: fclean all

.PHONY: re fclean all clean