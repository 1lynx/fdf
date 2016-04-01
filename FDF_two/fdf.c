#include <stdio.h>
#include "mlx.h"

int ft_key_print(int keycode, void *param)
{
	printf("key event : %d\n", keycode);
	return(0);
}

int main(void)
{
	void *mlx;
	void *win;
	int x = 50;
	int y = 50;
	
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "colin");
	while (y < 150)
	{
		x = 50;
	   while( x < 150 )
	   {
		   mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
		   x++;
	   }
	   y++;
	}
	mlx_key_hook(win, ft_key_print, 0);
	mlx_loop(mlx);
}
