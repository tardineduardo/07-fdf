#include "../fdf.h"

void ft_get_monitor_resolution(t_sizes *size)
{
	mlx_t *get_resolution;

	mlx_set_setting(MLX_HEADLESS, true);
	get_resolution = mlx_init(100, 100, "Parsing screen resolution", true);
	if (!get_resolution)
		ft_error();
	mlx_get_monitor_size(0, &size->scr_w, &size->scr_h);
	mlx_terminate(get_resolution);
	mlx_set_setting(MLX_HEADLESS, false);
	return;
}