# ---------------------------------------------------------------------------- #

SRCS		=	../KERNEL/main.c
# ---------------------------------------------------------------------------- #

OBJS		=	$(SRCS:.c=.o)

DEPS		=	$(SRCS:.c=.d)

CLANG		=	clang

INCL		=	../INCL/libc.h

TARGET		=	--target=i386-unknown-none

FLAGS		=	-std=gnu99 -O2 -ffreestanding -Wall -Wextra -fno-builtin -fno-exceptions -fno-stack-protector -nostdlib -nodefaultlibs

COLOR_GREEN	=	\033[1;32m
COLOR_RED	=	\033[1;31m
COLOR_BLUE	=	\033[3;36m
COLOR_PURP	=	\033[1;35m
COLOR_END	=	\033[0m

%.o: %.c
	@$(CLANG) $(TARGET) $(FLAGS) -include $(INCL) -c $< -o $@
	@echo "$(COLOR_BLUE) || Compiling ($<)...$(COLOR_END)"

all: $(OBJS) $(INCL)
	@$(CLANG) $(TARGET) -T ../CONF/linker.ld -o kfs.bin -ffreestanding -O2 -nostdlib ../../boot.o $(OBJS)
	@echo "$(COLOR_GREEN) || Done !$(COLOR_END)"

clean:
	@rm -rf $(OBJS)
	@echo "$(COLOR_RED) || Cleaning files...$(COLOR_END)"

fclean: clean
	@rm -rf $(DEPS)
	@echo "$(COLOR_RED) || Cleaning library...$(COLOR_END)"

re: fclean all

.PHONY: re fclean all clean