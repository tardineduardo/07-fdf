/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_dim_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 02:53:05 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/23 20:55:04 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_launch_dim_map(t_point *point, t_map *m, mlx_image_t *img,
	mlx_t **mlx)
{
	m->rot_z = 270;
	m->rot_x = 0;
	m->rot_y = 0;
	m->extrusion = 1;
	m->zoom = 0.5;
	m->proj = ft_convert_to_dimetric;
	ft_apply_gradient_colors(m);
	ft_update_points_new(m, &ft_fit_to_image);
	ft_update_points_new(m, &ft_z_rot);
	ft_update_points_new(m, &ft_x_rot);
	ft_update_points_new(m, &ft_y_rot);
	ft_update_points(point, img, m, m->proj);
	ft_find_x_boundaries(&point, m);
	ft_find_y_boundaries(&point, m);
	m->x_scr_var = (img->width / 2.0) - ((m->max_x_scr + m->min_x_scr) / 2.0);
	m->y_scr_var = (img->height / 2.0) - ((m->max_y_scr + m->min_y_scr) / 2.0);
	ft_update_points(point, NULL, m, &ft_center_map_in_image);
	ft_draw_solid_background(m->img, m->bg_color);
	ft_draw_vlines(img, point, m);
	ft_draw_hlines(img, point, m);
	mlx_image_to_window((*mlx), m->img, 0, 0);
	return ;
}
