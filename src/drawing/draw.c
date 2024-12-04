#include "../fdf.h"

void draw_lines(mlx_image_t *img, t_point ***point, t_sizes *sizes, uint32_t color)
{
	t_point *start;
	t_point *end;
	int a;
	int b;
	a = 0;
	b = 0;

	int wlen = point[a][b]->map_w;
	int hlen = point[a][b]->map_h;	
	while (a < wlen)
	{
		b = 0;
		while(b < hlen)
		{
			start = point[a][b];
			end = point[a][b + 1];			
			draw_line_xiaolim(img, start, end, 0xff000000);
		}
		a++;
	}   
}

void test(mlx_image_t *img, t_point ****map, t_sizes *size)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	int wlen = (*map)[a][b]->map_w;
	int hlen = (*map)[a][b]->map_h;	


	a = 0;
	while (a < hlen)
	{
		b = 0;
		while(b < wlen)
		{
			mlx_put_pixel(img, (*map)[a][b]->x, (*map)[a][b]->y, 0xfffffff);
			b++;
		}
		a++;
	}
}
