/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:31:04 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/23 20:11:48 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
		s = scale_w * map->zoom;
	else
		s = scale_h * map->zoom;
	(*point).x_wld = (double)(*point).x_map * s;
	(*point).y_wld = (double)(*point).y_map * s;
	(*point).z_wld = (double)(*point).z_map * s * map->extrusion;
}
