/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigjobio <bigjobio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:48:01 by bigjobio          #+#    #+#             */
/*   Updated: 2021/03/22 23:47:50 by bigjobio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

# include "mms/mlx.h"
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include "gnl/get_next_line.h"

typedef struct                  s_list
{
    int     r_x;
    int     r_y;
    char    *path_to_north;
    char    *south;
    char    *path_to_south;
    char    *west;
    char    *path_to_west;
    char    *east;
    char    *path_to_east;
    char    *sprite;
    char    *path_to_sprite;
    char    *floor;
    int     floor_red;
    int     floor_green;
    int     floor_blue;
    char    *ceiling;
    int     ceiling_red;
    int     ceiling_green;
    int     ceiling_blue;
        
}                               t_list;


void    print_error(int numerror);
void    errors(int  argc, char **argv);
void    errors2(int  argc, char **argv);
void    init_flags(t_list *big);
int     gnl(int  argc, char **argv, t_list *list);
void    parse_r(t_list *list, char **big);
void    parse_NO(t_list *list, char **big);
void    parse_SO(t_list *list, char **big);
void    parse_WE(t_list *list, char **big);
void    parse_EA(t_list *list, char **big);
void    parse_S(t_list *list, char **big);
void    parse_F(char *line, t_list *list);
void    parse_C(char *line, t_list *list);


#endif