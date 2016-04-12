#include "fdf.h"
#include <stdio.h>
#include "mlx.h"

int ft_key_print(int keycode, void *param)
{
	param = 0;
	printf("key ievent : %d\n", keycode);
	return(0);
}

void line_putter(t_info *info) 
{
	int dx;
	int dy;
	int cumul;
	int x;
	int y;
  	int x_i;
  	int y_i;

  	x = info->x;
 	y = info->y;
 	x_i = info->x_to;
 	y_i = info->y_to;

 	dx = x_i - x;
  	dy = y_i - y;
  	cumul = dx / 2 ;
  	while(x <= x_i) 
  	{
   	 	cumul += dy ;
    	if(cumul >= dx) 
    	{
      		cumul -= dx;
      		y += 1; 
      	}
		mlx_pixel_put(info->mlx, info->win, x, y, 0xFFFFFF);
		x++;
	}
}


int main(void)
{
	t_info list;

	list.x = 0;
	list.y = 0;
	list.x_to = 700;
	list.y_to = 700;

	list.mlx = mlx_init();
	list.win = mlx_new_window(list.mlx, HGT, WDT, "colin");

	line_putter(&list);

	// while(y < 151)
	// {
	// 	while(x < 300)
	// 	{
	// 		mlx_pixel_put(list.mlx, list.win, x, y, 0xFFFFFF);
	// 		x++;
	// 	}
	// 	y++;
	// }

	mlx_key_hook(list.win, ft_key_print, 0);
	// mlx_string_put(list.mlx, list.win, 0, 0, 0xFFFFFF, text);
	mlx_loop(list.mlx);
}
