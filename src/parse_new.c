#include "fdf.h"

// static void	ft_validate_digits(char **single, char **clean, t_map **parsed)
// {


// }


static void ft_init_empty_colors(char *color, t_map **parsed, size_t line, size_t col)
{
	parsed[line][col].color = NULL;
	parsed[line][col].r = -1;
	parsed[line][col].g = -1;
	parsed[line][col].b = -1;
}


static void ft_fill_colors(char *color, t_map **parsed, size_t line, size_t col)
{
	char *trimm;
	char *r;
	char *g;
	char *b;

	parsed[line][col].color = ft_strdup(color);
	if (ft_strnstr(color, "0x", 2) || ft_strnstr(color, "0X", 2))
		trimm = &color[2];
	r = ft_substr(trimm, 0, 2);	
	g = ft_substr(trimm, 2, 2);	
	b = ft_substr(trimm, 4, 2);	
	parsed[line][col].r = ft_atohx(r);
	parsed[line][col].g = ft_atohx(g);
	parsed[line][col].b = ft_atohx(b);
	free(r);
	free(g);
	free(b);
}

static void ft_fill_matrix(char **clean, t_map **parsed, t_file *fdf)
{
	size_t	line;
	size_t	col;
	char	**items;
	char	**single;

	line = 0;
	while (line < fdf->line_count)
	{
		items = ft_split_space(clean[line]);
		col = 0;
		while (col < fdf->column_count)
		{
			single = ft_split_char(items[col], ',');
			//ft_validate_digits(single);
			parsed[line][col].value = ft_atoi(single[0]);
			if (single[1])
			   ft_fill_colors(single[1], parsed, line, col);
			else
			   ft_init_empty_colors(single[1], parsed, line, col);
			ft_free_str_array(single);
			col++;
		}
		ft_free_str_array(items);
		line++;
	}
}

static t_map **ft_alloc_matrix(t_file *fdf)
{
	t_map **parsed;
	size_t i;

	parsed = malloc(fdf->line_count * sizeof(t_map *));
	if (!parsed)
		ft_print_error_and_exit("Error: Memory allocation failed.\n", 1);
	i = 0;
	while (i < fdf->line_count)
	{
		parsed[i] = malloc(fdf->column_count * sizeof(t_map));
		if (!parsed[i])
			ft_print_error_and_exit("Error: Memory allocation failed.\n", 1);
		i++;
	}
	return parsed;
}

static size_t	ft_count_and_validate_columns(char **clean, t_file *fdf)
{
	size_t	a;
	size_t	count_items;
	size_t	count_items_log;

	count_items_log = ft_split_count(clean[0], ' ');
	a = 1;
	while(a < fdf->line_count)
	{
		count_items = ft_split_count(clean[a], ' ');
		if (count_items != count_items_log)
		{
			ft_dprintf(STDERR_FILENO, "Error: irregular map width (line [%d] (0i)).\n", a);
			exit (1);
		}
		a++;
	}
	return (count_items);
}

static char **ft_trim_file(char *filename, t_file *fdf)
{
	size_t	i;
	int		file;
	char	*line;
	char	**clean;

	fdf->line_count = ft_count_nonempty_lines_fp(filename);
	clean = ft_calloc((fdf->line_count + 1), sizeof(char *));
	file = open(filename, O_RDONLY);
	if (file == -1)
		ft_perror_exit("Error opening file.\n", errno);	
	i = 0;
	while (i < fdf->line_count)
	{
		line = get_next_line(file);
		if (!line)
			break;
		clean[i] = ft_strtrim(line, " \n");
		free(line);
		i++;
	}
	close(file);
	fdf->column_count = ft_count_and_validate_columns(clean, fdf);
	return (clean);
}







int	count(void *ptr)
{
	int a;

	a = 0;
	while(ptr)
	{
		a++;
		ptr++;
	}
	return (a);
}




t_map **ft_parse(char *filename)
{
	t_file  fdf;
	t_map   **parsed;
	char	****clean;



	clean = ft_split_lines_and_values(ft_parse_all_text_fn(filename));



	// clean = ft_trim_file(filename, &fdf);
	// ft_debug_print_array_of_strings(clean, 1);
	// parsed = ft_alloc_matrix(&fdf);
	// ft_fill_matrix(clean, parsed, &fdf);
	// ft_free_str_array(clean);
	return (parsed);
}
