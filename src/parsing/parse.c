#include "../fdf.h"

static void ft_fill_colors(t_map *map, char *color)
{
	char *trimm;
	char *r;
	char *g;
	char *b;

	if (color)
	{
		if (ft_strnstr(color, "0x", 2) || ft_strnstr(color, "0X", 2))
			trimm = &color[2];
		r = ft_substr(trimm, 0, 2);	
		g = ft_substr(trimm, 2, 2);	
		b = ft_substr(trimm, 4, 2);	
		map->r = ft_atohx(r);
		map->g = ft_atohx(g);
		map->b = ft_atohx(b);
		ft_free(3, r, g, b);
	}
	else
	{
		map->color = NULL;
		map->r = -1;
		map->g = -1;
		map->b = -1;
	}
	return ;
}

static void	ft_fill_node(char *point, t_map ***map, int a, int b)
{
	char *data;
	char *save_data;

	map[a][b]->z = ft_atoi(ft_strtok_r(point, " ", &save_data)); 
	map[a][b]->color = ft_strtok_r(point, " ", &save_data);
	ft_fill_colors(map[a][b], map[a][b]->color);
	return ;
}

static void	ft_fill_matrix(char *str, t_map ***map, t_file *fdf)
{
	int		a;
	int		b;
	char	*line;
	char	*point;

	a = 0;
	line = ft_strtok_r(str, "\n", fdf->save_line);
	while (line != NULL)
	{
		b = 0;
		point = ft_strtok_r(line, " ", fdf->save_point);
		while (point != NULL)
		{
			ft_fill_struct(point, map, a, b);
			point = strtok_r(NULL, " ", fdf->save_point);
			b++;
		}
		line = strtok_r(NULL, "\n", fdf->save_line);
		a++;
	}
	free(str);
}

static void	ft_allocate_matrix(t_map ***parsed, t_file *fdf)
{
	int	a;

	*parsed = ft_calloc(fdf->line_count + 1, sizeof(t_map*));
	if (*parsed == NULL)
		return ;
	a = 0;
	while (a < fdf->line_count)
	{
		(*parsed)[a] = ft_calloc(fdf->column_count + 1, sizeof(t_map));
		if ((*parsed)[a] == NULL)
		{
			while (--a >= 0)
				free((*parsed)[a]);
			return ;
		}
		a++;
	}
	return ;
}

static void	ft_count_lines_and_cloumns(char *str, t_file *fdf)
{
	char	*line;
	char	*point;
	int		column_temp;

	column_temp = ft_columns_in_first_line(str);
	ft_init_zero(fdf, column_temp);
	line = strtok_r(str, "\n", fdf->save_line);
	while (line != NULL)
	{
		point = strtok_r(line, " ", fdf->save_point);
		while (point != NULL)
		{
			fdf->column_count++;
			point = strtok_r(NULL, " ", fdf->save_point);
		}
		if (fdf->column_count != column_temp)
			ft_print_error_and_exit("Error: irregular width.\n", EXIT_FAILURE);
		fdf->line_count++;
		line = strtok_r(NULL, "\n", fdf->save_line);
	}
	free(str);
}

t_map ***ft_parse(char *filename)
{
	t_map   ***parsed;
	t_file  fdf;
	char	*content;

	content = ft_parse_fd_to_string_void(filename);
	if (!content)
		return (NULL);
	ft_count_lines_and_cloumns(ft_strdup(content), &fdf);
	ft_allocate_matrix(parsed, &fdf);
	if (!parsed)
		return (NULL);
	ft_fill_matrix(content, parsed);
	free(content);
	return (parsed);
}
