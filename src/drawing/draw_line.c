/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 04:21:36 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/22 18:02:54 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_draw_line(mlx_image_t *img, t_point *start, t_point *end)
{
	t_line	line;
	u_int32_t color;

	line.x = start->x_scr;
	line.y = start->y_scr;
	line.delta_x = end->x_scr - start->x_scr;
	line.delta_y = end->y_scr - start->y_scr;
	if (fabs(line.delta_x) > fabs(line.delta_y))
		line.steps = fabs(line.delta_x);
	else
		line.steps = fabs(line.delta_y);
	line.x_inc = line.delta_x / line.steps;
	line.y_inc = line.delta_y / line.steps;
	line.i = 0;
	while (line.i <= line.steps)
	{
		if (line.x >= 0 && line.y >= 0 && line.x < img->width - 1 && line.y < img->height -1)
		{
			color = ft_interpolate(start->rgba, end->rgba, line.steps, line.i);
			mlx_put_pixel(img, round(line.x), round(line.y), color);
		}
		line.x += line.x_inc;
		line.y += line.y_inc;
		line.i++;
	}
}

