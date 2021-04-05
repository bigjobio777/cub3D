NAME := cub3D
SRC := main.c errors.c init_flags.c gnl.c all_for_parse/parse_for_map.c all_for_parse/parse_F_C.c all_for_parse/parse_1.c gnl/get_next_line.c gnl/get_next_line_utils.c all_for_parse/small_fun_parse.c image.c key.c cast_rays.c angle_maker.c make_karta.c
OBJS := $(SRC:.c=.o)
CC := gcc
D := $(SRC:.c=.d)
CFLAGS ?= -MMD -Imlx#-Wall -Wextra -Werror

all: Makelib cub3D

Makelib: 
	make -C Libft

cub3D: $(OBJS) Libft/libft.a
	$(CC) -g -Lmlx  -framework OpenGL libmlx.dylib -framework AppKit $(CFLAGS) $(OBJS) -LLibft -lft -o $(NAME)

debug:
	make all CFLAGS+="$(CFLAGS) -g"
clean : 
	make clean -C Libft
	rm -rf $(D)
	rm -f *.o
	rm -f gnl/*.o
	rm -f all_for_parse/*.o

fclean : clean
	make fclean -C Libft
	rm -f $(NAME)

re : fclean
	make re -C Libft
	make all

-include $(D)
