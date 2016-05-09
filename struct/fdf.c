/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampda <cchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 16:34:14 by cchampda          #+#    #+#             */
/*   Updated: 2016/05/09 15:53:10 by cchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	print_list(list);
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, HGT, WDT, "colin");
	make_img(info, list, use);
	mlx_loop(info->mlx);
}
