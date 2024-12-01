#include "fdf.h"






int main(int argc, char *argv[])
{
    // mlx_t	*mlx;
    t_map	***parsed;
    // int32_t	screen_width;
    // int32_t	screen_height;

    if (argc != 2)
        return (1);

	// ft_get_monitor_resolution(&screen_width, &screen_height);

    // mlx = mlx_init(screen_width*7/10, screen_height*7/10, "Eduardo's FdF", true);
    // if (!mlx)
    //    ft_error();

    // mlx_image_t *img = mlx_new_image(mlx, 256, 256);
    // if (!img)
    //     return (EXIT_FAILURE);

    // mlx_image_to_window(mlx, img, (screen_width*7/10 - 256) / 2, (screen_height*7/10 - 256) / 2);
    // mlx_loop(mlx);

	parsed = ft_parse(argv[1]);
	ft_debug_print_2D_struct(&parsed);
	ft_free_map(parsed);
    // mlx_terminate(mlx);

    return (EXIT_SUCCESS);
}





