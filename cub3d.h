/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigjobio <bigjobio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:48:01 by bigjobio          #+#    #+#             */
/*   Updated: 2021/03/29 13:39:47 by bigjobio         ###   ########.fr       */
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
    char    *path_to_south;
    char    *path_to_west;
    char    *path_to_east;
    char    *path_to_sprite;
    int     floor_red;
    int     floor_green;
    int     floor_blue;
    int     ceiling_red;
    int     ceiling_green;
    int     ceiling_blue;
    int     max_map;
    int     help_mas;
    int     bil_1;
    int     playes_location;
    char    **karta;
}                               t_list;


void    print_error(int numerror);
void    errors(int  argc, char **argv);
void    errors2(int  argc, char **argv);
void    init_flags(t_list *big);
int     gnl(int  argc, char **argv, t_list *list);
void    parse_r(t_list *list, char **big);
void    parse_NO_SO(t_list *list, char **big);
void    parse_WE_EA(t_list *list, char **big);
void    parse_S(t_list *list, char **big);
void    parse_F(char *line, t_list *list);
void    parse_C(char *line, t_list *list);
void    parse_1(char *line, t_list *list);
void     check_player(char c, t_list *list);
int     availeble_simvol(char c);
char    **big_massiv(char **karta, char *testline);
void    check_all(t_list *list);
void    last_line_map(char *line);
char    **check_map(t_list *list);

#endif