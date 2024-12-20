/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 03:02:21 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/10 05:36:31 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	ft_free_resources(mlx_t **mlx, mlx_image_t **img, t_sizes **size,
	t_map **map)
{
	if (*mlx || *img)
		mlx_terminate(*mlx);
	if (*map)
		free(*map);
	if (*size)
		free(*size);
	return ;
}

void	ft_inits(mlx_t **mlx, mlx_image_t **img, t_sizes **size, t_map **map)
{
	*size = ft_calloc(1, sizeof(t_sizes));
	if (!(*size))
		return (ft_free_resources(mlx, img, size, map));
	ft_get_monitor_resolution(*size);
	ft_set_win_and_img_sizes(*size);
	*mlx = mlx_init((*size)->win_w, (*size)->win_h, "Eduardo's FdF", false);
	if (!mlx)
	{
		ft_error();
		ft_free_resources(mlx, img, size, map);
		return ;
	}
	*img = mlx_new_image((*mlx), (*size)->img_w, (*size)->img_h);
	if (!img)
	{
		ft_error();
		ft_free_resources(mlx, img, size, map);
		return ;
	}
	return ;
}
