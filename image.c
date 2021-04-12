#include "libft.h"
#include "cub3d.h"

int	 key_hook(int keycode, t_list *list)
{	
    if (keycode == LEFT)
		list->key_pressed[LEFT] = 1;
	else if (keycode == RIGHT)
		list->key_pressed[RIGHT] = 1;
	else if (keycode == ESC)
		exit(1);
	else if (keycode == W)
		list->key_pressed[W] = 1;
	else if (keycode == S)
		list->key_pressed[S] = 1;
	else if (keycode == A)
		list->key_pressed[A] = 1;
	else if (keycode == D)
		list->key_pressed[D] = 1;
	printf("UGOL == %f\n", list->pos_angle);
	printf("Position po x == %f, Position po y = %f\n", list->pos_x, list->pos_y);
return (0);
}

int		key_hook_exit(int	keycode, t_list *list)
{
	exit(0);
}

int		key_hook_stop(int keycode, t_list *list)
{
	if (keycode == LEFT)
		list->key_pressed[LEFT] = 0;
	else if (keycode == RIGHT)
		list->key_pressed[RIGHT] = 0;
	else if (keycode == W)
		list->key_pressed[W] = 0;
	else if (keycode == S)
		list->key_pressed[S] = 0;
	else if (keycode == A)
		list->key_pressed[A] = 0;
	else if (keycode == D)
		list->key_pressed[D] = 0;

	return (0);
}

void	make_image(t_list *list, int stolbec, double dist)
{
	int	 i;
	int	 nachalo;
	int	 konec;
	double	tempo_dist;
	double	visota;
	int		help_i;

	help_i = 0;
	i = 0;
	nachalo = 0;
	konec = 0;
	tempo_dist = dist;
	visota = (list->focus / dist) * list->r_y;
	while (i <= (list->r_y - visota) / 2 && i < list->r_y)
	{
		my_mlx_pixel_put(list, stolbec, i, 0xFF0000);
		i++;
	}

	while (i <= (list->r_y + visota) / 2 && i < list->r_y)
	{
		my_mlx_pixel_put(list, stolbec, i, 0x00FF00);
		i++;
	}

	while (i < list->r_y)
	{
		my_mlx_pixel_put(list, stolbec, i, 0x0000FF);
		i++;
	}
}
void			my_mlx_pixel_put(t_list *list, int x, int y, int color)
{
	char	*dst;

	dst = list->data.addr + (y * list->data.line_length + x * (list->data.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
