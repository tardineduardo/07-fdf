#include "../fdf.h"

void draw_horizontal_lines(mlx_image_t *img, t_point ***point, t_sizes *size, uint32_t color)
{
    t_point *start;
    t_point *end;
    int x;
    int y;

    y = 0;
    while (y < size->map_h)
    {
        x = 0;
        while (x < size->map_w - 1) // Prevent out-of-bounds access
        {
            start = point[y][x];
            end = point[y][x + 1];
            draw_line_xiaolim(img, start, end, color);
			//draw_line_bresenham(img, start, end, color);
            x++; // Increment x to avoid an infinite loop
        }
        y++;
    }
}

void draw_vertical_lines(mlx_image_t *img, t_point ***point, t_sizes *size, uint32_t color)
{
    t_point *start;
    t_point *end;
    int x;
    int y;

    x = 0;
    while (x < size->map_w)  // Switch to columns first
    {
        y = 0;
        while (y < size->map_h - 1)  // Prevent out-of-bounds access
        {
            start = point[y][x];       // Current point
            end = point[y + 1][x];     // Point below
            draw_line_xiaolim(img, start, end, color);
			//draw_line_bresenham(img, start, end, color);


            y++;  // Move down the column
        }
        x++;  // Next column
    }
}





void test(mlx_image_t *img, t_point ****map, t_sizes *size)
{
	int	a;
	int	b;

	a = 0;
	while (a < size->map_h)
	{
		b = 0;
		while(b < size->map_w)
		{
			mlx_put_pixel(img, (*map)[a][b]->x, (*map)[a][b]->y, 0xffffffff);
			b++;
		}
		a++;
	}
}
