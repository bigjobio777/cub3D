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
    else if (numerror == (-11))
        printf("in F more digits than 3");
    else if (numerror == (-12))
        printf("Error arguments in F");
    else if (numerror == (-13))
        printf("Duplicate line -R-");
    else if (numerror == (-14))
        printf("Arguments in -R- more than 2");
    else if (numerror == (-15))
        printf("Duplicate line -NO-");
    else if (numerror == (-16))
        printf("Duplicate line -SO-");
    else if (numerror == (-17))
        printf("Duplicate line -WE-");
    else if (numerror == (-18))
        printf("in -WE- arguments more than 2");
    else if (numerror == (-19))
        printf("in -SO- arguments more than 2");
    else if (numerror == (-20))
        printf("in -NO- arguments more than 2");
    else if (numerror == (-21))
        printf("in -EA- arguments more than 2");
    else if (numerror == (-22))
        printf("Duplicate line -EA-");
    else if (numerror == (-23))
        printf("in -Sprite- arguments more than 2");
    else if (numerror == (-24))
        printf("Duplicate line -Sprite-");
    else if (numerror == (-25))
        printf("Not digit arguments in -F-");
    else if (numerror == (-26))
        printf("Not dot in -F-");
    else if (numerror == (-27))
        printf("line -F- haven't end line");
    else if (numerror == (-28))
        printf("Duplicate line -F-");
    else if (numerror == (-29))
        printf("colors in -F- more 255 or lower than 1");
    else if (numerror == (-30))
        printf("Duplicate line -C-");
    else if (numerror == (-31))
        printf("Not dot in -C-");
    else if (numerror == (-32))
        printf("line -C- haven't end line");
    else if (numerror == (-33))
        printf("Not digit arguments in -C-");
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