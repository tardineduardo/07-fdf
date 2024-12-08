#include "../fdf.h"

static void	ft_fill_point_struct(char *point, t_point *map, t_file *fdf)
{
	char	*charcolor;
	char	*data;
	char	*save_data;

	map->z0 = ft_atoi(ft_strtok_r(point, " ", &save_data)); 
	charcolor = ft_strtok_r(NULL, " ", &save_data);
	if (charcolor)
	{
		map->rgba = (int)ft_atohx(charcolor);
		// map->r = ft_get_r(map->rgba);
		// map->g = ft_get_g(map->rgba);
		// map->b = ft_get_b(map->rgba);
		// map->b = ft_get_a(map->rgba);

	}
	return ;
}

static void	ft_fill_matrix(char *str, t_point ****map, t_file *fdf)
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
			ft_fill_point_struct(point, (*map)[a][b], fdf);
			(*map)[a][b]->x0 = b;
			(*map)[a][b]->y0 = a;
			point = ft_strtok_r(NULL, " ", &fdf->save_point);
			b++;
		}
		line = ft_strtok_r(NULL, "\n", &fdf->save_line);
		a++;
	}
}

static void	ft_allocate_matrix(t_point ****point, t_file *fdf)
{
	int	a;
	int	b;

	
	*point = ft_calloc(fdf->lines + 1, sizeof(t_point**));
	//error check
	a = 0;
	while (a < fdf->lines)
	{
		(*point)[a] = ft_calloc(fdf->cols + 1, sizeof(t_point*));
		//error check
		b = 0;
		while (b < fdf->cols)
		{
			(*point)[a][b] = ft_calloc(1, sizeof(t_point));
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

t_point ***ft_parse(char *filename, t_sizes	*size)
{
	t_point   ***point;
	t_file  fdf;
	char	*content;

	content = ft_fn_to_str(filename);
	if (!content)
		return (NULL);
	ft_count_trimm_and_validate(content, &fdf);
	ft_allocate_matrix(&point, &fdf);
	if (!point)
		return (NULL);
	ft_fill_matrix(content, &point, &fdf);
	size->map_w = fdf.cols;
	size->map_h = fdf.lines;	
	free(content);
	return (point);
}
