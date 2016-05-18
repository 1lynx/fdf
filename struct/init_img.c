#include "fdf.h"

void init(t_info *i)
{
	i->color_r = 255;
	i->color_g = 255;
	i->color_b = 255;
	i->zoom = 5;
	i->xplace = HGT / 2;
	i->yplace = (WDT / 4);
	i->y_line = 0;
	i->nb_tmp = 0;
	i->deep = 5;
}

void init_co(t_info *i)
{
	i->xi = 0;
	i->yi = 0;
	i->xf = 0;
	i->yi = 0;
}

void			line_putter(t_info *i)
{
	int dx;
	int sx;
	int dy;
	int sy;
	int err;
	int e2;

	dx = abs((i->xf - i->xi));
	sx = i->xi < i->xf ? 1 : -1;
	dy = abs((i->yf - i->yi));
	sy = i->yi < i->yf ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	while (!(i->xi == i->xf && i->yi == i->yf))
	{
		put_pixel_to_image(i->xi, i->yi, i);
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			i->xi += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			i->yi += sy;
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

void 	make_img(t_info *i, t_co *l)
{
	i->mlx_img = mlx_new_image(i->mlx, HGT, WDT);
	i->img_ptr = mlx_get_data_addr(i->mlx_img, &(i->bits_per_pixel), &(i->size_line), &(i->endian));
	init_co_list(l);
	modify_list(l, i);
	second_mapping(i, l);
	mlx_put_image_to_window(i->mlx, i->win, i->mlx_img, 0, 0);
	mlx_destroy_image(i->mlx, i->img_ptr);

}
