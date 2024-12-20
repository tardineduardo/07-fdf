/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:58:35 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/10 05:42:14 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_put_points(t_point *p, t_map *m)
{
	int	i;
	int	max;

	max = (*m).map_w * (*m).map_h;
	i = 0;
	while (i < max)
	{
		printf("xm = %i, ym = %i, zm = %i\t|\t",
			p[i].x_map, p[i].y_map, p[i].z_map);
		printf("xw = %.2f, yw = %.2f, zw = %.2f\t|\t",
			p[i].x_wld, p[i].y_wld, p[i].z_wld);
		printf("xs = %i, ys = %i\n", p[i].x_scr, p[i].y_scr);
		i++;
	}
}
