#include "../fdf.h"

void ft_fit_to_image(t_point ****map, mlx_image_t *img, t_sizes *size)
{
	int a;
	int b;

	a = 0;
	while ((*map)[a])
	{
		int b = 0;
		while ((*map)[a][b])
		{			
			(*map)[a][b]->x0 = ((*map)[a][b]->x0 * size->img_w) / size->map_w;
			(*map)[a][b]->y0 = ((*map)[a][b]->y0 * size->img_h) / size->map_h;
			(*map)[a][b]->z0 = 2;
			b++;
		}
		a++;
	}
}
