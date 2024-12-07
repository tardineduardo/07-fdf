#include "../fdf.h"


#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

void apply_isometric_transform(t_point *point)
{
    double x = point->x0;
    double y = point->y0;
    double z = point->z0;

    // Simple isometric projection
    point->x1 = (x - y) * cos(30 * PI / 180);
    point->y1 = (x + y) * sin(30 * PI / 180) - z;
}


void ft_transform_map(t_point ****map, mlx_image_t *img, t_sizes *size)
{
    int a = 0;
    int scale = img->height / (size->map_h * 3);  // Adjusted scale
    int offset_x = img->width / 2;
    int offset_y = img->height / 3;  // Move it up a bit
    
    while ((*map)[a])
    {
        int b = 0;
        while ((*map)[a][b])
        {
            // Center the map around origin before transformation
            (*map)[a][b]->x0 = (b - size->map_w/2) * scale;
            (*map)[a][b]->y0 = (a - size->map_h/2) * scale;
            (*map)[a][b]->z0 = 2;  // Or your height value if you have one

            apply_isometric_transform((*map)[a][b]);

            // Apply offset after transformation
            int pixel_x = (int)((*map)[a][b]->x1) + offset_x;
            int pixel_y = (int)((*map)[a][b]->y1) + offset_y;

            // Draw a larger point for visibility
            for(int dx = -1; dx <= 1; dx++) {
                for(int dy = -1; dy <= 1; dy++) {
                    if(pixel_x + dx >= 0 && pixel_x + dx < img->width &&
                       pixel_y + dy >= 0 && pixel_y + dy < img->height) {
                        mlx_put_pixel(img, pixel_x + dx, pixel_y + dy, 0xFFFFFFFF);
                    }
                }
            }
            b++;
        }
        a++;
    }
}

void ft_transform_map_iso(t_point ****map, mlx_image_t *img, t_sizes *size)
{
    int a;
    int b;
    int prev_x;
    int prev_y;
    int height;
    int scale;
    // Standard isometric angles (30 degrees for true isometric)
    const double angle_x = 0.523599; // 30 degrees in radians
    const double angle_y = 0.523599; // 30 degrees in radians

    scale = img->height / (size->map_h * 4);
    a = 0;
    while ((*map)[a])
    {
        b = 0;
        while((*map)[a][b])
        {
            prev_x = b * scale;
            prev_y = a * scale;
            height = (*map)[a][b]->z0 * (scale / 10); // Adjust the division factor to control height impact

            // Isometric projection with height
            (*map)[a][b]->x1 = (prev_x - prev_y) * cos(angle_x);
            (*map)[a][b]->y1 = ((prev_x + prev_y) * sin(angle_y)) - height;

            // Center the projection
            (*map)[a][b]->x1 += img->width / 2;
            (*map)[a][b]->y1 += img->height / 3;

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