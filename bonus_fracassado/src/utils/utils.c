/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:33:37 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/16 19:34:35 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_update_points(t_point *p, mlx_image_t *img, t_map *map, t_ft func)
{
	int	i;
	int	total_size;
	t_point *debug;

	i = 0;
	total_size = map->map_w * map->map_h;
	while (i < total_size)
	{
		debug = &p[i];
		func(debug, map, img);
		i++;
	}
}

void	ft_update_points_rot(t_map *map, t_point *p, t_ft2 func)
{
	int	i;
	int	total_size;

	i = 0;
	total_size = map->map_w * map->map_h;
	while (i < total_size)
	{
		func(map, &p[i]);
		i++;
	}
}

void	ft_error(void)
{
	ft_dprintf(STDERR_FILENO, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int	ft_columns_in_first_line(char *str)
{
	char	*copy;
	char	*copy_tok;
	char	*line;
	int		count;

	copy = ft_strdup(str);
	line = ft_strtok_r(copy, "\n", &copy_tok);
	count = ft_split_count(line, ' ');
	free(copy);
	return (count);
}

void	ft_init_count(char *str, t_file *fdf, int *col_check)
{
	fdf->cols = ft_columns_in_first_line(str);
	fdf->lines = 0;
	*col_check = 0;
	return ;
}

double rad(double angle)
{
	return(angle * PI / 180);
}