/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampda <cchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 16:35:26 by cchampda          #+#    #+#             */
/*   Updated: 2016/04/18 19:36:50 by cchampda         ###   ########.fr       */
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
    int x;
    int y;
	int z;
	int nb;
	t_co *next;
};

typedef struct s_info t_info;

struct s_info
{
	void *mlx;
	void *win;
};

#endif
