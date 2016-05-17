/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampda <cchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 16:34:14 by cchampda          #+#    #+#             */
/*   Updated: 2016/05/17 18:05:19 by cchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			key_hook(int key, t_info *i, t_co *l, t_use *u)
{
	printf("%d\n", key);
	// i->zoom += (key == 126) ? 1 : 0;
	make_img(i, l, u);
	printf("hello");
	return (1);
}

int	main(int ac, char **av)
{
	t_co *list;
	t_info *info;
	t_use *use;
	list = NULL;

	if (ac > 2)
		return(0);

	use = malloc(sizeof(t_use));
	info = malloc(sizeof(t_info));
	init(info, use);
	list = get_data(av[1], list, use);
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, HGT, WDT, "colin");
	make_img(info, list, use);
	mlx_hook(info->win, 2, 3, key_hook, info);
	mlx_loop(info->mlx);
}
