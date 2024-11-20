# include "../libft/libft.h"

#include <mlx.h>

#define FDF_BUFF 1024

typedef struct t_map
{
	int	value;
	int	color;
	int	red;
	int	gre;
	int	blu;
}		t_map;

typedef struct t_file
{
	size_t	h_file;
	size_t	w_file;
}		t_file;


t_map **ft_parse(char *filename);
