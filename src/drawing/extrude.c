/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extrude.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:15:32 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/23 18:34:54 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h" 

void	ft_extrude(t_map *m, mlx_t **mlx, int key)
{
	if (key == MLX_KEY_1)
		m->extrusion += 0.05;
	else if (key == MLX_KEY_2)
		m->extrusion -= 0.05;
	ft_update_points_new(m, &ft_fit_to_image);
	ft_update_points_new(m, &ft_x_rot);
	ft_update_points_new(m, &ft_y_rot);
	ft_update_points_new(m, &ft_z_rot);
	ft_update_points_new(m, m->proj);
	m->center_type = 2;
	ft_center(m);
	ft_redraw(m, mlx);
	return ;
}
