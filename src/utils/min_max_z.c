/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max_z.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:49:02 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/15 16:34:42 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_min_max_z(t_map **map)
{
	int	i;
	int	total_size;

	total_size = (*map)->map_w * (*map)->map_h;
	(*map)->minz = INT_MAX;
	(*map)->maxz = INT_MIN;
	i = 0;
	while (i < total_size)
	{
		if ((*map)->points[i].z_map < (*map)->minz)
			(*map)->minz = (*map)->points[i].z_map;
		if ((*map)->points[i].z_map > (*map)->maxz)
			(*map)->maxz = (*map)->points[i].z_map;
		i++;
	}
	return ;
}
