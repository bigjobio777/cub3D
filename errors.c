#include "Libft/libft.h"
#include "cub3d.h"

void    print_error(int numerror)
{
    if (numerror == (-1))
        printf("Numbers of arguments wrong\n");
    else if (numerror == (-2))
        printf("File not end with .cub\n");
    else if (numerror == (-3))
        printf("3th argument not '--save'\n");
    else if (numerror == (-4))
        printf("After R not digit");
    else if (numerror == (-5))
        printf("Not path to texture for NORTH in 2th argument");
    else if (numerror == (-6))
        printf("Not path to texture for SOUTH in 2th argument");
    else if (numerror == (-7))
        printf("Not path to texture for WEST in 2th argument");
    else if (numerror == (-8))
        printf("Not path to texture for EAST in 2th argument");
    else if (numerror == (-9))
        printf("Not path to texture for SPRITE in 2th argument");
    else if (numerror == (-10))
        printf("After F not digit");
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
            if (ft_strcmp(&argv[1][length - 4], ".cub"))
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
            if (ft_strcmp(&argv[1][length - 4], ".cub"))
                print_error(-2);
        }
        else
            print_error(-2);
        if (ft_strcmp(argv[2], "--save"))
                print_error(-3);
    }
}