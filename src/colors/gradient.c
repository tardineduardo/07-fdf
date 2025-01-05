/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:39:19 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/23 20:15:29 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_apply_gradient_colors(t_map *map)
{
	int	i;
	int	total_size;

	i = 0;
	total_size = map->map_w * map->map_h;
	while (i < total_size)
	{
		map->points[i].rgba = ft_interpolate(map->gradient_start_color,
				map->gradient_end_color, map->deltaz, map->points[i].z_map);
		i++;
	}
}

void	ft_apply_original_colors(t_map *map)
{
	int	i;
	int	total_size;

	i = 0;
	total_size = map->map_w * map->map_h;
	while (i < total_size)
	{
		map->points[i].rgba = map->points[i].rgba_original;
		i++;
	}
	map->bg_color = 0x000000FF;
}
