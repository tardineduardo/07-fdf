/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:06:49 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/16 19:48:12 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_x_rot_s(t_point *point, double radian)
{
	double	temp_y;
	double	temp_z;

	temp_y = (*point).y_wld * cos(radian) - (*point).z_wld * sin(radian);
	temp_z = (*point).y_wld * sin(radian) + (*point).z_wld * cos(radian);
	(*point).x_scr = (*point).x_wld;
	(*point).y_scr = temp_y;
	(*point).z_wld = temp_z;
}

void	ft_y_rot_s(t_point *point, double radian)
{
	double	temp_x;
	double	temp_z;

	temp_x = (*point).x_wld * cos(radian) + (*point).z_wld * sin(radian);
	temp_z = -(*point).x_wld * sin(radian) + (*point).z_wld * cos(radian);
	(*point).x_scr = temp_x;
	(*point).y_scr = (*point).y_wld;
	(*point).z_wld = temp_z;
}

void	ft_z_rot_s(t_point *point, double radian)
{
	double	temp_x;
	double	temp_y;

	temp_x = (*point).x_wld * cos(radian) - (*point).y_wld * sin(radian);
	temp_y = (*point).x_wld * sin(radian) + (*point).y_wld * cos(radian);
	(*point).x_scr = temp_x;
	(*point).y_scr = temp_y;
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