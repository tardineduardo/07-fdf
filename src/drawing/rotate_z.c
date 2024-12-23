/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_iso_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 02:53:05 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/21 15:17:24 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_rotate_z(t_map *m, mlx_t **mlx, int key)
{
	if (key == MLX_KEY_LEFT)
		m->rot_z += 5;
	else if (key == MLX_KEY_RIGHT)
		m->rot_z -= 5;
	ft_update_points_new(m, &ft_fit_to_image);
	ft_update_points_new(m, &ft_x_rot);
	ft_update_points_new(m, &ft_y_rot);
	ft_update_points_new(m, &ft_z_rot);
	ft_update_points_new(m, &ft_convert_to_isometric);
	m->center_type = 2;
	ft_center(m);
	ft_redraw(m, mlx);
	return ;
}