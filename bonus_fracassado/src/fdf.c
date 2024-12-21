/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:34:56 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/16 19:30:08 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

///bonus!!!!

void	ft_init_hooks1(mlx_t **mlx, t_map **map, t_sizes **sizes)
{
	t_hook_param	*hooks;
	
	hooks = ft_calloc(1, sizeof(t_hook_param));
	hooks->mlx = *mlx;
	hooks->map = *map;
	hooks->sizes = *sizes;	
	hooks->img = (*map)->img;
	hooks->points = (*map)->points;

	mlx_key_hook(hooks->mlx, &ft_key_hooks, hooks);




}


int	main(int argc, char *argv[])
{
	mlx_t		*mlx;
	t_map		*map;
	t_sizes		*size;

	if (argc != 2)
		ft_print_error_and_exit("Error: invalid number of arguments", 1);
	ft_parse(argv[1], &map);
	if (!map->points)
		return (ft_printf("Error parsing file.\n", 1));
	ft_inits(&mlx, &size, &map);

	mlx_image_t *menu;
	menu = mlx_new_image(mlx, 250, size->win_h - 10);
	ft_draw_solid_background(menu, 0x222222FF);
	mlx_image_to_window(mlx, menu, 5, 5);

	ft_launch_iso_map(map->points, map, map->img, mlx);
	ft_init_hooks1(&mlx, &map, &size);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free(map->points);
	free(map);
	free(size);
	return (EXIT_SUCCESS);
}
