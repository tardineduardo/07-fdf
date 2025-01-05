/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:35:34 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/23 20:07:32 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_set_color_pallet_1(t_map *map)
{
	map->gradient_start_color = 0x9d29a6FF;
	map->gradient_end_color = 0x02d2688FF;
	map->bg_color = 0x1e1824FF;
	ft_apply_gradient_colors(map);
}

void	ft_set_color_pallet_2(t_map *map)
{
	map->gradient_start_color = 0x0B3D91FF;
	map->gradient_end_color = 0xFFFFFFFF;
	map->bg_color = 0x090B2BFF;
	ft_apply_gradient_colors(map);
}

void	ft_set_color_pallet_3(t_map *map)
{
	map->gradient_start_color = 0x2D5A27FF;
	map->gradient_end_color = 0xE8D82AFF;
	map->bg_color = 0x1A2F17FF;
	ft_apply_gradient_colors(map);
}

void	ft_set_color_pallet_4(t_map *map)
{
	map->gradient_start_color = 0x8B0000FF;
	map->gradient_end_color = 0xFFB266FF;
	map->bg_color = 0x1A0F0FFF;
	ft_apply_gradient_colors(map);
}

void	ft_change_color_hooks(t_map *map, mlx_t *mlx, int key)
{
	if (key == MLX_KEY_F5)
		ft_apply_original_colors(map);
	if (key == MLX_KEY_F1)
		ft_set_color_pallet_1(map);
	if (key == MLX_KEY_F2)
		ft_set_color_pallet_2(map);
	if (key == MLX_KEY_F3)
		ft_set_color_pallet_3(map);
	if (key == MLX_KEY_F4)
		ft_set_color_pallet_4(map);
	ft_redraw(map, &mlx);
}
