#include "../fdf.h"

void	ft_draw_solid_background(mlx_image_t *img, int color)
{
	uint32_t	i;
	uint32_t	j;

	i = 0;
	while (i < img->height)
	{
		j = 0;
		while (j < img->width)
		{
			mlx_put_pixel(img, j, i, color);
			j++;
		}
		++i;
	}
}
