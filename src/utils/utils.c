#include "../fdf.h"

void ft_error(void)
{
	ft_dprintf(STDERR_FILENO, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int ft_columns_in_first_line(char *str)
{
	char	*copy;
	char	*copy_tok;
	char	*line;
	int		count;

	copy = ft_strdup(str);
	line = ft_strtok_r(copy, "\n", &copy_tok);
	count = ft_split_count(line, ' ');	
	free(copy);
	return (count);
}

void ft_init_count(char *str, t_file *fdf, int *col_check)
{
	fdf->cols = ft_columns_in_first_line(str);
	fdf->lines = 0;
	col_check = 0;
	return ;
}

void ft_free_map(t_point ***parsed)
{
	int a;
	int b;

	if (!parsed)
		return ;
	a = 0;
	while (parsed[a])
	{
		b = 0;
		while (parsed[a][b])
		{
			if (parsed[a][b]->color)
				free(parsed[a][b]->color);
			free(parsed[a][b]);
			b++;
		}
		free(parsed[a]);
		a++;
	}
	free(parsed);
}
