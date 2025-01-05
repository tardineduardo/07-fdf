/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpolate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:00:37 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/23 20:16:22 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	ft_get_color(t_rgba_color *c, u_int32_t color)
{
	c->r = ft_get_r(color);
	c->g = ft_get_g(color);
	c->b = ft_get_b(color);
	c->a = ft_get_a(color);
}

uint32_t	ft_interpolate(u_int32_t start_color, u_int32_t end_color,
	int total_steps, int curr_step)
{
	t_rgba_color	start;
	t_rgba_color	end;
	t_rgba_color	new;
	double			ratio;

	ft_get_color(&start, start_color);
	ft_get_color(&end, end_color);
	ratio = (double)curr_step / (double)total_steps;
	new.r = (uint8_t)(start.r + (end.r - start.r) * ratio);
	new.g = (uint8_t)(start.g + (end.g - start.g) * ratio);
	new.b = (uint8_t)(start.b + (end.b - start.b) * ratio);
	new.a = (uint8_t)(start.a + (end.a - start.a) * ratio);
	new.rgba = ft_get_rgba(new.r, new.g, new.b, new.a);
	return (new.rgba);
}
