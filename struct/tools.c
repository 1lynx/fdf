#include "fdf.h"

void init(t_info *info)
{
	info->color_r = 255;
	info->color_g = 255;
	info->color_b = 255;
}

void			line_putter(t_info *i, int xi, int yi, int xf, int yf)
{
	int dx;
	int sx;
	int dy;
	int sy;
	int err;
	int e2;
	// int xi = a->x;
	// int yi = a->y;
	// int xf = a->next->x;
	// int yf = a->next->y;

	dx = ft_abs((xf - xi));
	sx = xi < xf ? 1 : -1;
	dy = ft_abs((yf - yi));
	sy = yi < yf ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	while (!(xi == xf && yi == yf))
	{
		put_pixel_to_image(xi, yi, i);
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			xi += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			yi += sy;
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

void 	make_img(t_info *info, t_co *list)
{
	info->mlx_img = mlx_new_image(info->mlx, HGT, WDT);
	info->img_ptr = mlx_get_data_addr(info->mlx_img, &(info->bits_per_pixel), &(info->size_line), &(info->endian));
	map_maker(info, list);
	mlx_put_image_to_window(info->mlx, info->win, info->mlx_img, 0, 0);
	mlx_destroy_image(info->mlx, info->img_ptr);
}
