#include "fdf.h"


void static ft_init_matrix(t_file *fdf, t_map **parsed)
{
	int i;

	parsed = malloc(fdf->h_file * sizeof(*parsed));
	i = 0



}

static size_t	ft_get_number_of_lines(char *filename)
{
	int		file;
	char	*line;
<<<<<<< HEAD
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
=======
	char	*trav;

	line = get_next_line(fd);
	trav = line;
	*width = 0;
	while(*trav != '\n')
	{
		if (*trav == ' ')
			(*width)++;
		trav++;
>>>>>>> d7d7169147ed6f45e8ec991a3834f6065110ef7d
	}
	close(file);
	return (count_lines);
}

static size_t	ft_validate_consistency(char *filename)
{
	char	*line;
	int		file;
	size_t	count_items;
	size_t	count_items_log;

	file = open(filename, O_RDONLY);
	line = get_next_line(file);
	count_items_log = ft_split_count(line, ' ');
	free(line);
	while(1)
	{
		line = get_next_line(file);
		if (line == NULL)
		{
			free(line);
			break;
		}		
		count_items = ft_split_count(line, ' ');
		if (count_items != count_items_log)
			ft_free_and_exit(line, "Error: irregular map width.\n", 1);
		free(line);
	}
	close(file);
	return (count_items);
}

static char **ft_trim_file(char *filename, t_file *fdf)
{
	size_t	i;
	size_t	line_count;
	int		file;
	char	*line;
	char	**clean;

	line_count = ft_get_number_of_lines(filename);
	clean = ft_calloc((line_count + 1), sizeof(char *));
	file = open(filename, O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(file);
		if (!line)
			break;
		clean[i] = ft_strtrim(line, " \n");
		free(line);
		i++;
	}
	close(file);
	fdf->h_file = i + 1;
	fdf->w_file = ft_validate_consistency(filename);
	return (clean);
}

t_map **ft_parse(char *filename)
{
<<<<<<< HEAD
	t_file		fdf;
	t_map		**parsed;
	char		**clean;

	clean = ft_trim_file(filename, &fdf);
	ft_debug_print_array_of_strings(clean, 1);

	ft_init_matrix(parsed, &fdf);
	// ft_fill_matrix(fd, parsed, width, height);
=======
	int		fd;
	int		width;
	int		height;
	map		**parsed;

	fd = open(filename, O_RDONLY);
	ft_get_size(fd, &width, &height);
	parsed = ft_calloc(sizeof(map));
	close(fd);
>>>>>>> d7d7169147ed6f45e8ec991a3834f6065110ef7d
	return (parsed);

}
