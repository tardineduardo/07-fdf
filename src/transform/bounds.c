/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 01:23:25 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/10 05:27:57 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_find_x_boundaries(t_point **point, t_map *map)
{
	int	i;
	int	total_size;

	map->max_x_scr = INT_MIN;
	map->min_x_scr = INT_MAX;
	i = 0;
	total_size = map->map_w * map->map_h;
	while (i < total_size)
	{
		if ((*point)[i].x_scr < map->min_x_scr)
			map->min_x_scr = (*point)[i].x_scr;
		if ((*point)[i].x_scr > map->max_x_scr)
			map->max_x_scr = (*point)[i].x_scr;
		i++;
	}
	return ;
}

void	ft_find_y_boundaries(t_point **point, t_map *map)
{
	int	i;
	int	total_size;

	map->max_y_scr = INT_MIN;
	map->min_y_scr = INT_MAX;
	i = 0;
	total_size = map->map_w * map->map_h;
	while (i < total_size)
	{
		if ((*point)[i].y_scr < map->min_y_scr)
			map->min_y_scr = (*point)[i].y_scr;
		if ((*point)[i].y_scr > map->max_y_scr)
			map->max_y_scr = (*point)[i].y_scr;
		i++;
	}
	return ;
}
