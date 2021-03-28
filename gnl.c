#include "Libft/libft.h"
#include "cub3d.h"

int    tester(char *line, t_list *list)
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
            if (check_player(line[i]))
            {
                if(list->playes_location == 0)
                    list->playes_location = 1;
                else
                    print_error(-44);
            }
            testline = ft_strjoinchr(testline, line[i++]);
        }
        if (!line[i])
           list->karta = big_massiv(list->karta, testline);
        else 
            print_error(-45);
    }
    return (0);
}

int     parse_line(char *line, t_list *list)
{
    char    **big;

    if (list->bil_1 == 1 && line[0] != ' ' && line[0] != '1' && line[0])
        print_error(-43);
    if (line[0] == '\0')
        return (0);
    big = ft_split(line, ' ');
    if (tester(line, list))
        printf("DAAA?");
    if (!(ft_strcmp(big[0], "R")))
        parse_r(list, big);
    else if (!(ft_strcmp(big[0], "NO")))
        parse_NO_SO(list, big);
    else if (!(ft_strcmp(big[0], "SO")))
        parse_NO_SO(list, big);
    else if (!(ft_strcmp(big[0], "WE")))
        parse_WE_EA(list, big);
    else if (!(ft_strcmp(big[0], "EA")))
        parse_WE_EA(list, big);
    else if (!(ft_strcmp(big[0], "S")))
        parse_S(list, big);
    else if (!(ft_strcmp(big[0], "F")))
        parse_F(line, list);
    else if (!(ft_strcmp(big[0], "C")))
        parse_C(line, list);
    return (0);
}
int    gnl(int  argc, char **argv, t_list *list)
{
    int     fd;
    char    *line;
    int     test;

    errors(argc, argv);
    errors2(argc, argv);
    fd = open(argv[1], O_RDONLY);
    if (fd == (-1))
    {
        printf("%s", strerror(errno));
        return (-1);
    }
    while ((test = get_next_line(fd, &line)) > 0)
        {
            parse_line(line, list);
            free(line);
        }
    parse_line(line, list);
    free(line);

    printf("R_X == %d, R_Y == %d\n", list->r_x, list->r_y);
    printf("%s\n", list->path_to_north);
    printf("%s\n", list->path_to_south);
    printf("%s\n", list->path_to_west);
    printf("%s\n", list->path_to_east);
    printf("%s\n", list->path_to_sprite);
    printf("floor_red == %d, floor_green == %d, floor_blue == %d\n", list->floor_red, list->floor_green, list->floor_blue);
    printf("ceiling_red == %d, ceiling_green == %d, ceiling_blue == %d\n", list->ceiling_red, list->ceiling_green, list->ceiling_blue);

    return (0);
}