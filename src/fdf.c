#include "fdf.h"

int main(int argc, char *argv[])
{
	mlx_t	*mlx;
	t_sizes	size;
	t_map	***matrix;

	if (argc != 2)
		return (1);

	matrix = ft_parse(argv[1]);
	//ft_debug_print_2D_struct(&matrix);

	ft_get_monitor_resolution(&size);
	ft_set_win_and_img_sizes(&size);
	//check_size_errors

	mlx = mlx_init(size.win_w, size.win_h, "Eduardo's FdF", true);
	if (!mlx)
	   ft_error();

	mlx_image_t *img = mlx_new_image(mlx, size.img_w, size.img_h);

	if (!img)
		ft_error();


	mlx_image_to_window(mlx, img, 0, 0);
	draw_grid(img, matrix, &size, 0xFFFFFF);

	mlx_loop(mlx);


	mlx_terminate(mlx);

	ft_free_map(matrix);
	return (EXIT_SUCCESS);
}





