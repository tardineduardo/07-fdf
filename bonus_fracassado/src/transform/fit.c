/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:31:04 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/21 14:29:51 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static double	ft_adjust_z(t_map *map, t_point *point, double s)
{
	int	map_dim;

	map_dim = lowest(map->map_w, map->map_h);
	if (map->maxz > map_dim)
	{
		if (map->maxz == map->minz)
			return ((double)(*point).z_map * s);
		map->extrusion = (double)map_dim / ((double)map->maxz - map->minz);
		return ((double)((*point).z_map - map->minz) * map->extrusion * s);
	}
	else
		return ((double)(*point).z_map * s);
}

void	ft_fit_to_image(t_point *point, t_map *map, mlx_image_t *img)
{
	double	s;
	double	scale_w;
	double	scale_h;

	if (map->map_w == 0 || map->map_h == 0)
		return ;
	scale_w = (double)img->width / map->map_w;
	scale_h = (double)img->height / map->map_h;
	if (scale_w < scale_h)
		s = scale_w * 0.5;
	else
		s = scale_h * 0.5;
	(*point).x_wld = (double)(*point).x_map * s;
	(*point).y_wld = (double)(*point).y_map * s;
	(*point).z_wld = ft_adjust_z(map, point, s);
}
