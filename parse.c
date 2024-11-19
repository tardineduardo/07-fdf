#include "fdf.h"



void	ft_get_size(int fd, int *width, int *height)
{




}

struct map **ft_parse(int fd)
{
	int			width;
	int			height;
	struct map	**parsed;

	ft_get_size(fd, &width, &height);
	parsed = malloc...

}