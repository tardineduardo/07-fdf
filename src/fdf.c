#include "fdf.h"

#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0xFF00
#define WHITE_PIXEL 0xFFFFFF


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



int main(int argc, char *argv[])
{
	mlx_t	*mlx;
	t_sizes	size;
	t_point	***point;

	if (argc != 2)
		return (1);

	point = ft_parse(argv[1]);
	if (!point)
		return (ft_printf("Error parsing file.\n", 1));

	ft_get_monitor_resolution(&size);
	ft_set_win_and_img_sizes(&size);




	mlx = mlx_init(500, 500, "Eduardo's FdF", true);
	if (!mlx)
	   ft_error();

	mlx_image_t *img = mlx_new_image(mlx, 500, 500);
	if (!img)
		ft_error();

	ft_transform_map(&point, img);
	ft_debug_print_2D_struct(&point);

	ft_background(&size, img, 0xffc49678);
	test(img, &point, &size);
	//draw_lines(img, point, &size, 0xff000000);


	mlx_image_to_window(mlx, img, 0, 0);


	mlx_loop(mlx);
	mlx_terminate(mlx);
	ft_free_map(point);
	return (EXIT_SUCCESS);
}





