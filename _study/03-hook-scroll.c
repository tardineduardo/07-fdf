#include "../src/fdf.h"

void my_scrollhook(double xdelta, double ydelta, void* param)
{
	// Simple up or down detection.
	if (ydelta > 0)
		puts("Up!");
	else if (ydelta < 0)
		puts("Down!");
	

}

// int32_t	main(void)
// {
// 	mlx_t* mlx;

// 	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
// 		return (EXIT_FAILURE);

// 	mlx_scroll_hook(mlx, &my_scrollhook, NULL);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }