/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:06:49 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/16 19:47:16 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_x_rot_w(t_point *point, t_map *map, mlx_image_t *i)
{
	double	radian;
	double	temp_y;
	double	temp_z;

	(void)i;
	radian = map->rot_x * (PI / 180.0);
	temp_y = (*point).y_wld * cos(radian) - (*point).z_wld * sin(radian);
	temp_z = (*point).y_wld * sin(radian) + (*point).z_wld * cos(radian);
	(*point).y_wld = temp_y;
	(*point).z_wld = temp_z;
}

void	ft_y_rot_w(t_point *point, t_map *map, mlx_image_t *i)
{
	double	radian;
	double	temp_x;
	double	temp_z;

	(void)i;
	radian = map->rot_y * (PI / 180.0);
	temp_x = (*point).x_wld * cos(radian) + (*point).z_wld * sin(radian);
	temp_z = -(*point).x_wld * sin(radian) + (*point).z_wld * cos(radian);
	(*point).x_wld = temp_x;
	(*point).z_wld = temp_z;
}

void	ft_z_rot_w(t_point *point, t_map *map, mlx_image_t *i)
{
	double	radian;
	double	temp_x;
	double	temp_y;

	(void)i;
	radian = map->rot_z * (PI / 180.0);
	temp_x = (*point).x_wld * cos(radian) - (*point).y_wld * sin(radian);
	temp_y = (*point).x_wld * sin(radian) + (*point).y_wld * cos(radian);
	(*point).x_wld = temp_x;
	(*point).y_wld = temp_y;
}
