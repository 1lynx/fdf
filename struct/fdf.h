/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampda <cchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 16:35:26 by cchampda          #+#    #+#             */
/*   Updated: 2016/04/26 17:46:58 by cchampda         ###   ########.fr       */
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
{
	void 			*mlx;
	void 			*win;
	void 			*mlx_img;
	char 			*img_ptr;
	int 			bits_per_pixel;
	int 			size_line;
	int 			endian;
	int				color_b;
	int 			color_g;
	int 			color_r;
};

void			put_pixel_to_image(int x, int y, t_info *i);
void 			print_list(t_co *list);
t_co 			*add_link(t_co *list, int x, int y, int z);
void			line_putter(t_info *i, int xi, int yi, int xf, int yf);
void 			init(t_info *i);
int				ft_abs(int nb);
void 			make_img(t_info *info, t_co *list);
void 			get_data(char *file, t_co *list);
void 			map_maker(t_info *info, t_co *list);


#endif
