#include "../fdf.h"




void ft_transform_map(t_point ****map, mlx_image_t *img)
{
	int	a;
	int	b;

	a = 0;
	while ((*map)[a])
	{
		b = 0;
		while((*map)[a][b])
		{
			(*map)[a][b]->x = b * img->width / (*map)[a][b]->map_w;
			ft_printf("[x = %i ", (*map)[a][b]->x);
			(*map)[a][b]->y = a * img->height / (*map)[a][b]->map_h;
			ft_printf("y = %i]", (*map)[a][b]->y);
			b++;
		}
		ft_printf("\n");
		a++;
	}
	ft_debug_print_2D_struct(map);	
}
