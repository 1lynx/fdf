#include "fdf.h"

void second_mapping(t_info *i, t_co *l)
{
	int cnt;

	cnt = 0;
	map_maker(i, l);
	while(cnt < i->x_line)
	{
		init_co(i);
		goto_n(&l, i, cnt);
		cnt++;
	}
}

void map_maker(t_info *i, t_co *l)
{
	int count;

	while(l)
	{
		count = 1;
		while(count < (i->x_line))
		{
			i->xi = (l->x);
			i->yi = (l->y);
			if (l->next)
			{
				i->xf = (l->next->x);
				i->yf = (l->next->y);
				l = l->next;
			}
			line_putter(i);
			count++;
		}
		if(count == i->x_line)
		{
			line_putter(i);
			l = l->next;
			count = 0;
		}
	}
}
