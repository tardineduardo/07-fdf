#include "../fdf.h"

void ft_error(void)
{
	ft_dprintf(STDERR_FILENO, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}