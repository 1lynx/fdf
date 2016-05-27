/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampda <cchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 16:35:26 by cchampda          #+#    #+#             */
/*   Updated: 2016/05/27 04:06:56 by cchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#include "libft/libft.h"
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
# define HGT 1000
# define WDT 1500
# define BUF_SIZE 1000


typedef struct	s_info
{
	void 		*mlx;
	void 		*win;
	void 		*mlx_img;
	char 		*ptr_img;
	int 		x_lines;
	int 		y_lines;
	int 		**tab;
	int 		x_place;
	int 		y_place;
	float 		zoom;
	int 		deep;
	float		flat;
	float		R;
	float		G;
	float		B;
	int			bpp;
	int 		sl;
	int			ian;
	int			mode;
	int			x;
	int			y;
	int			dx;
	int			sx;
	int			dy;
	int			sy;
	int			err;
	int 		err2;
	char 		*map_name;

}				t_info;

typedef struct s_point
{
	int x;
	int y;
}							t_point;

void 		print_tab(t_info *s);
int			count_col(char **tab, t_info *s);
int			count_line(char *av);
int			*get_int_tab(char *str, t_info *s);

void 		init_para(t_info *i);
void 		init_window(t_info *i);
void 		put_calc_img(t_info *i);
void 		init_color(t_info *s, int z);
void 		put_pixel_to_image(int x, int y, t_info *i);
t_point		calcul(int x, int y, int z, t_info *i);
void 		print_trace(t_point p1, t_point p2, t_info *i);
void 		print_map(t_info *i);
int 		ft_key_print(int key, t_info *i);
void 		menu(t_info *s);
// void 		loop_base(t_info *i);




#endif
