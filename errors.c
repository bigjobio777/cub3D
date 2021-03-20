#include <stdio.h>
#include "libft.h"
#include "cub3d.h"

void    print_error(int numerror)
{
    if (numerror == (-1))
        printf("Numbers of arguments wrong\n");
    else if (numerror == (-2))
        printf("File not end with .cub\n");
    else if (numerror == (-3))
        printf("3th argument not '--save'\n");
    exit(1);
}

void     errors(int  argc, char **argv)
{
    int     i;
    int     length;

    length = 0;
    i = 0;
    if (argc > 3 || argc < 2)
        print_error(-1);
    length = ft_strlen(argv[1]);
    if (argc == 2)
    {
        if (length > 4)
        {
            if (ft_strncmp(&argv[1][length - 4], ".cub", 4))
                print_error(-2);
    }
    else
        print_error(-1);
    }
}

void     errors2(int  argc, char **argv)
{
    int     i;
    int     length;

    length = ft_strlen(argv[1]);
    i = 0;
    if (argc == 3)
    {
        if (length > 4)
        {
            if (ft_strncmp(&argv[1][length - 4], ".cub", 4))
                print_error(-2);
        }
        else
            print_error(-2);
        if (ft_strncmp(argv[2], "--save", 6))
                print_error(-3);
    }
}