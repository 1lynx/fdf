#include "fdf.h"

void init_para(t_info *i)
{
	i->deep = 10;
	i->y_place = HGT / 4;
	i->x_place = WDT / 2;
	i->zoom = 10.0;
	i->mode = 0;
	i->flat = 0.80;
}

void init_window(t_info *i)
{

	i->mlx = mlx_init();
	i->win = mlx_new_window(i->mlx, WDT, HGT, "Window");
	init_para(i);
	put_calc_img(i);
	mlx_hook(i->win, 2, 3, ft_key_print, i);
	mlx_loop(i->mlx);
}

void put_calc_img(t_info *i)
{
	i->mlx_img = mlx_new_image(i->mlx, WDT, HGT);
	i->ptr_img = mlx_get_data_addr(i->mlx_img, &(i->bpp), &(i->sl), &(i->ian));
	print_map(i);
	mlx_put_image_to_window(i->mlx, i->win, i->mlx_img, 0, 0);
	menu(i);
	mlx_destroy_image(i->mlx, i->ptr_img);
}

void init_color(t_info *i, int z)
{
	/*bleu*/
	if (z >= -100 && z <= 2)
	{
		i->B = 51;
		i->G = 153;
		i->R = 255;
	}
	/*jaune*/
	if (z >= 3 && z <= 15)
	{
		i->B = 255;
		i->G = 204;
		i->R = 0;
	}
	/*vert*/
	if (z >= 16 && z <= 50)
	{
		i->B = 51;
		i->G = 255;
		i->R = 51;
	}
	/*marron*/
	if (z >= 51 && z <= 75)
	{
		i->B = 153;
		i->G = 102;
		i->R = 0;
	}
	/*blanc*/
	if (z >= 76 && z <= 150)
	{
		i->B = 255;
		i->G = 255;
		i->R = 255;
	}
}
