/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 02:53:05 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/28 21:23:14 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_change_view(t_map *m, mlx_t **mlx, int key)
{
	if (key == MLX_KEY_I)
		m->proj = &ft_convert_to_isometric;
	if (key == MLX_KEY_D)
		m->proj = &ft_convert_to_dimetric;
	if (key == MLX_KEY_T)
		m->proj = &ft_convert_to_top;
	ft_update_points(m->points, m->img, m, m->proj);
	m->center_type = 1;
	ft_center(m);
	ft_draw_solid_background(m->img, m->bg_color);
	ft_draw_vlines(m->img, m->points, m);
	ft_draw_hlines(m->img, m->points, m);
	mlx_image_to_window((*mlx), m->img, 0, 0);
	return ;
}
