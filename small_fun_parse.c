#include "Libft/libft.h"
#include "cub3d.h"

int     check_player(char c)
{
    if (c == 'E' || c == 'S' || c == 'N' || c == 'W')
        return (1);
    return (0);
}

int     availeble_simvol(char c)
{
    if ((c == ' ' || c == '1' || c == '2' || c == '0' || c == 'S' || c == 'N' || c == 'W' || c == 'E'))
        return (1);
    return (0);
}

char    **big_massiv2(char **karta, char *testline, int i, int j)
{
    int     itog;
    char    **big;

    big = NULL;
    itog = 0;
    while(karta[i])
    {
        while (karta[i][j])
            j++;
        itog += j;
        j = 0;
        i++;
    }
    big = (char **)malloc(sizeof(char) * (itog + 1 + strlen(testline + 1)));
    i = 0;
    j = 0;
    while (karta[i])
    {
        big[i] = karta[i];
        i++;
    }
    big[i++] = testline;
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
        big = (char **)malloc(sizeof(char) * (strlen(testline + 1)));
        big[i] = testline;
        big[i + 1] = NULL;
    }
    else
    {
        big = big_massiv2(karta, testline, i, j);
    }
    return (big);
}

