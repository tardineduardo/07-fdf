#include "fdf.h"


static void ft_fill_matrix(char **clean, t_map **parsed, t_file *fdf)
{
    size_t line, col;
    char **items;
    char **single;

    line = 0;
    while (line < fdf->line_count)
    {
        items = ft_split_space(clean[line]);
        col = 0;
        while (col < fdf->column_count)
        {
            single = ft_split_char(items[col], ',');
            parsed[line][col].value = ft_atoi(single[0]);
            if (single[1])
                parsed[line][col].color = ft_strdup(single[1]);
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
        ft_error_exit("Error: Memory allocation failed.\n", 1);
    i = 0;
    while (i < fdf->line_count)
    {
        parsed[i] = malloc(fdf->column_count * sizeof(t_map));
        if (!parsed[i])
            ft_error_exit("Error: Memory allocation failed.\n", 1);
        i++;
    }
    return parsed;
}
// static t_map **ft_alloc_matrix(t_file *fdf) {
//     t_map **parsed = malloc(fdf->line_count * sizeof(t_map *));
//     for (int i = 0; i < fdf->line_count; i++) {
//         parsed[i] = malloc(fdf->column_count * sizeof(t_map));
//     }
//     return parsed;
// }



static size_t	ft_get_number_of_lines(char *filename)
{
	int		file;
	char	*line;
	size_t	count_lines;

	file = open(filename, O_RDONLY);
	count_lines = 1;
	while(1)
	{
		line = get_next_line(file);
		if (line == NULL)
		{
			free(line);
			break;
		}	
		count_lines += ft_count_char(line, '\n');
		free(line);

	}
	close(file);
	return (count_lines);
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
			ft_error_exit("Error: irregular map width.\n", 1);
		a++;
	}
	return (count_items);
}
// return and close

static char **ft_trim_file(char *filename, t_file *fdf)
{
	size_t	i;
	int		file;
	char	*line;
	char	**clean;

	fdf->line_count = ft_get_number_of_lines(filename);
	clean = ft_calloc((fdf->line_count + 1), sizeof(char *));
	file = open(filename, O_RDONLY);
	if (file == -1)
		return (NULL);
	i = 0;
	while (1)
	{
		line = get_next_line(file);
		if (!line)
			break;
		clean[i] = ft_strtrim(line, " \n");
		if (clean[i][0] == '\0')
		{
			free(line);
			break;
		}
		free(line);
		i++;
	}
	close(file);
	fdf->line_count = i;
	fdf->column_count = ft_count_and_validate_columns(clean, fdf);
	return (clean);
}

t_map **ft_parse(char *filename)
{
    t_file  fdf;
    t_map   **parsed;
    char    **clean;

    clean = ft_trim_file(filename, &fdf);
    if (!clean)
        ft_error_exit("Error: Failed to process input file.\n", 1);

    ft_debug_print_array_of_strings(clean, 1);

    // Allocate memory for the parsed matrix
    parsed = ft_alloc_matrix(&fdf);

    // Fill the matrix
    ft_fill_matrix(clean, parsed, &fdf);

    // Free the cleaned input
    ft_free_str_array(clean);

    return parsed;
}

