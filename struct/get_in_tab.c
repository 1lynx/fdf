#include "fdf.h"


int	count_col(char **tab, t_info *s)
{
	int i;
	i = 0;
	while (tab[i])
		i++;
	s->y_lines = i;
	return (i);
}

int	count_line(char *av)
{
	int fd;
	char *line;
	int i;

	i = 0;
	if ((fd = open(av, O_RDONLY)) > 0)
	{
		while (get_next_line(fd, &line) > 0)
			i++;
		close(fd);
    return (i);
	}
	else
		return (-1);
}

int		*get_int_tab(char *str, t_info *s)
{
	int i;
	char **tmp;
	int *tab = NULL;

	i = 0;
	tmp = ft_strsplit(str, ' ');
	tab = (int *)malloc(sizeof(int) * count_col(tmp, s));
	while (tmp[i])
	{
		tab[i] = ft_atoi(tmp[i]);
		i++;
	}
	return(tab);
}
