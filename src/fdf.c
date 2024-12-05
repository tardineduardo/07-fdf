#include "fdf.h"




void	ft_background(t_sizes *size, mlx_image_t *img, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < size->img_h)
	{
		x = 0;
		while (x < size->img_w)
		{
			mlx_put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}



int main(int argc, char *argv[])
{
	mlx_t	*mlx;
	t_sizes	size;
	t_point	***point;

	if (argc != 2)
		return (1);

	point = ft_parse(argv[1], &size);
	if (!point)
		return (ft_printf("Error parsing file.\n", 1));

	ft_get_monitor_resolution(&size);
	ft_set_win_and_img_sizes(&size);

	mlx = mlx_init(size.win_w, size.win_h, "Eduardo's FdF", true);
	if (!mlx)
	   ft_error();

	mlx_image_t *img = mlx_new_image(mlx, size.img_w, size.img_h);
	if (!img)
		ft_error();

	ft_background(&size, img, 0xffff0000);
//	ft_transform_map(&point, img, &size);

	ft_transform_map_iso(&point, img, &size);
	draw_horizontal_lines(img, point, &size, 0xffffffff);
	draw_vertical_lines(img, point, &size, 0xffffffff);

	// draw_horizontal_lines(img, point, &size, 0xffffffff);
	// draw_vertical_lines(img, point, &size, 0xffffffff);


	test(img, &point, &size);

	mlx_image_to_window(mlx, img, 0, 0);



	mlx_loop(mlx);
	mlx_terminate(mlx);
	ft_free_map(point);
	return (EXIT_SUCCESS);
}





