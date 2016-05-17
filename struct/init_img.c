#include "fdf.h"

void init(t_info *info, t_use *u)
{
	info->color_r = 255;
	info->color_g = 255;
	info->color_b = 255;
	info->zoom = 5;
	info->xplace = HGT / 2;
	info->yplace = (WDT / 4);
	u->y_line = 0;
	u->nb_tmp = 0;
	info->deep = 10;
}

void init_co(t_use *u)
{
	u->xi = 0;
	u->yi = 0;
	u->xf = 0;
	u->yi = 0;
}

void			line_putter(t_info *i, t_use *u)
{
	int dx;
	int sx;
	int dy;
	int sy;
	int err;
	int e2;

	dx = abs((u->xf - u->xi));
	sx = u->xi < u->xf ? 1 : -1;
	dy = abs((u->yf - u->yi));
	sy = u->yi < u->yf ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	while (!(u->xi == u->xf && u->yi == u->yf))
	{
		put_pixel_to_image(u->xi, u->yi, i);
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			u->xi += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			u->yi += sy;
		}
	}
}

void			put_pixel_to_image(int x, int y, t_info *i)
{
	if (x >= 0 && y >= 0 && x < WDT && y < HGT)
	{

		i->img_ptr[(i->size_line * y) + (4 * x) + 2] = i->color_b;
		i->img_ptr[(i->size_line * y) + (4 * x) + 1] = i->color_g;
		i->img_ptr[(i->size_line * y) + (4 * x)] = i->color_r;
	}
}

void 	make_img(t_info *i, t_co *l, t_use * u)
{
	i->mlx_img = mlx_new_image(i->mlx, HGT, WDT);
	i->img_ptr = mlx_get_data_addr(i->mlx_img, &(i->bits_per_pixel), &(i->size_line), &(i->endian));
	init_co_list(l);
	modify_list(l, i);
	second_mapping(i, l, u);
	mlx_put_image_to_window(i->mlx, i->win, i->mlx_img, 0, 0);
	mlx_destroy_image(i->mlx, i->img_ptr);

}
