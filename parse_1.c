#include "Libft/libft.h"
#include "cub3d.h"

void    parse_1(char *line, t_list *list)
{
    int     i;
    int     j;
    char    *testline;

    i = 0;
    j = 0;
    testline = ft_strjoin("", "");
    if ((line[i] == ' ' || line[i] == '1') && line[i])
    {
        list->bil_1 = 1;
        while ((availeble_simvol(line[i])) && line[i])
        {
            check_player(line[i], list);
            testline = ft_strjoinchr(testline, line[i++]);
        }
        if (!line[i])
           list->karta = big_massiv(list->karta, testline);
        else 
            print_error(-45);
    }
}