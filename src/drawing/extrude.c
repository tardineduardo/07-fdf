/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:15:32 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/21 14:47:43 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_extrude(t_map *m, mlx_t **mlx, int key)
{
	if (key == MLX_KEY_A)
		m->extrusion += 0.05;
	else if (key == MLX_KEY_S)
		m->extrusion -= 0.05;
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
