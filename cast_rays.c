#include "Libft/libft.h"
#include "cub3d.h"
#include <math.h>

double		cast_ray_x_n(t_list   *list, double tempo)
{
	double  length_x;
	double  length_y;
	double  dot_y;
	double  length_for_wall;
	int  x;
	int	 help;

	help = 0;
	x = (int)(list->pos_x + 1);
	length_x = x - list->pos_x;
	length_y = length_x * tan(tempo);
	dot_y = length_y + list->pos_y;
	while (((int)dot_y < list->max_y && (int)dot_y >= 0) && (x >= 0 && x < list->max_x) && list->karta[(int)(dot_y)][x] != '1' && help == 0)
	{
		x++;
		length_x = x - list->pos_x;
		length_y = length_x * tan(tempo);
		dot_y = length_y + list->pos_y;
		if (!((dot_y < list->max_y && dot_y >= 0) && (x >= 0 && x < list->max_x)))
			help = 1;
	}
	length_for_wall = fabs(length_y / sin(tempo));
	return(length_for_wall);
}

double	   cast_ray_y_n(t_list   *list, double tempo)
{
	double  length_x;
	double  length_y;
	double  dot_x;
	double  length_for_wall;
	int  y;
	int	 help;

	help = 0;
	y = (int)(list->pos_y + 1);
	length_y = y - list->pos_y;
	length_x = length_y / tan(tempo);
	dot_x = length_x + list->pos_x;
	
	while ((y < list->max_y && y >= 0) && (dot_x >= 0 && dot_x < list->max_x) && list->karta[y][((int)(dot_x))] != '1')
	{
		y++;
		length_y = y - list->pos_y;
		length_x = length_y / tan(tempo);
		dot_x = length_x + list->pos_x;
		if (!((y < list->max_y && y >= 0) && (dot_x >= 0 && dot_x < list->max_x)))
			help = 1;
	}

	length_for_wall = fabs(length_y / sin(tempo));
	return(length_for_wall);
}

double		cast_ray_x_w(t_list   *list, double tempo)
{
	double  length_x;
	double  length_y;
	double  dot_y;
	double  length_for_wall;
	int  x;
	int	 help;

	help = 0;
	x = (int)(list->pos_x);
	length_x =  x - list->pos_x;
	length_y = length_x * tan(tempo);
	dot_y = length_y + list->pos_y;
	while (((int)dot_y < list->max_y && (int)dot_y >= 0) && (x - 1 >= 0 && x - 1 < list->max_x) && list->karta[(int)(dot_y)][x - 1] != '1' && help == 0)
	{
		x--;
		length_x = x - list->pos_x;
		length_y = length_x * tan(tempo);
		dot_y = length_y + list->pos_y;
		if (!((dot_y < list->max_y && dot_y >= 0) && (x >= 0 && x < list->max_x)))
			help = 1;
	}
	length_for_wall = fabs(length_x / cos(tempo));
	return(length_for_wall);
}

double	   cast_ray_y_w(t_list   *list, double tempo)
{
	double  length_x;
	double  length_y;
	double  dot_x;
	double  length_for_wall;
	int  y;
	int	 help;

	help = 0;
	y = (int)(list->pos_y + 1);
	length_y = y - list->pos_y;
	length_x = length_y / tan(tempo);
	dot_x = list->pos_x + length_x;
	while ((y < list->max_y && y >= 0) && (dot_x >= 0 && dot_x < list->max_x) && list->karta[y][((int)(dot_x))] != '1')
	{
		y++;
		length_y = y - list->pos_y;
		length_x = length_y / tan(tempo);
		dot_x = list->pos_x + length_x;
		if (!((y < list->max_y && y >= 0) && (dot_x >= 0 && dot_x < list->max_x)))
			help = 1;
	}

	length_for_wall = fabs(length_y / sin(tempo));
	return(length_for_wall);
}

double		cast_ray_x_s(t_list   *list, double tempo)
{
	double  length_x;
	double  length_y;
	double  dot_y;
	double  length_for_wall;
	int  x;
	int	 help;

	help = 0;
	x = (int)(list->pos_x);
	length_x = x - list->pos_x;
	length_y = length_x * tan(tempo);
	dot_y = length_y + list->pos_y;
	while (((int)dot_y < list->max_y && (int)dot_y >= 0) && (x - 1 >= 0 && x - 1 < list->max_x) && list->karta[(int)(dot_y)][x - 1] != '1' && help == 0)
	{
		x--;
		length_x = list->pos_x - x;
		length_y = length_x * tan(tempo);
		dot_y = length_y + list->pos_y;
		if (!((dot_y < list->max_y && dot_y >= 0) && (x >= 0 && x < list->max_x)))
			help = 1;
	}
	length_for_wall = fabs(length_x / cos(tempo));
	return(length_for_wall);
}

double	   cast_ray_y_s(t_list   *list, double tempo)
{
	double  length_x;
	double  length_y;
	double  dot_x;
	double  length_for_wall;
	int  y;
	int	 help;

	help = 0;
	y = (int)(list->pos_y);
	length_y = y- list->pos_y;
	length_x = length_y / tan(tempo);
	dot_x = length_x + list->pos_x;
	
	while ((y < list->max_y && y >= 0) && (dot_x - 1 >= 0 && dot_x - 1 < list->max_x) && list->karta[y][((int)(dot_x) - 1)] != '1')
	{
		y--;
		length_y = y - list->pos_y;
		length_x = length_y / tan(tempo);
		dot_x = length_x + list->pos_x;
		if (!((y < list->max_y && y >= 0) && (dot_x - 1 >= 0 && dot_x - 1 < list->max_x)))
			help = 1;
	}
	length_for_wall = fabs(length_y / sin(tempo));
	return(length_for_wall);
}

double		cast_ray_x_e(t_list *list, double tempo)
{
	double  length_x;
	double  length_y;
	double  dot_y;
	double  length_for_wall;
	int  x;
	int	 help;

	help = 0;
	x = (int)(list->pos_x + 1);
	length_x = x - list->pos_x;
	length_y = length_x * tan(tempo);
	dot_y = length_y + list->pos_y;
	while (((int)dot_y < list->max_y && (int)dot_y >= 0) && (x >= 0 && x < list->max_x) && list->karta[(int)(dot_y)][x] != '1' && help == 0)
	{
		x++;
		length_x = list->pos_x - x;
		length_y = length_x * tan(tempo);
		dot_y = length_y + list->pos_y;
		if (!((dot_y < list->max_y && dot_y >= 0) && (x >= 0 && x < list->max_x)))
			help = 1;
	}
	length_for_wall = fabs(length_x / cos(tempo));
	return(length_for_wall);
}

double		cast_ray_y_e(t_list *list, double tempo)
{
	double  length_x;
	double  length_y;
	double  dot_x;
	double  length_for_wall;
	int  y;
	int	 help;

	help = 0;
	y = (int)(list->pos_y);
	length_y = y - list->pos_y;
	length_x = length_y / tan(tempo);
	dot_x = length_x + list->pos_x;
	while ((y < list->max_y && y>= 0) && (dot_x - 1 >= 0 && dot_x - 1 < list->max_x) && list->karta[y][(int)dot_x - 1] != '1' && help == 0)
	{
		y--;
		length_y = y - list->pos_y;
		length_x = length_y / tan(tempo);
		dot_x = length_x + list->pos_x;
		if (!((y - 1 < list->max_y && y - 1 >= 0) && (dot_x - 1 >= 0 && dot_x - 1 < list->max_x)))
			help = 1;
	}
	length_for_wall = fabs(length_y / sin(tempo));
	return(length_for_wall);
}

void		cast_rays(t_list *list)
{
	double	  increment_FOV;
	double	  tempo;
	double	  first;
	double	  second;
	int		 i;
	int		 y;
	double	  visota;

	i = 0;
	y = 0;
	tempo = list->pos_angle + list->FOV / 2;
	increment_FOV = list->FOV / list->r_x;
	while ((tempo >= (list->pos_angle - list->FOV / 2)) && (i < list->r_x))
	{
		if (tempo >= 2 * M_PI)
			tempo -= 2 * M_PI;
		else if (tempo < 0)
			tempo += 2 * M_PI;
		if (tempo >= 0 && tempo < (M_PI / 2))
		{
			first = cast_ray_x_n(list, tempo);
			second = cast_ray_y_n(list,tempo);
			make_image(list, i, fmin(first, second));
		}
		else if (tempo >= (M_PI / 2) && tempo < M_PI)
		{
			first = cast_ray_x_w(list, tempo);
			second = cast_ray_y_w(list,tempo);
			make_image(list, i, fmin(first, second));
		}
		else if (tempo >= M_PI && tempo < (3 * (M_PI / 2)))
		{
			first = cast_ray_x_s(list, tempo);
			second = cast_ray_y_s(list,tempo);
			make_image(list, i, fmin(first, second));
		}
		else if (tempo >= (3 * (M_PI / 2)) && tempo < (2 * M_PI))
		{
			first = cast_ray_x_e(list, tempo);
			second = cast_ray_y_e(list,tempo);
			make_image(list, i, fmin(first, second));
		}
		i++;
		tempo -= increment_FOV;
	}
}