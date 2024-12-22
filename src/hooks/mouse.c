/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:02:36 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/21 14:29:51 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void my_scrollhook(double xdelta, double ydelta, void* param)
{
	t_hook_param *hook = (t_hook_param *)param;

	if (ydelta > 0)
		ft_extrude(hook->map, &hook->mlx, 83);
	else if (ydelta < 0)
		ft_extrude(hook->map, &hook->mlx, 65);
	}




