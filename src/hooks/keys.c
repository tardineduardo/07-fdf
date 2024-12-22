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

	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_S) && keydata.action == MLX_PRESS)
	{
		ft_extrude(hook->map, &hook->mlx, keydata.key);
	}
	if ((keydata.key == MLX_KEY_Z || keydata.key == MLX_KEY_X) && keydata.action == MLX_PRESS)
	{
		ft_zoom(hook->map, &hook->mlx, keydata.key);
	}






}
