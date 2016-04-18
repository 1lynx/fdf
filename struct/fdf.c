/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampda <cchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 16:34:14 by cchampda          #+#    #+#             */
/*   Updated: 2016/04/18 19:37:21 by cchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void line_putter(t_co *list, t_info *info)
{
	int dx;
	int dy;
	int cumul;
	int x;
	int y;
  	int x_i;
  	int y_i;

  	x = list->x;
 	y = list->y;
 	x_i = list->next->x;
 	y_i = list->next->y;

 	dx = x_i - x;
  	dy = y_i - y;
  	cumul = dx / 2 ;
  	while(x <= x_i)
  	{
   	 	cumul += dy ;
    	if(cumul >= dx)
    	{
      		cumul -= dx;
      		y += 1;
      	}
		mlx_pixel_put(info->mlx, info->win, x, y, 0xFFFFFF);
		x++;
	}
}

t_co *add_link(t_co *list, int x, int y, int z)
{
	t_co *tmp;

	tmp = malloc(sizeof(t_co));
	if (tmp)
	{
		tmp->x = x;
		tmp->y = y;
		tmp->z = z;
		tmp->next = list;
	}
	return(tmp);
}

void print_list(t_co *list)
{
	 while(list)
	 {
		 printf("x : %d\n", list->x);
		 printf("y : %d\n", list->y);
		 printf("z : %d\n", list->z);
		 printf("\n");
		 list = list->next;
	 }
}

int	main(int ac, char **av)
{
	t_co *list;
	t_info *info;
	int x;
	int y = 0;
	int fd;
	char *line;
	char **tmp;
	list = NULL;

	info = malloc(sizeof(t_info));
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, HGT, WDT, "colin");

	if (ac > 2)
		return(0);

	fd = open(av[1], O_RDWR);
	while (get_next_line(fd, &line) > 0)
	{
		x = 0;
		tmp = ft_strsplit(line, ' ');
		while (tmp[x])
		{
			list = add_link(list, x, y, ft_atoi(tmp[x]));
			x++;
		}
		free(tmp);
		free(line);
		y++;
	}
	print_list(list);
	line_putter(list, info);
	mlx_loop(info->mlx);


}
