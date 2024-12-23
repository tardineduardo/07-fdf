/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:34:56 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/16 14:28:53 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"




int	main(int argc, char *argv[])
{
	mlx_t		*mlx;
	t_map		*map;
	t_sizes		*size;

	if (argc != 2)
		ft_print_error_and_exit("Error: invalid number of arguments.\n", 1);
	ft_parse(argv[1], &map);
	if (!map->points)
		return (ft_printf("Error parsing file.\n", 1));
	ft_inits(&mlx, &size, &map);
	ft_launch_iso_map(map->points, map, map->img, &mlx);
	
	ft_init_hooks(&mlx, &map, &size);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	free(map->points);
	free(map);
	free(size);
	return (EXIT_SUCCESS);
}
