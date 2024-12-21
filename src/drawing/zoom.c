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

void	ft_zoom(t_map *m, mlx_t **mlx)
{
	ft_update_points(m->points, m->img, m, &ft_fit_to_image);
	ft_update_points(m->points, m->img, m, &ft_x_rot);
	ft_update_points(m->points, m->img, m, &ft_y_rot);
	ft_update_points(m->points, m->img, m, &ft_z_rot);
	ft_update_points(m->points, m->img, m, &ft_convert_to_isometric);

	// m->x_scr_var = (img->width / 2.0) - ((m->max_x_scr + m->min_x_scr) / 2.0);
	// m->y_scr_var = (img->height / 2.0) - ((m->max_y_scr + m->min_y_scr) / 2.0);
	ft_update_points(m->points, NULL, m, &ft_center_map_in_image);
	ft_redraw(m, mlx);

	
	return ;
}
