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
	t_point		*points;
	mlx_image_t	*img;

	if (argc != 2)
		ft_print_error_and_exit("Error: invalid number of arguments.\n", 1);
	points = ft_parse(argv[1], &map);
	if (!points)
		return (ft_printf("Error parsing file.\n", 1));
	ft_inits(&mlx, &img, &size, &map);
	ft_draw_solid_background(img, 0x000000DD);
	ft_draw_isometric_map(points, map, img);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_key_hook(mlx, &ft_key_hooks, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free(points);
	free(map);
	free(size);
	return (EXIT_SUCCESS);
}
