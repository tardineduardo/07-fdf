/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:34:56 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/22 20:22:58 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_hooks(mlx_t **mlx, t_map **map, t_sizes **sizes)
{
	t_hook_param	*hooks;
	
	hooks = ft_calloc(1, sizeof(t_hook_param));
	hooks->mlx = *mlx;
	hooks->map = *map;
	hooks->sizes = *sizes;	
	hooks->img = (*map)->img;
	hooks->points = (*map)->points;

	mlx_key_hook(hooks->mlx, &ft_key_hooks, hooks);
 	mlx_scroll_hook(hooks->mlx, &my_scrollhook, hooks);




}


int	main(int argc, char *argv[])
{
	mlx_t		*mlx;
	t_map		*map;
	t_sizes		*size;

	if (argc != 2)
		ft_print_error_and_exit("Error: invalid number of arguments.\n", 1);
	ft_printf("Parsing...");
	ft_parse(argv[1], &map);
	ft_printf("Done!\n");
	if (!map->points)
		return (ft_printf("Error parsing file.\n", 1));
	ft_inits(&mlx, &size, &map);
	ft_printf("Launching map...");
	ft_launch_iso_map(map->points, map, map->img, &mlx);
	ft_printf("Done!\n");

	ft_init_hooks(&mlx, &map, &size);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	free(map->points);
	free(map);
	free(size);
	return (EXIT_SUCCESS);
}
