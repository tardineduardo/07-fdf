#include "fdf.h"

void	ft_get_size(int fd, int *width, int *height)
{
	char	*line;

	line = get_next_line(fd);
	*width = 1;
	while(line)
	{
		if (*line == ' ')
			(*width)++;
		line++;
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

	fd = open("_test_maps/42.fdf", O_RDONLY);
	ft_get_size(fd, &width, &height);
	parsed = malloc(1);
	close(fd);
	return (parsed);

}
