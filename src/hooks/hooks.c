/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:02:36 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/21 14:29:51 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_key_hooks(mlx_key_data_t keydata, void *param)
{
	t_hook_param *hook = (t_hook_param *)param;

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(hook->mlx);

	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_S) && keydata.action == MLX_PRESS)
		ft_extrude(hook->map, &hook->mlx, keydata.key);
	if ((keydata.key == MLX_KEY_Z || keydata.key == MLX_KEY_X) && keydata.action == MLX_PRESS)
		ft_zoom(hook->map, &hook->mlx, keydata.key);
	if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT) && keydata.action == MLX_PRESS)
		ft_rotate_z(hook->map, &hook->mlx, keydata.key);
	if ((keydata.key == MLX_KEY_R) && keydata.action == MLX_PRESS)
		ft_launch_iso_map(hook->map->points, hook->map, hook->map->img, &hook->mlx);
	if (keydata.key == MLX_KEY_LEFT_SHIFT || keydata.key == MLX_KEY_RIGHT_SHIFT)
		hook->shift_pressed = (keydata.action != MLX_RELEASE);


}

void	ft_scroll_hooks(double xdelta, double ydelta, void *param)
{
	t_hook_param *hook = (t_hook_param *)param;

	if (hook->shift_pressed)
	{
		if (ydelta > 0)
			ft_extrude(hook->map, &hook->mlx, MLX_KEY_A);
		else if (ydelta < 0)
			ft_extrude(hook->map, &hook->mlx, MLX_KEY_S);
	}
	else
	{
		if (ydelta > 0)
			ft_zoom(hook->map, &hook->mlx, MLX_KEY_Z);
		else if (ydelta < 0)
			ft_zoom(hook->map, &hook->mlx, MLX_KEY_X);
	}
}


void	ft_init_hooks(mlx_t **mlx, t_map **map, t_sizes **sizes)
{
	t_hook_param	*hooks;
	
	hooks = ft_calloc(1, sizeof(t_hook_param));
	hooks->mlx = *mlx;
	hooks->map = *map;
	hooks->sizes = *sizes;	
	hooks->img = (*map)->img;
	hooks->points = (*map)->points;
	hooks->shift_pressed = false;


	mlx_key_hook(hooks->mlx, &ft_key_hooks, hooks);
 	mlx_scroll_hook(hooks->mlx, &ft_scroll_hooks, hooks);
}

