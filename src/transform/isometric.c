/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:29:50 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/09 18:20:09 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_convert_to_isometric(t_point *p, t_map *m, mlx_image_t *i)
{
	(void)i;
	(void)m;
	(*p).x_scr = ((*p).x_wld - (*p).y_wld) * cos(30 * PI / 180);
	(*p).y_scr = ((*p).x_wld + (*p).y_wld) * sin(30 * PI / 180) - (*p).z_wld;
}
