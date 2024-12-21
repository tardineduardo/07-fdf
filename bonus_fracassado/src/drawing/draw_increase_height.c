/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_increase_height.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 02:53:05 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/15 17:14:26 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_draw_dimetric_map(t_point *point, t_map *m, mlx_image_t *img, mlx_t *mlx)
{
	ft_update_points(point, img, m, &ft_convert_to_dimetric);

	ft_draw_solid_background(img, 0x000000DD);
	draw_vlines(img, point, m);
	draw_hlines(img, point, m);
	mlx_image_to_window(mlx, img, 0, 0);
	return ;
}
