#include "../fdf.h"

void ft_transform_map(t_map ***map, u_int32_t scr_w, u_int32_t scr_h)
{
	int	a;
	int	b;

	a = 0;
	while (map[a])
	{
		b = 0;
		while(map[a][b])
		{
			map[a][b]->x = ((float)a * (float)scr_w) / 100.0;
			map[a][b]->y = ((float)b * (float)scr_h) / 100.0;
			b++;
		}
		a++;
	}

	ft_debug_print_2D_struct(map);	
}
