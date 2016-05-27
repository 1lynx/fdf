/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampda <cchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 16:34:14 by cchampda          #+#    #+#             */
/*   Updated: 2016/05/26 23:49:10 by cchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void print_tab(t_info *s)
{

	int x = 0;
	int y = 0;
	while(x != s->x_lines)
	{
		y = 0;
		while(y != s->y_lines)
		{
			printf("%d ", s->tab[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}

}

int	main(int ac, char **av)
{
	t_info *i;
	ac = 0;
	char *line;
	int fd;
	int lines;
	int c = 0;

	fd = open(av[1], O_RDONLY);
	lines = count_line(av[1]);
	i = malloc(sizeof(t_info));
	i->tab = (int **)malloc(sizeof(int *) * lines);
	ft_memset(i, 0, sizeof(i));
	while ((get_next_line(fd, &line)) > 0)
	{
				i->tab[c] = get_int_tab(line, i);
				c++;
	}
	i->x_lines = c;
	i->tab[c] = NULL;
	i->map_name = av[1];
	init_window(i);

}
