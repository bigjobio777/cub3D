#include "Libft/libft.h"
#include "cub3d.h"

void     check_player(char c, t_list *list)
{
    if (c == 'E' || c == 'S' || c == 'N' || c == 'W')
    {
        if (list->playes_location == 0)
            list->playes_location = 1;
        else
            print_error(-44);
    }
}

int     availeble_simvol(char c)
{
    if (c == ' ' || c == '1' || c == '2' || c == '0' || c == 'S' || c == 'N' || c == 'W' || c == 'E')
        return (1);
    return (0);
}

char    **big_massiv2(char **karta, char *testline)
{
    char    **big;
    int     i = 0;

    big = NULL;
    while(karta[i])
        i++;
    big = (char **)malloc(sizeof(char *) * (i + 2));
    i = 0;
    while (karta[i])
    {
        big[i] = ft_strdup(karta[i]);
        i++;
    }
    big[i] = ft_strdup(testline);
    i++;
    big[i] = NULL;
    return (big);
}

char    **big_massiv(char **karta, char *testline)
{
    int     i;
    int     j;
    int     itog;
    char    **big;

    i = 0;
    j = 0;
    itog = 0;
    big = NULL;
    if (karta == NULL)
    {
        big = (char **)malloc(sizeof(char  *) * (2));
        big[i] = (char *)malloc(sizeof(char) * (ft_strlen(testline) + 1));
        big[i] = testline;
        big[i + 1] = NULL;
    }
    else
    {
        big = big_massiv2(karta, testline);
    }
    return (big);
}

