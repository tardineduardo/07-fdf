#include "fdf.h"

void	ft_get_size(int fd, int *width, int *height)
{
	char	*line;
	char	*trav;

	line = get_next_line(fd);
	trav = line;
	*width = 0;
	while(*trav != '\n')
	{
		if (*trav == ' ')
			(*width)++;
		trav++;
	}
	free(line);
	*height = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line)
			(*height)++;
		else
			break;
		free(line);
	}
	free(line);
}

map **ft_parse(char *filename)
{
	int		fd;
	int		width;
	int		height;
	map		**parsed;

	fd = open(filename, O_RDONLY);
	ft_get_size(fd, &width, &height);
	parsed = ft_calloc(sizeof(map));
	close(fd);
	return (parsed);

}
