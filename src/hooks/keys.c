/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:02:36 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/14 17:42:57 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// void	ft_key_hooks(mlx_key_data_t keydata, void *param)
// {
// 	mlx_t	*mlx;

// 	mlx = (mlx_t *)param;
// 	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
// 		mlx_close_window(mlx);
// }

void	ft_key_hooks(mlx_key_data_t keydata, void *param)
{
	t_hook_param *hook = (t_hook_param *)param;

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(hook->mlx);

	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		hook->map->height_scale	+= 0.2;
		ft_redraw(hook->map->points, hook->map, hook->map->img, &hook->mlx);
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		hook->map->height_scale	-= 0.2;
		ft_redraw(hook->map->points, hook->map, hook->map->img, &hook->mlx);
	}



	if (keydata.key == MLX_KEY_Q && keydata.action == MLX_PRESS)
	{
		hook->map->zoom += 0.25;
		ft_redraw(hook->map->points, hook->map, hook->map->img, &hook->mlx);
	}
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		hook->map->zoom -= 0.25;
		ft_redraw(hook->map->points, hook->map, hook->map->img, &hook->mlx);
	}



}
