/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:02:36 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/28 21:22:14 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_key_hooks(mlx_key_data_t keydata, void *param)
{
	t_hook_param	*h;

	h = (t_hook_param *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PR)
		mlx_close_window(h->mlx);
	if (keydata.key == MLX_KEY_BACKSPACE && keydata.action == MLX_PR)
		ft_launch_iso_map(h->map->points, h->map, h->img, &h->mlx);
	if ((keydata.key == 73 || keydata.key == 68) && keydata.action == MLX_PR)
		ft_change_view(h->map, &h->mlx, keydata.key);
	if ((keydata.key == MLX_KEY_T) && keydata.action == MLX_PR)
		ft_launch_top_map(h->map->points, h->map, h->img, &h->mlx);
	if ((keydata.key >= 290 && keydata.key <= 294) && keydata.action == MLX_PR)
		ft_change_color_hooks(h->map, h->mlx, keydata.key);
	if ((keydata.key == 49 || keydata.key == 50) && keydata.action == MLX_PR)
		ft_extrude(h->map, &h->mlx, keydata.key);
	if ((keydata.key == 263 || keydata.key == 262) && keydata.action == MLX_PR)
		ft_rotate_z(h->map, &h->mlx, keydata.key);
	if ((keydata.key == 265 || keydata.key == 264) && keydata.action == MLX_PR)
		ft_rotate_x(h->map, &h->mlx, keydata.key);
	if ((keydata.key == 266 || keydata.key == 267) && keydata.action == MLX_PR)
		ft_rotate_y(h->map, &h->mlx, keydata.key);
	if ((keydata.key >= 54 && keydata.key <= 57) && keydata.action == MLX_PR)
		ft_translate_key(h->map, &h->mlx, keydata.key);
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_hook_param	*hook;

	hook = (t_hook_param *)param;
	(void)xdelta;
	if (ydelta > 0)
		ft_zoom(hook->map, &hook->mlx, ydelta);
	else if (ydelta < 0)
		ft_zoom(hook->map, &hook->mlx, ydelta);
}

void	ft_init_hooks(mlx_t **mlx, t_map **map, t_sizes **sizes,
	t_hook_param *hooks)
{
	hooks->mlx = *mlx;
	hooks->map = *map;
	hooks->sizes = *sizes;
	hooks->img = (*map)->img;
	hooks->points = (*map)->points;
	mlx_key_hook(hooks->mlx, &ft_key_hooks, hooks);
	mlx_scroll_hook(hooks->mlx, &my_scrollhook, hooks);
}
