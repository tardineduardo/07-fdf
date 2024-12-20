/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:06:49 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/09 01:03:50 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_x_rot(t_point *point, t_map *map, mlx_image_t *i)
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

void	ft_y_rot(t_point *point, t_map *map, mlx_image_t *i)
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

void	ft_z_rot(t_point *point, t_map *map, mlx_image_t *i)
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

/*
rotate x
|1	0		0		|	| x	|
|0	cos(θ)  -sin(θ)	| *	| y	|
|0	sin(θ)   cos(θ)	| 	z	|

rotate y
|cos(θ)		0	sin(θ)	|	| x	|
|0			1	0		| *	| y	|
|-sin(θ)	0	cos(θ)	|	| z	|

rotate z
|cos(θ)	-sin(θ)	0	|	| x	|
|sin(θ)	cos(θ)	0	| *	| y	|
|0		0		1	|	| z	|

*/