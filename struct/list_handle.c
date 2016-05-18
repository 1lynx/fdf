#include "fdf.h"

void modify_list(t_co *l, t_info *i)
{
	int nx;
	int ny;


	 while(l)
	 {
		nx = i->xplace + ((sqrt(3.0) / 3.0) * ((l->x * i->zoom) - (l->y * i->zoom)));
		ny = i->yplace - ((sqrt(2.0 / 3.0) * (l->z * i->zoom / i->deep)) -
				((1.0 / sqrt(9.0)) * (i->zoom * (l->x + l->y))));
		l->x = nx;
		l->y = ny;
		l = l->next;
	 }
}

void init_co_list(t_co *list)
{
	while(list)
	{
		list->x = list->x_base;
		list->y = list->y_base;
		list->z = list->z_base;
		list = list->next;
	}
}

void print_list(t_co *list)
{
	 while(list)
	 {
		 printf("x : %d\n", list->x);
		 printf("y : %d\n", list->y);
		 printf("z : %d\n", list->z);
		 printf("nb : %d\n", list->nb);
		 printf("\n");
		 list = list->next;
	 }
}

void		ft_push_back_t(t_co **list, t_info *i)
{
	t_co	*tmp;

	tmp = *list;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add_link(i);
	}
	else
		*list = add_link(i);
}

t_co *add_link(t_info *i)
{
	t_co *tmp;

	tmp = malloc(sizeof(t_co));
	if (tmp)
	{
		tmp->x_base = i->x_line;
		tmp->y_base = i->y_line;
		tmp->z_base = i->z_tmp;
		tmp->nb = i->nb_tmp;
		tmp->next = NULL;
	}
	return(tmp);
}

void goto_n(t_co **l, t_info *i, int n)
{
	t_co *tmp;
	int bi;
	int cnt;
	cnt = 0;
	bi = 0;
	tmp = *l;

	while(cnt < (i->y_line - 1))
	{
		if(tmp->nb == n)
		{
			i->xi = i->xf;
			i->yi = i->yf;
			i->xf = (tmp->x);
			i->yf = (tmp->y);
			if(bi > 0)
			{
				line_putter(i);
				cnt++;
			}
			bi++;
		}
		tmp = tmp->next;
	}
}

t_co *get_data(char *file, t_co *list, t_info *i)
{
	char *line;
	char **tmp;
	int fd;

	i->y_line = 0;
	fd = open(file, O_RDWR);
	while (get_next_line(fd, &line) > 0)
	{
		i->x_line = 0;
		i->nb_tmp = 0;
		tmp = ft_strsplit(line, ' ');
		while (tmp[i->x_line])
		{
			i->z_tmp = ft_atoi(tmp[i->x_line]);
			ft_push_back_t(&list, i);
			i->x_line++;
			i->nb_tmp++;
		}
		free(tmp);
		free(line);
		i->y_line++;
	}
	close(fd);
	return(list);
}
