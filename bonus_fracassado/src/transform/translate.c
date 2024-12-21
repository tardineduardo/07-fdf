/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:01:26 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/21 14:40:32 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_center_map_in_image(t_point *point, t_map *map, mlx_image_t *img)
{
	(void)img;
	(*point).x_scr += map->x_scr_var;
	(*point).y_scr += map->y_scr_var;
}
