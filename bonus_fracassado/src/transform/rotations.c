/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:35:04 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/16 19:44:35 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_apply_rotations(t_map *map, t_point *point)
{
    ft_x_rot(point, map->rot_x);
    ft_y_rot(point, map->rot_y);
    ft_z_rot(point, map->rot_z);

}
