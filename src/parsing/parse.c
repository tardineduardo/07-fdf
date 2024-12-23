/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 04:37:24 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/22 20:14:55 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	ft_fill_point(char *pointstr, t_point *point)
{
	char	*charcolor;
	char	*save_data;

	point->z_map = ft_atoi(ft_strtok_r(pointstr, ",", &save_data));
	charcolor = ft_strtok_r(NULL, ",", &save_data);
	if (charcolor)
		point->rgba = (int)ft_atohx(charcolor);
	else
		point->rgba = 0xFFFFFFFF;
}

static void	ft_fill_array(char *content, t_point *point, t_file *fdf)
{
	int		line;
	int		col;
	int		i;
	char	*linestr;
	char	*pointstr;

	line = 0;
	linestr = ft_strtok_r(content, "\n", &fdf->save_line);
	while (line < fdf->lines && linestr != NULL)
	{
		col = 0;
		pointstr = ft_strtok_r(linestr, " ", &fdf->save_point);
		while (col < fdf->cols && pointstr != NULL)
		{
			i = line * fdf->cols + col;
			point[i].x_map = col;
			point[i].y_map = line;
			ft_fill_point(pointstr, &point[i]);
			pointstr = ft_strtok_r(NULL, " ", &fdf->save_point);
			col++;
		}
		linestr = ft_strtok_r(NULL, "\n", &fdf->save_line);
		line++;
	}
}

/* Counts lines and colums; trimm empty lines and validate width. */
static void	ft_count_trimm_and_validate(char *str, t_file *fdf)
{
	char	*copy;
	char	*line;
	char	*point;
	int		col_check;

	ft_init_count(str, fdf, &col_check);
	copy = ft_strdup(str);
	// error_ckeck
	line = ft_strtok_r(copy, "\n", &fdf->save_line);
	while (line != NULL)
	{
		col_check = 0;
		point = ft_strtok_r(line, " ", &fdf->save_point);
		while (point != NULL)
		{
			col_check++;
			point = ft_strtok_r(NULL, " ", &fdf->save_point);
		}
		if (fdf->cols != col_check)
			ft_error_free_and_exit(copy, "Irregular width.\n", EXIT_FAILURE);
		fdf->lines++;
		line = ft_strtok_r(NULL, "\n", &fdf->save_line);
	}
	free(copy);
	return ;
}

void	ft_parse(char *filename, t_map **map)
{
	t_file	fdf;
	char	*content;

	*map = ft_calloc(1, sizeof(t_map));
	if (!map)
		ft_print_error_and_exit("Malloc error.\n", EXIT_FAILURE);
	content = ft_fn_to_str(filename);
	if (!content)
	{
		free(*map);
		exit(EXIT_FAILURE);
	}
	ft_count_trimm_and_validate(content, &fdf);
	(*map)->points = ft_calloc(fdf.lines * fdf.cols, sizeof(t_point));
	ft_fill_array(content, (*map)->points, &fdf);
	(*map)->map_w = fdf.cols;
	(*map)->map_h = fdf.lines;
	ft_min_max_z(map);
	free(content);
}
