#include "Libft/libft.h"
#include "cub3d.h"

int     tester(char *line)
{
    if (line[0] == ' ' || line[0] == '1')
        printf("amin");


    return (1);
}
int     parse_line(char *line, t_list *list)
{
    char    **big;
    int     i;

    i = 0;
    big = ft_split(line, ' ');
    if (!(ft_strcmp(big[i], "R")))
        parse_r(list, big);
    else if (!(ft_strcmp(big[i], "NO")))
        parse_NO_SO(list, big);
    else if (!(ft_strcmp(big[i], "SO")))
        parse_NO_SO(list, big);
    else if (!(ft_strcmp(big[i], "WE")))
        parse_WE_EA(list, big);
    else if (!(ft_strcmp(big[i], "EA")))
        parse_WE_EA(list, big);
    else if (!(ft_strcmp(big[i], "S")))
        parse_S(list, big);
    else if (!(ft_strcmp(big[i], "F")))
        parse_F(line, list);
    else if (!(ft_strcmp(big[i], "C")))
        parse_C(line, list);
    else if (tester(line))
        printf("DAAA?");
    
    return (0);
}
int    gnl(int  argc, char **argv, t_list *list)
{
    int     fd;
    char    *line;

    errors(argc, argv);
    errors2(argc, argv);
    fd = open(argv[1], O_RDONLY);
    if (fd == (-1))
    {
        printf("%s", strerror(errno));
        return (-1);
    }
    while (get_next_line(fd, &line) > 0)
        {
            parse_line(line, list);
        }
    parse_line(line, list);
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