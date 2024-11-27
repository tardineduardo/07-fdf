#include "../libft/libft.h"
#include "../MLX42/include/MLX42/MLX42.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define WIDTH 256
#define HEIGHT 256

/*
 * Main MLX handle, carries important data in regards to the program.
 * @param window The window itself.
 * @param context Abstracted opengl data.
 * @param width The width of the window.
 * @param height The height of the window.
 * @param delta_time The time difference between the previous frame and the current frame.
 */



typedef struct
{
	int		value;
	int		r;
	int		g;
	int		b;
	char	*color;
} t_map;

typedef struct
{
	size_t	line_count;
	size_t	column_count;
} t_file;

t_map **ft_parse(char *filename);




