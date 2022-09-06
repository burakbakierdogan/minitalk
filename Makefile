NAME :=
CC := gcc
CFLAGS := -Wall -Werror -Wextra -I $(INCLUDE) ft_printf/libft
INCLUDE := ft_printf ft_printf/libft
SRCS := $(wildcard ft_printf/*.cpp) $(wildcard ft_printf/libft/*.c)
SRCS2 := *.c
OBJS := $(SRCS: .c=.o)

all: $(NAME) $(OBJS) $(INCLUDE)

$(NAME): $(OBJS) MAKE_C CC_
	ar -rcs $(NAME) $(OBJS)
CC_:
	$(CC) $(CFLAGS) -c $(SRCS2)
MAKE_C:
	make -C ft_printf
	make -C ft_printf/libft
	print($(OBJS))
clean:
	rm -rf *.o
	make clean -C ft_printf
	make clean -C ft_printf/libft
fclean: clean
	make fclean -C ft_printf
	make fclean -C ft_printf/libft
re: fclean all
