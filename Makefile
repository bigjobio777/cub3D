NAME := cub3D
SRC := main.c errors.c init_flags.c gnl.c parse_for_map.c parse_F_C.c parse_1.c gnl/get_next_line.c gnl/get_next_line_utils.c small_fun_parse.c
OBJS := $(SRC:.c=.o)
CC := gcc
D := $(SRC:.c=.d)
CFLAGS := -g -MMD#-Wall -Wextra -Werror

all: Makelib cub3D

Makelib: 
	make -C Libft

cub3D: $(OBJS) Libft/libft.a
	$(CC) $(CFLAGS) $(OBJS) -LLibft -lft -o $(NAME)

clean : 
	make clean -C Libft
	rm -rf $(D)
	rm -f *.o
	rm -f gnl/*.o

fclean : clean
	make fclean -C Libft
	rm -f $(NAME)

re : fclean
	make re -C Libft
	make all

-include $(D)
