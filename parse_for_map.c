#include "Libft/libft.h"
#include "cub3d.h"

void    parse_r(char *line, t_list *list, char **big)
{
    int     i;
    int     j;

    j = 0;
    i = 1;
    list->razreshenie = "R";
    while (i < 3)
    {
        while (big[i][j])
        {
            if (!(ft_isdigit(big[i][j])))
                print_error(-4);
            j++;
        }
        if (i == 1)
            list->razmerRazresheniya1 = ft_atoi(big[i]);
        else if(i == 2)
            list->razmerRazresheniya2 = ft_atoi(big[i]);
        i++;
    }
    printf("R если разрешение  == %s\n", list->razreshenie);
    printf("Разрешение экрана 1 == %d\n", list->razmerRazresheniya1);
    printf("Разрешение экрана 2 == %d", list->razmerRazresheniya2);
}

void    parse_NO(char *line, t_list *list, char **big)
{
    list->north = "NO";
    if (big[1][0] != '.' || big[1][1] != '/')
        print_error(-5);
    list->path_to_north = big[1];
}

void    parse_SO(char *line, t_list *list, char **big)
{
    list->south = "SO";
    if (big[1][0] != '.' || big[1][1] != '/')
        print_error(-6);
    list->path_to_south = big[1];
}

void    parse_WE(char *line, t_list *list, char **big)
{
    list->west = "WE";
    if (big[1][0] != '.' || big[1][1] != '/')
        print_error(-7);
    list->path_to_west = big[1];
}

void    parse_EA(char *line, t_list *list, char **big)
{
    list->east = "EA";
    if (big[1][0] != '.' || big[1][1] != '/')
        print_error(-8);
    list->path_to_east = big[1];
}

void    parse_S(char *line, t_list *list, char **big)
{
    list->sprite = "S";
    if (big[1][0] != '.' || big[1][1] != '/')
        print_error(-9);
    list->path_to_sprite = big[1];
}