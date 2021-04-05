#include "Libft/libft.h"
#include "cub3d.h"
#include "mlx/mlx.h"

int     main(int argc, char **argv)
{
    t_list  list;
    
    init_flags(&list);
    gnl(argc, argv, &list);
    
    // image(&list);
    return (0);
}