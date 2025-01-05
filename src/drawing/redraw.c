/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:30:08 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/23 20:30:49 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_redraw(t_map *m, mlx_t **mlx)
{
	ft_draw_solid_background(m->img, m->bg_color);
	ft_draw_vlines(m->img, m->points, m);
	ft_draw_hlines(m->img, m->points, m);
	mlx_image_to_window((*mlx), m->img, 0, 0);
	return ;
}
