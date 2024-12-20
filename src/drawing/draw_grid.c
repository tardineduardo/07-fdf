/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:55:09 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/10 00:33:12 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_vlines(mlx_image_t *img, t_point *p, t_map *m)
{
	int		line;
	int		col;
	t_point	*start;
	t_point	*end;

	line = 0;
	while (line < m->map_h - 1)
	{
		col = 0;
		while (col < m->map_w)
		{
			start = &p[m->map_w * line + col];
			end = &p[m->map_w * (line + 1) + col];
			ft_draw_line(img, start, end);
			col++;
		}
		line++;
	}
}

void	draw_hlines(mlx_image_t *img, t_point *p, t_map *m)
{
	int		line;
	int		col;
	t_point	*start;
	t_point	*end;

	line = 0;
	while (line < m->map_h)
	{
		col = 0;
		while (col < m->map_w - 1)
		{
			start = &p[m->map_w * line + col];
			end = &p[(m->map_w * line + col) + 1];
			ft_draw_line(img, start, end);
			col++;
		}
		line++;
	}
}
