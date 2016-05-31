/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampda <cchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 16:34:14 by cchampda          #+#    #+#             */
/*   Updated: 2016/05/31 14:53:11 by cchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int		main(int ac, char **av)
{
	t_info *i;

	i = malloc(sizeof(t_info));
	if (ac == 2 && av[1] && ft_strstr(av[1], ".fdf"))
		open_file(i, av[1]);
	else
		USAGE_ERROR;
}
