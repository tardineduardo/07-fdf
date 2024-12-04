#include "../fdf.h"

void	ft_background(t_sizes *size, mlx_image_t *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size->win_h)
	{
		j = 0;
		while (j < size->win_w)
		{
			mlx_put_pixel(img, j++, i, color);
		}
		++i;
	}
}
