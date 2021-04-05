#include "Libft/libft.h"
#include "cub3d.h"
#include <math.h>

double        cast_ray_x(t_list   *list, double tempo)
{
    double  length_x;
    double  length_y;
    double  dot_y;
    double  length_for_wall;
    int  x;
    int     help;

    help = 0;
    x = (int)(list->pos_x + 1);
    length_x = x - list->pos_x;
    length_y = length_x * tan(tempo);
    dot_y = length_y + list->pos_y;
    if ((dot_y < list->max_y && dot_y >= 0) && (x >= 0 && x < list->max_x))
    {
        while (list->karta[(int)(dot_y)][x] != '1' && help == 0)
        {
            x++;
            length_x = fabs(x - list->pos_x);
            length_y = length_x / tan(tempo);
            dot_y = length_y + list->pos_y;
            printf("length_x == %f    length_y == %f\n", length_x, length_y);
            printf("DOT_Y == %f    x == %d\n", dot_y, x);
            if (!((dot_y < list->max_y && dot_y >= 0) && (x >= 0 && x < list->max_x)))
                help = 1;
        }
    }
    length_for_wall = (length_y / sin(tempo));
    return(length_for_wall);
}

double       cast_ray_y(t_list   *list, double tempo)
{
    double  length_x;
    double  length_y;
    double  dot_x;
    double  length_for_wall;
    int  y;
    int     help;

    help = 0;
    y = (int)(list->pos_y + 1);
    length_y = y - list->pos_y;
    length_x = length_y / tan(tempo);
    dot_x = length_x + list->pos_x;
    if ((y < list->max_y && y >= 0) && (dot_x >= 0 && dot_x < list->max_x))
    {
        while (list->karta[y][((int)(dot_x))] != '1')
        {
            y++;
            length_y = y - list->pos_y;
            length_x = length_y / tan(tempo);
            dot_x = length_x + list->pos_x;
            if (!((y < list->max_y && y >= 0) && (dot_x >= 0 && dot_x < list->max_x)))
                help = 1;
        }
    }
    length_for_wall = length_y / sin(tempo);
    return(length_for_wall);
}

void        cast_rays(t_list *list)
{
    double      increment_FOV;
    double      tempo;
    double      first;
    double      second;

    tempo = list->pos_angle - list->FOV / 2;
    increment_FOV = list->FOV / list->r_x;
    printf(" tempo nachalnaya == %f\n", tempo);
    printf("increment   == %f\n", increment_FOV);
    printf(" tempo itogovaya == %f\n", (list->pos_angle + list->FOV / 2));
    while (tempo <= (list->pos_angle + list->FOV / 2))
    {
        // first = fmin(cast_ray_x(list,tempo), cast_ray_y(list, tempo));
        first = cast_ray_x(list, tempo);
        second = cast_ray_y(list,tempo);
        printf("ugol == %f , rasstoyanie do steni po x  == %f\n", tempo, first);
        printf("ugol == %f , rasstoyanie do steni po y == %f\n", tempo, second);
        tempo += increment_FOV;
    }

}