#include "Libft/libft.h"
#include "cub3d.h"

int     parse_line(char *line, t_list *list)
{
    char    **big;
    int     i;

    i = 0;
    big = ft_split(line, ' ');
    if (!(ft_strcmp(big[i], "R")))
        parse_r(line, list, big);
    else if (!(ft_strcmp(big[i], "NO")))
        parse_NO(line, list, big);
    else if (!(ft_strcmp(big[i], "SO")))
        parse_SO(line, list, big);
    else if (!(ft_strcmp(big[i], "WE")))
        parse_WE(line, list, big);
    else if (!(ft_strcmp(big[i], "EA")))
        parse_EA(line, list, big);
    else if (!(ft_strcmp(big[i], "S")))
        parse_S(line, list, big);
    else if (!(ft_strcmp(big[i], "F")))
        parse_F(line, list, big);
    else if (!(ft_strcmp(big[i], "C")))
        list->ceiling = "C";
    printf("krasnii == %d\n", list->floor_red);
    printf("zelenii == %d\n", list->floor_green);
    printf("sinii == %d\n", list->floor_blue);

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
    get_next_line(fd, &line);
    parse_line(line, list);

    return (0);
}