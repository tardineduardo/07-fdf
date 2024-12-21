#include "../fdf.h"

void	ft_key_hooks(mlx_key_data_t keydata, void *param)
{
	t_hook_param *hook = (t_hook_param *)param;

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(hook->mlx);

	if (keydata.key == MLX_KEY_Q && keydata.action == MLX_PRESS)
	{
		hook->map->order = "Z";
		hook->map->rot_z += 0.0174532925;
		ft_redraw_map(hook->points, hook->map, hook->img, hook->mlx);
	}

	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		hook->map->order = "Z";
		hook->map->rot_z -= 0.0174532925;
		ft_redraw_map(hook->points, hook->map, hook->img, hook->mlx);
	}

	if (keydata.key == MLX_KEY_X && keydata.action == MLX_PRESS)
	{
		hook->map->order = "X";
		hook->map->rot_x += 0.0174532925;
		ft_redraw_map(hook->points, hook->map, hook->img, hook->mlx);
	}

	if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
	{
		hook->map->order = "X";
		hook->map->rot_x -= 0.0174532925;
		ft_redraw_map(hook->points, hook->map, hook->img, hook->mlx);
	}

	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		hook->map->order = "Y";
		hook->map->rot_y += 0.0174532925;
		ft_redraw_map(hook->points, hook->map, hook->img, hook->mlx);
	}

	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		hook->map->order = "Y";
		hook->map->rot_y -= 0.0174532925;
		ft_redraw_map(hook->points, hook->map, hook->img, hook->mlx);
	}
}



