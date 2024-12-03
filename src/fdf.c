#include "fdf.h"

#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0xFF00
#define WHITE_PIXEL 0xFFFFFF

void ft_draw(mlx_image_t *img, t_sizes *size, t_map ***matrix)
{
	uint32_t x;
	uint32_t y;

	x = 30;
	y = 0;
	while (x < size->img_w)
	{
		y = 0;
		while (y < size->img_h)
		{
			mlx_put_pixel(img, x, y, RED_PIXEL);
			y++;
		}
	}


}



int main(int argc, char *argv[])
{
	mlx_t	*mlx;
	t_sizes	size;
	t_map	***matrix;

	if (argc != 2)
		return (1);

	matrix = ft_parse(argv[1]);
	if (!matrix)
		return (ft_printf("Error parsing file.\n", 1));

	ft_get_monitor_resolution(&size);
	ft_set_win_and_img_sizes(&size);

	mlx = mlx_init(size.win_w, size.win_h, "Eduardo's FdF", true);
	if (!mlx)
	   ft_error();

	mlx_image_t *img = mlx_new_image(mlx, size.img_w, size.img_h);
	if (!img)
		ft_error();

	ft_draw(img, &size, matrix);

	mlx_image_to_window(mlx, img, 0, 0);



	mlx_loop(mlx);


	mlx_terminate(mlx);

	ft_free_map(matrix);
	return (EXIT_SUCCESS);
}





//	ft_debug_print_2D_struct(&matrix);
