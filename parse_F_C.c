#include "Libft/libft.h"
#include "cub3d.h"

void    parse_F(char *line, t_list *list, char **big)
{
    char    **new;
    char    **new2;
    int     i;

    i = 0;
    new = ft_split(big[1], ',');
    new2 = ft_split(new[0], ' ');
    while (new2[0][i] )
    {
        if (!(ft_isdigit(new2[0][i])))
            print_error(-10);
        i++;
    }
    list->floor_red = ft_atoi(new2[0]);
    new2 = ft_split(new[1], ' ');
    i = 0;
    while (new2[0][i])
    {
        if (!(ft_isdigit(new2[0][i])))
            print_error(-10);
        i++;
    }
    list->floor_green = ft_atoi(new2[0]);
    new2 = ft_split(new[2], ' ');
    i = 0;
    while (new2[0][i])
    {
        if (!(ft_isdigit(new2[0][i])))
            print_error(-10);
        i++;
    }
    list->floor_blue = ft_atoi(new2[0]);
}