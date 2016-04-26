#include "fdf.h"


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

int		ft_abs(int nb)
{
	return ((nb < 0) ? -nb : nb);
}

void get_data(char *file, t_co *list)
{
	char *line;
	char **tmp;
	int fd;
	int x;
	int y;

	y = 0;
	fd = open(file, O_RDWR);
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
}
