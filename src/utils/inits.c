/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 03:02:21 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/23 21:21:29 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	ft_free_resources(mlx_t **mlx, t_sizes **size, t_map **map,
	t_hook_param **hooks)
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
	if (*hooks)
		free(*hooks);
	return ;
}

void	ft_inits(mlx_t **mlx, t_sizes **size, t_map **m, t_hook_param **hooks)
{
	*size = ft_calloc(1, sizeof(t_sizes));
	if (!(*size))
		return (ft_free_resources(mlx, size, m, hooks));
	*hooks = ft_calloc(1, sizeof(t_hook_param));
	if (!(*hooks))
		return (ft_free_resources(mlx, size, m, hooks));
	ft_get_monitor_resolution(*size);
	ft_set_win_and_img_sizes(*size);
	*mlx = mlx_init((*size)->win_w, (*size)->win_h, "Eduardo's FdF", false);
	if (!mlx)
	{
		ft_error();
		ft_free_resources(mlx, size, m, hooks);
		return ;
	}
	(*m)->img = mlx_new_image(*mlx, (*size)->img_w, (*size)->img_h);
	if (!(*m)->img)
	{
		ft_error();
		ft_free_resources(mlx, size, m, hooks);
		return ;
	}
	return ;
}
