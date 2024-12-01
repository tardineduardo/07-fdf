#include "../src/fdf.h"

int32_t	main(void)
{
	//mlx_set_setting(MLX_STRETCH_IMAGE, true);						// TODO: DOUBLE CLICK TO SWITCH FULL SCREEN

	mlx_t* mlx = mlx_init(256, 256, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);

	mlx_image_t* img = mlx_new_image(mlx, 23, 128);					//OK, uma imagem só pode ser um quadrado idiota

	// Set the channels of each pixel in our image to the maximum byte value of 255. 
	ft_memset(img->pixels, 150, img->width * img->height * BPP);

	mlx_image_to_window(mlx, img, 100, 50);

	// Run the main loop and terminate on quit.  
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}