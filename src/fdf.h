# include "../libft/libft.h"

#include <mlx.h>

#define FDF_BUFF 1024

typedef struct fdf
{
	int	h;
	int	c;
}		map;

map **ft_parse(char *filename);
