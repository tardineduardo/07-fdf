/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimetric.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:29:50 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/23 20:08:29 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_convert_to_dimetric(t_point *p, t_map *m, mlx_image_t *i)
{
	(void)i;
	(void)m;
	(*p).x_scr = ((*p).x_wld - (*p).y_wld)
		* cos(26.565 * PI / 180);
	(*p).y_scr = ((*p).x_wld + (*p).y_wld)
		* sin(26.565 * PI / 180) - (*p).z_wld;
}
