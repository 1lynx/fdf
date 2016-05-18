/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampda <cchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 16:34:14 by cchampda          #+#    #+#             */
/*   Updated: 2016/05/18 18:36:56 by cchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			key_hook(int key, t_info *i, t_co *l)
{
	printf("%d\n", key);
	i->zoom += (key == 126) ? 1 : 0;
	make_img(i, l);
	printf("hello");
	return (1);
}

int	main(int ac, char **av)
{
	t_co *list;
	t_info *info;

	list = NULL;

	if (ac > 2)
		return(0);

	info = malloc(sizeof(t_info));
	init(info);
	list = get_data(av[1], list, info);
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, HGT, WDT, "colin");
	make_img(info, list);
	mlx_key_hook(info->win, key_hook, info);
	mlx_loop(info->mlx);
}
