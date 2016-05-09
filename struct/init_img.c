#include "fdf.h"

void init(t_info *info, t_use *u)
{
	info->color_r = 255;
	info->color_g = 255;
	info->color_b = 255;
	info->zoom = 100;
	info->place = 100;
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

void 	make_img(t_info *info, t_co *list, t_use * use)
{
	info->mlx_img = mlx_new_image(info->mlx, HGT, WDT);
	info->img_ptr = mlx_get_data_addr(info->mlx_img, &(info->bits_per_pixel), &(info->size_line), &(info->endian));
	second_mapping(info, list, use);
	mlx_put_image_to_window(info->mlx, info->win, info->mlx_img, 0, 0);
	mlx_destroy_image(info->mlx, info->img_ptr);
}
