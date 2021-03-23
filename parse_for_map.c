#include "Libft/libft.h"
#include "cub3d.h"

void    parse_r(t_list *list, char **big)
{
    int     i;
    int     j;

    j = 0;
    i = 1;
    if (list->r_x != 0)
        print_error(-13);
    if (big[3] != NULL)
        print_error(-14);
    while (i < 3)
    {
        while (big[i][j])
        {
            if (!(ft_isdigit(big[i][j])))
                print_error(-4);
            j++;
        }
        if (i == 1)
            list->r_x = ft_atoi(big[i]);
        else if(i == 2)
            list->r_y = ft_atoi(big[i]);
        i++;
    }
}

void    parse_NO(t_list *list, char **big)
{
    if (big[2] != NULL)
        print_error(-20);
    if (list->path_to_north != NULL)
        print_error(-15);
    list->path_to_north = ft_strdup(big[1]);
}

void    parse_SO(t_list *list, char **big)
{
    if (big[2] != NULL)
        print_error(-19);
    if (list->path_to_south != NULL)
        print_error(-16);
    list->path_to_south = ft_strdup(big[1]);
}

void    parse_WE(t_list *list, char **big)
{
    if (big[2] != NULL)
        print_error(-18);
    if (list->path_to_west != NULL)
        print_error(-17);
    list->path_to_west = ft_strdup(big[1]);
}

void    parse_EA(t_list *list, char **big)
{
    if (big[2] != NULL)
        print_error(-21);
    if (list->path_to_east != NULL)
        print_error(-22);
    list->path_to_east = ft_strdup(big[1]);
}

void    parse_S(t_list *list, char **big)
{
    if (big[2] != NULL)
        print_error(-23);
    if (list->path_to_sprite != NULL)
        print_error(-24);
    list->path_to_sprite = ft_strdup(big[1]);
}