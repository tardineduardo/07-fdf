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

static void	ft_fill_struct(char *point, t_map ****map, int a, int b)
{
	char *data;
	char *save_data;

	(*map)[a][b]->z = ft_atoi(ft_strtok_r(point, " ", &save_data)); 
	(*map)[a][b]->color = ft_strtok_r(NULL, " ", &save_data);
	ft_fill_colors((*map)[a][b], (*map)[a][b]->color);
	return ;
}

static void	ft_fill_matrix(char *str, t_map ****map, t_file *fdf)
{
	int		a;
	int		b;
	char	*line;
	char	*point;

	a = 0;
	line = ft_strtok_r(str, "\n", &fdf->save_line);
	while (line != NULL)
	{
		b = 0;
		point = ft_strtok_r(line, " ", &fdf->save_point);
		while (point != NULL)
		{
			ft_fill_struct(point, map, a, b);
			point = ft_strtok_r(NULL, " ", &fdf->save_point);
			b++;
		}
		line = ft_strtok_r(NULL, "\n", &fdf->save_line);
		a++;
	}
}

static void	ft_allocate_matrix(t_map ****parsed, t_file *fdf)
{
	int	a;
	int	b;

	
	*parsed = ft_calloc(fdf->lines + 1, sizeof(t_map**));
	//error check
	a = 0;
	while (a < fdf->lines)
	{
		(*parsed)[a] = ft_calloc(fdf->cols + 1, sizeof(t_map*));
		//error check
		b = 0;
		while (b < fdf->cols)
		{
			(*parsed)[a][b] = ft_calloc(1, sizeof(t_map));
			//error check
			b++;
		}
		a++;
	}
	return ;
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
		line = strtok_r(NULL, "\n", &fdf->save_line);
	}
	free(copy);
	return ;
}

t_map ***ft_parse(char *filename)
{
	t_map   ***parsed;
	t_file  fdf;
	char	*content;

	content = ft_fn_to_str(filename);
	if (!content)
		return (NULL);
	ft_count_trimm_and_validate(content, &fdf);
	ft_allocate_matrix(&parsed, &fdf);
	if (!parsed)
		return (NULL);
	ft_fill_matrix(content, &parsed, &fdf);
	free(content);
	return (parsed);
}
