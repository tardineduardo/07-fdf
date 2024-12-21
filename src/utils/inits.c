/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 03:02:21 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/16 19:26:26 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"






static void ft_free_resources(mlx_t **mlx, t_sizes **size, t_map **map)
{
	if (*mlx || (*map)->img)
		mlx_terminate(*mlx);
	if (*map)
	{
		if ((*map)->points)
			free((*map)->points);
		free(*map);
	}
	if (*size)
		free(*size);
	return ;	
}

void	ft_inits(mlx_t **mlx, t_sizes **size, t_map **map)
{
	*size = ft_calloc(1, sizeof(t_sizes));
	if (!(*size))
		return (ft_free_resources(mlx, size, map));
	ft_get_monitor_resolution(*size);
	ft_set_win_and_img_sizes(*size);
	*mlx = mlx_init((*size)->win_w, (*size)->win_h, "Eduardo's FdF", false);
	if (!mlx)
	{
		ft_error();
		ft_free_resources(mlx, size, map);
		return; 
	}
	(*map)->img = mlx_new_image(*mlx, (*size)->img_w, (*size)->img_h);
	if (!(*map)->img)
	{
		ft_error();
		ft_free_resources(mlx, size, map);
		return; 
	}
	return ;
}
