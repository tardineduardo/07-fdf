/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:01:56 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/06 22:55:59 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/fdf.h"

void apply_isometric_matrix(t_point *point)
{
    double matrix[4][4] = {
        {0.707,		0.408,	0.577,	0.000},
        {0.000,		0.866,	-0.500,	0.000},
        {-0.707,	0.408,	0.577,	0.000},
        {0.000,		0.000,	0.000,	1.000}
    };

    double x = point->x0;
    double y = point->y0;
    double z = point->z0;

    point->x1 = x * matrix[0][0] + y * matrix[0][1] + z * matrix[0][2] + matrix[0][3];
    point->y1 = x * matrix[1][0] + y * matrix[1][1] + z * matrix[1][2] + matrix[1][3];
    point->z1 = x * matrix[2][0] + y * matrix[2][1] + z * matrix[2][2] + matrix[2][3];
}
