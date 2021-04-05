#include "Libft/libft.h"
#include "cub3d.h"

void            my_mlx_pixel_put(t_list *list, int x, int y, int color)
{
    char    *dst;

    dst = list->data.addr + (y * list->data.line_length + x * (list->data.bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void    image(t_list *list)
{
    list->mlx.mlx = mlx_init();
    list->mlx.mlx_win = mlx_new_window(list->mlx.mlx, 1000, 600, "Hello world!");
    list->data.img = mlx_new_image(list->mlx.mlx, 1000, 600);
    list->data.addr = mlx_get_data_addr(list->data.img, &list->data.bits_per_pixel, &list->data.line_length, &list->data.endian);
    mlx_put_image_to_window(list->mlx.mlx, list->mlx.mlx_win, list->data.img, 0, 0);
    mlx_key_hook(list->mlx.mlx_win, touch_key, list);
    mlx_loop(list->mlx.mlx);
}