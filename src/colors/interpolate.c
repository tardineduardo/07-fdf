/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpolate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:00:37 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/22 18:38:14 by eduribei         ###   ########.fr       */
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

uint32_t ft_interpolate(u_int32_t start_color, u_int32_t end_color, int total_steps, int curr_step)
{
	t_rgba_color	start;
	t_rgba_color	end;
	t_rgba_color	new;

	ft_get_color(&start, start_color);
	ft_get_color(&end, end_color);

	new.r = (uint8_t)(start.r + (end.r - start.r) * ((float)curr_step / (float)total_steps));
	new.g = (uint8_t)(start.g + (end.g - start.g) * ((float)curr_step / (float)total_steps));
	new.b = (uint8_t)(start.b + (end.b - start.b) * ((float)curr_step / (float)total_steps));
	new.a = (uint8_t)(start.a + (end.a - start.a) * ((float)curr_step / (float)total_steps));
	new.rgba = ft_get_rgba(new.r, new.g, new.b, new.a);

	return (new.rgba);
}













