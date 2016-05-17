#include "fdf.h"

void second_mapping(t_info *i, t_co *l, t_use *u)
{
	int cnt;

	cnt = 0;
	map_maker(i, l, u);
	while(cnt < u->x_line)
	{
		init_co(u);
		goto_n(u, &l, i, cnt);
		cnt++;
	}
}

void map_maker(t_info *i, t_co *l, t_use *u)
{
	int count;

	while(l)
	{
		count = 1;
		while(count < (u->x_line))
		{
			u->xi = (l->x);
			u->yi = (l->y);
			if (l->next)
			{
				u->xf = (l->next->x);
				u->yf = (l->next->y);
				l = l->next;
			}
			line_putter(i, u);
			count++;
		}
		if(count == u->x_line)
		{
			line_putter(i, u);
			l = l->next;
			count = 0;
		}
	}
}
