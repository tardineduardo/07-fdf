#include "../fdf.h"

void ft_error(void)
{
	ft_dprintf(STDERR_FILENO, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void ft_init_fdf(t_file *fdf, int temp_count)
{
	fdf->line_count = 0;
	fdf->column_count = 0;
	temp_count = 0;
}

int ft_columns_in_first_line(char *s)
{
	char	*copy;
	char	*line;

	copy = ft_strdup(s);
	line = ft_strtok(copy, "\n");
	return (ft_split_count(line, " "));
}
