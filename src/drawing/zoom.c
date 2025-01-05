/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:15:32 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/23 18:34:59 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_zoom(t_map *m, mlx_t **mlx, int ydelta)
{
	if (ydelta > 0)
		m->zoom += 0.05;
	if (ydelta < 0)
		m->zoom -= 0.05;
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
