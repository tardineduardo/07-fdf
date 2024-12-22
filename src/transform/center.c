#include "../fdf.h"

void ft_center_map_in_place(t_point *point, t_map *map, mlx_image_t *img)
{
    (void)img;
    double delta_x = point->x_scr - point->x_scr_old;
    double delta_y = point->y_scr - point->y_scr_old;
    
    point->x_scr = point->x_scr_old + delta_x + map->x_scr_var;
    point->y_scr = point->y_scr_old + delta_y + map->y_scr_var;
}

void ft_center_map_in_image(t_point *point, t_map *map, mlx_image_t *img)
{
    (void)img;
    point->x_scr += map->x_scr_var;
    point->y_scr += map->y_scr_var;
}

void ft_center(t_map *map)
{
    int i = 0;
    while (i < map->map_w *  map->map_h)
    {
        map->points[i].x_scr_old = map->points[i].x_scr;
        map->points[i].y_scr_old = map->points[i].y_scr;
        i++;
    }
    ft_find_x_boundaries(&map->points, map);
    ft_find_y_boundaries(&map->points, map);
    map->x_scr_var = (map->img->width / 2.0) - ((map->max_x_scr + map->min_x_scr) / 2.0);
    map->y_scr_var = (map->img->height / 2.0) - ((map->max_y_scr + map->min_y_scr) / 2.0);
    if (map->center_type == 1)
        ft_update_points_new(map, ft_center_map_in_place);
    else if (map->center_type == 2)
        ft_update_points_new(map, ft_center_map_in_image);
}