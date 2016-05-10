#include "fdf.h"

void modify_list(t_co *l, t_info *i)
{
	int nx;
	int ny;

	 while(l)
	 {
		nx = i->xplace + ((sqrt(2) / 2) * ((l->x * i->zoom) - (l->y * i->zoom)));
		ny = i->yplace - ((sqrt(2 / 3) * (l->z * i->zoom / i->deep)) -
				((1 / sqrt(9)) * (i->zoom * (l->x + l->y))));
		l->x = nx;
		l->y = ny;
		 l = l->next;
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

void		ft_push_back_t(t_co **list, t_use *u)
{
	t_co	*tmp;

	tmp = *list;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add_link(u);
	}
	else
		*list = add_link(u);
}

t_co *add_link(t_use *u)
{
	t_co *tmp;

	tmp = malloc(sizeof(t_co));
	if (tmp)
	{
		tmp->x = u->x_line;
		tmp->y = u->y_line;
		tmp->z = u->z_tmp;
		tmp->nb = u->nb_tmp;
		tmp->next = NULL;
	}
	return(tmp);
}

void goto_n(t_use *u, t_co **l, t_info *i, int n)
{
	t_co *tmp;
	int bi;
	int cnt;
	cnt = 0;
	bi = 0;
	tmp = *l;

	while(cnt < (u->y_line - 1))
	{
		if(tmp->nb == n)
		{
			u->xi = u->xf;
			u->yi = u->yf;
			u->xf = (tmp->x);
			u->yf = (tmp->y);
			if(bi > 0)
			{
				line_putter(i, u);
				cnt++;
			}
			bi++;
		}
		tmp = tmp->next;
	}
}

t_co *get_data(char *file, t_co *list, t_use *u)
{
	char *line;
	char **tmp;
	int fd;

	u->y_line = 0;
	fd = open(file, O_RDWR);
	while (get_next_line(fd, &line) > 0)
	{
		u->x_line = 0;
		u->nb_tmp = 0;
		tmp = ft_strsplit(line, ' ');
		while (tmp[u->x_line])
		{
			u->z_tmp = ft_atoi(tmp[u->x_line]);
			ft_push_back_t(&list, u);
			u->x_line++;
			u->nb_tmp++;
		}
		free(tmp);
		free(line);
		u->y_line++;
	}
	return(list);
}
