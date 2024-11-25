# ---------------------------------------------------------------------------- #

SRCS		=	LIBC/printk.c \
				LIBC/STRING/strcat.c LIBC/STRING/strcmp.c LIBC/STRING/strcpy.c LIBC/STRING/strlen.c \
				LIBC/MEM/memcmp.c LIBC/MEM/memcpy.c LIBC/MEM/memmove.c

# ---------------------------------------------------------------------------- #

OBJS 		= 	$(SRCS:.c=.o)

CLANG		=	clang

NAME		=	libkfs.a

INCL		=	../INCL

TARGET		=	--target=i386-unknown-none

FLAGS		=	-std=gnu99 -O2 -ffreestanding -Wall -Wextra -fno-builtin -fno-exceptions -fno-stack-protector -nostdlib -nodefaultlibs

COLOR_GREEN=	\033[1;32m
COLOR_RED	=	\033[1;31m
COLOR_BLUE	=	\033[3;36m
COLOR_PURP	=	\033[1;35m
COLOR_END	=	\033[0m

%.o: %.c
	@$(CLANG) $(TARGET) $(FLAGS) -I $(INCL) -c $< -o $@
	@echo "$(COLOR_BLUE) || Compiling ($<)...$(COLOR_END)"

all: $(NAME)

$(NAME): $(OBJS) 
	@ar rcs $(NAME) $(OBJS)
	@echo "$(COLOR_GREEN)|| Done !$(COLOR_END)"

clean:
	@rm -f $(OBJS)
	@echo "$(COLOR_PURP)|| Cleaning files...$(COLOR_END)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(COLOR_PURP)|| Cleaning library...$(COLOR_END)"

re: fclean all

.PHONY: all clean fclean re