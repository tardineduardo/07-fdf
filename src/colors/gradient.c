/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:39:19 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/22 22:17:50 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

typedef struct s_array_index
{
	int	start;
	int	end;
}	t_array_index;


void ft_apply_gradient_colors(t_map *map)
{
	int				total_steps;
	int				curr_step;
    pthread_t		th[4];
	t_array_index	array[4];

	



	total_steps = abs(map->maxz - map->minz); //total steps

	curr_step = map->maxz - total_steps - Z;





}


void ft_apply_original_colors(t_map *map)
{




}


void ft_terrain_colors(t_map *map)
{




}