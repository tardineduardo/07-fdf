#include "../src/fdf.h"

static mlx_image_t	*g_img;

void	hook(void* param)
{
	mlx_t* mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_P))
		mlx_delete_image(mlx, g_img);
	for (int x = 0; x < g_img->width; x++)
		for(int y= 0; y < g_img->height; y++)
			mlx_put_pixel(g_img, x, y, rand() % RAND_MAX);
}

int32_t	main(void)
{


	mlx_t*    mlx;

	//mlx_set_setting(MLX_STRETCH_IMAGE, true);						// TODO: DOUBLE CLICK TO SWITCH FULL SCREEN


	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, 128, 128);
	mlx_image_to_window(mlx, g_img, 0, 0);
	mlx_loop_hook(mlx, &hook, mlx);


	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}