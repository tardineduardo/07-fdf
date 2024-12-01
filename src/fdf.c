#include "fdf.h"



int main(int argc, char *argv[])
{
    mlx_t	*mlx;
    t_map	***parsed;
    int32_t	screen_width;
    int32_t	screen_height;

    if (argc != 2)
        return (1);

	ft_get_monitor_resolution(&screen_width, &screen_height);

    mlx = mlx_init(screen_width*7/10, screen_height*7/10, "Eduardo's FdF", true);
    if (!mlx)
       ft_error();

	parsed = ft_parse(argv[1]);
	ft_transform_map(&parsed, screen_width, screen_height);

    // Create a new image of size 256x256
    mlx_image_t *img = mlx_new_image(mlx, 256, 256);
    if (!img)
        return (EXIT_FAILURE);

    uint32_t color = 0xFFFF0011; // Fully opaque red

    // Draw the top and bottom borders (horizontal lines)
    for (int x = 0; x < 256; x++)
    {
        ((uint32_t *)img->pixels)[0 * 256 + x] = color;          // Top border
        ((uint32_t *)img->pixels)[255 * 256 + x] = color;        // Bottom border
    }

    // Draw the left and right borders (vertical lines)
    for (int y = 0; y < 256; y++)
    {
        ((uint32_t *)img->pixels)[y * 256 + 0] = color;          // Left border
        ((uint32_t *)img->pixels)[y * 256 + 255] = color;        // Right border
    }

    // Place the image in the center of the window
    mlx_image_to_window(mlx, img, (screen_width*7/10 - 256) / 2, (screen_height*7/10 - 256) / 2);

    mlx_loop(mlx);
    mlx_terminate(mlx);
    free(parsed);

    return (EXIT_SUCCESS);
}




