/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:04:54 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/09 01:31:15 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_extrude(t_point *point, double increment)
{
	point->x_scr = point->x_scr * increment;
	point->y_scr = point->y_scr * increment;
}
