/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:35:04 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/08 22:38:03 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	apply_rotations(t_point *point, t_map *map, const char *order)
{
	int		i;
	double	rx;
	double	ry;
	double	rz;

	rx = map->rot_x * (PI / 180.0);
	ry = map->rot_y * (PI / 180.0);
	rz = map->rot_z * (PI / 180.0);
	i = 0;
	while (order[i] != '\0')
	{
		if (order[i] == 'X')
			rotate_x(point, rx);
		else if (order[i] == 'Y')
			rotate_y(point, ry);
		else if (order[i] == 'Z')
			rotate_z(point, rz);
		i++;
	}
}
