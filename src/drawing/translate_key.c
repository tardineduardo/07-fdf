/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 02:53:05 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/28 19:43:27 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_translate_key(t_map *m, mlx_t **mlx, int key)
{
	int	i;
	int	total_size;
	int	translation_x;
	int	translation_y;

	translation_x = 0;
	translation_y = 0;
	if (key == MLX_KEY_6)
		translation_y = 10;
	else if (key == MLX_KEY_7)
		translation_y = -10;
	else if (key == MLX_KEY_8)
		translation_x = -10;
	else if (key == MLX_KEY_9)
		translation_x = 10;
	i = 0;
	total_size = m->map_w * m->map_h;
	while (i < total_size)
	{
		m->points[i].x_scr += translation_x;
		m->points[i].y_scr += translation_y;
		i++;
	}
	ft_redraw(m, mlx);
	return ;
}
