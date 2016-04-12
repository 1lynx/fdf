#ifndef FDF_H
# define FDF_H
#include "libft/libft.h"
#include <mlx.h>
# define HGT 700
# define WDT 700

typedef struct	s_info
{
	void *mlx;
	void *win;
	int x;
	int y;
	int x_to;
	int y_to;
}				t_info;

int ft_key_print(int keycode, void *param);
void line_putter(t_info *info);


#endif
