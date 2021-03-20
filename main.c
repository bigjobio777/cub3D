#include <fcntl.h>
#include "libft.h"
#include <stdio.h>
#include <errno.h>
#include "gnl/get_next_line.h"
#include "cub3d.h"

int     main(int argc, char **argv)
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
    printf("%s",line);

    return (0);
}