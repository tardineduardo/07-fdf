#include "../fdf.h"

void ft_transform_map(t_point ****map, mlx_image_t *img, t_sizes *size)
{
    int a;
    int b;

    // Precompute the width and height of each square
    int square_width = img->width / size->map_w;   // Width of each square
    int square_height = img->height / size->map_h; // Height of each square

    // Precompute half-width and half-height for centering
    int square_half_width = square_width / 2;
    int square_half_height = square_height / 2;

    a = 0;
    while ((*map)[a])
    {
        b = 0;
        while ((*map)[a][b])
        {
            // Use precomputed values for efficiency
            (*map)[a][b]->x = b * square_width + square_half_width;
            (*map)[a][b]->y = a * square_height + square_half_height;

            // Debugging output
            ft_printf("[x = %i y = %i] ", (*map)[a][b]->x, (*map)[a][b]->y);

            b++;
        }
        ft_printf("\n");
        a++;
    }

    ft_debug_print_2D_struct(map);
}

void ft_transform_map_iso(t_point ****map, mlx_image_t *img, t_sizes *size)
{
    int a;
    int b;
    int prev_x;
    int prev_y;
    int scale;
    const double angle_x = 0.523599; // 30 degrees in radians
    const double angle_y = 0.523599; // 30 degrees in radians

    scale = img->height / (size->map_h * 2);

    a = 0;
    while ((*map)[a])
    {
        b = 0;
        while((*map)[a][b])
        {
            prev_x = b * scale;
            prev_y = a * scale;

            // Isometric projection
            (*map)[a][b]->x = (prev_x - prev_y) * cos(angle_x);
            (*map)[a][b]->y = (prev_x + prev_y) * sin(angle_y) ;

            // Center the projection
            (*map)[a][b]->x += img->width / 2;
            (*map)[a][b]->y += img->height / 3;

            ft_printf("[x = %i ", (*map)[a][b]->x);
            ft_printf("y = %i]", (*map)[a][b]->y);
            b++;
        }
        ft_printf("\n");
        a++;
    }
    ft_debug_print_2D_struct(map);
}