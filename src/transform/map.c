#include "../fdf.h"

void apply_isometric_matrix(t_point *point)
{
    double matrix[4][4] = {
        {0.707,		0.408,	0.577,	0.000},
        {0.000,		0.866,	-0.500,	0.000},
        {-0.707,	0.408,	0.577,	0.000},
        {0.000,		0.000,	0.000,	1.000}
    };

    double x = point->x0;
    double y = point->y0;
    double z = point->z0;

    point->x1 = x * matrix[0][0] + y * matrix[0][1] + z * matrix[0][2] + matrix[0][3];
    point->y1 = x * matrix[1][0] + y * matrix[1][1] + z * matrix[1][2] + matrix[1][3];
    point->z1 = x * matrix[2][0] + y * matrix[2][1] + z * matrix[2][2] + matrix[2][3];
}



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
            
			apply_isometric_matrix((*map)[a][b]);
			// Use precomputed values for efficiency
            // (*map)[a][b]->x0 = b * square_height + square_half_width;
            // (*map)[a][b]->y0 = a * square_height + square_half_height;

            // // Debugging output
            // ft_printf("[x = %i y = %i] ", (*map)[a][b]->x0, (*map)[a][b]->y0);

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
            (*map)[a][b]->x0 = (prev_x - prev_y) * cos(angle_x);
            (*map)[a][b]->y0 = (prev_x + prev_y) * sin(angle_y) ;

            // Center the projection
            (*map)[a][b]->x0 += img->width / 2;
            (*map)[a][b]->y0 += img->height / 3;

            ft_printf("[x = %i ", (*map)[a][b]->x0);
            ft_printf("y = %i]", (*map)[a][b]->y0);
            b++;
        }
        ft_printf("\n");
        a++;
    }
    ft_debug_print_2D_struct(map);
}




// void ft_transform_map_iso(t_point ****map, mlx_image_t *img, t_sizes *size)
// {
//     int a;
//     int b;
//     int prev_x;
//     int prev_y;
//     int scale;
//     const double angle_x = 0.523599; // 30 degrees in radians
//     const double angle_y = 0.523599; // 30 degrees in radians

//     scale = img->height / (size->map_h * 2);

//     a = 0;
//     while ((*map)[a])
//     {
//         b = 0;
//         while((*map)[a][b])
//         {
//             prev_x = b * scale;
//             prev_y = a * scale;

//             // Isometric projection
//             (*map)[a][b]->x1 = ((*map)[a][b]->x0 - (*map)[a][b]->y0) * cos(angle_x);
//             (*map)[a][b]->y1 = ((*map)[a][b]->x0 + (*map)[a][b]->y0) * sin(angle_y) ;

//             // Center the projection
//             (*map)[a][b]->x0 += img->width / 2;
//             (*map)[a][b]->y0 += img->height / 3;

//             ft_printf("[x = %i ", (*map)[a][b]->x0);
//             ft_printf("y = %i]", (*map)[a][b]->y0);
//             b++;
//         }
//         ft_printf("\n");
//         a++;
//     }
//     ft_debug_print_2D_struct(map);
// }