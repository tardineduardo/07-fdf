

#include "../fdf.h"


void	ft_redraw(t_map *m, mlx_t **mlx)
{
	ft_draw_solid_background(m->img, m->bg_color);
	draw_vlines(m->img, m->points, m);
	draw_hlines(m->img, m->points, m);
	mlx_image_to_window((*mlx), m->img, 0, 0);
	return ;
}