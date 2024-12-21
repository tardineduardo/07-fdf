/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:04:54 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/15 17:15:41 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_height(t_point *point, double increment)
{
	point->x_scr = point->x_scr * increment;
	point->y_scr = point->y_scr * increment;
}
