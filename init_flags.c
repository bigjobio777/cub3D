#include "Libft/libft.h"
#include "cub3d.h"

void        init_flags(t_list *big)
{
    big->r_x = 0;
    big->r_y = 0;
    big->path_to_north = NULL;
    big->path_to_west = NULL;
    big->path_to_south = NULL;
    big->path_to_east = NULL;
    big->path_to_sprite = NULL;
    big->floor_red = 0;
    big->floor_green = 0;
    big->floor_blue = 0;
    big->ceiling_red = 0;
    big->ceiling_green = 0;
    big->ceiling_blue = 0;
}