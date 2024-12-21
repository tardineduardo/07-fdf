/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 02:53:05 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/16 00:24:05 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_redraw_map(t_point *point, t_map *m, mlx_image_t *img, mlx_t *mlx)
{
	ft_update_points(point, img, m, &ft_fit_to_image);
	ft_update_points_rot(m, point, &ft_apply_rotations);
	ft_update_points(point, img, m, &ft_convert_to_isometric);
	ft_find_x_boundaries(&point, m);
	ft_find_y_boundaries(&point, m);
	m->x_scr_var = (img->width / 2.0) - ((m->max_x_scr + m->min_x_scr) / 2.0);
	m->y_scr_var = (img->height / 2.0) - ((m->max_y_scr + m->min_y_scr) / 2.0);
	ft_update_points(point, NULL, m, &ft_translate);
	ft_draw_solid_background(img, 0x000000DD);
	draw_vlines(img, point, m);
	draw_hlines(img, point, m);
	mlx_image_to_window(mlx, img, 0, 0);
	return ;
}
