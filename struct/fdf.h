/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampda <cchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 16:35:26 by cchampda          #+#    #+#             */
/*   Updated: 2016/05/03 18:32:15 by cchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#include "libft/libft.h"
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
# define HGT 700
# define WDT 700
# define BUF_SIZE 1000

typedef struct s_use t_use;

struct s_use
{
	int x_line;
	int y_line;
	int z_tmp;
	int nb_tmp;
	int xi;
	int yi;
	int xf;
	int yf;
};

typedef struct s_co t_co;

struct s_co
{
    int 	x;
    int 	y;
	int 	z;
	int 	nb;
	t_co 	*next;
};

typedef struct s_info t_info;

struct s_info
{	void 			*mlx;
	void 			*win;
	void 			*mlx_img;
	char 			*img_ptr;
	int 			bits_per_pixel;
	int 			size_line;
	int 			endian;
	int 			zoom;
	int 			place;
	int				color_b;
	int 			color_g;
	int 			color_r;
};

// INIT + IMAGE

void 			init(t_info *i, t_use *u);
void 			init_co(t_use *u);
void			line_putter(t_info *i, t_use *u);
void			put_pixel_to_image(int x, int y, t_info *i);
void 			make_img(t_info *info, t_co *list, t_use *use);

// GESTION LIST

void 			print_list(t_co *list);
void			ft_push_back_t(t_co **list, t_use *u);
t_co 			*add_link(t_use *u);
void 			goto_n(t_use *u, t_co **l, t_info *i, int n);
t_co 			*get_data(char *file, t_co *list, t_use *use);

// CREATE MAP

void 			map_maker(t_info *info, t_co *list, t_use *use);
void 			second_mapping(t_info *i, t_co *l, t_use *u);





#endif
