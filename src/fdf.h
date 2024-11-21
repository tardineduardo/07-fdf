# include "../libft/libft.h"

#include <mlx.h>

#define FDF_BUFF 1024

typedef struct
{
	int	value;
	char	*color;
	int	red;
	int	gre;
	int	blu;
} t_map;

typedef struct
{
	size_t	line_count;
	size_t	column_count;
} t_file;


t_map **ft_parse(char *filename);
