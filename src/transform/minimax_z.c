/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimax_z.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:49:02 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/10 05:15:39 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_find_max_min_height(t_point *point, t_map **map)
{
	int	i;
	int	total_size;

	total_size = (*map)->map_w * (*map)->map_h;
	(*map)->minz = INT_MAX;
	(*map)->maxz = INT_MIN;
	i = 0;
	while (i < total_size)
	{
		if (point[i].z_map < (*map)->minz)
			(*map)->minz = point[i].z_map;
		if (point[i].z_map > (*map)->maxz)
			(*map)->maxz = point[i].z_map;
		i++;
	}
	return ;
}
