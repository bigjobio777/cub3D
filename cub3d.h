/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigjobio <bigjobio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:48:01 by bigjobio          #+#    #+#             */
/*   Updated: 2021/03/20 22:09:55 by bigjobio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

# include "mms/mlx.h"
# include <stdio.h>
# include <string.h>




typedef struct          s_mlx
{
    void            *ptr;
}                       t_mlx;

typedef struct          s_win
{
    void            *ptr;
    int             x;
    int             y;
}                       t_win;

typedef struct          s_img
{
    void            *ptr;
    unsigned int    *adr;
    int             flash;
}                       t_img;

typedef struct          s_error
{
    int             a;
    int             b;
    int             c;
}                       t_error;

typedef struct          s_list
{
    t_mlx           mlx;
    t_win           win;
    t_img           img;
    t_error         error;
}                       t_list;

void    print_error(int numerror);
void     errors(int  argc, char **argv);
void     errors2(int  argc, char **argv);

#endif