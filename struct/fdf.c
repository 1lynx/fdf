/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampda <cchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 16:34:14 by cchampda          #+#    #+#             */
/*   Updated: 2016/04/26 17:48:33 by cchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void map_maker(t_info *info, t_co *list)
{
	int xi;
	int yi;
	int xf;
	int yf;

	printf("hello");
	while(list)
	{
		xi = list->x;
		yi = list->y;
		list = list->next;
		xf = list->x;
		yf = list->y;
		line_putter(info, xi, yi, xf, xf);
	}


}

int	main(int ac, char **av)
{
	t_co *list;
	t_info *info;
	list = NULL;

	if (ac > 2)
		return(0);

	get_data(av[1], list);
	info = malloc(sizeof(t_info));
	init(info);
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, HGT, WDT, "colin");
	make_img(info, list);
	mlx_loop(info->mlx);
}
