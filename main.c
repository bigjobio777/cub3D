#include "Libft/libft.h"
#include "cub3d.h"

int     main(int argc, char **argv)
{
    t_list  list;
    
    init_flags(&list);
    gnl(argc, argv, &list);
    int     i = 0;
    while (list.karta[i])
    {
        printf("%s\n",list.karta[i]);
        i++;
    }

    return (0);
}