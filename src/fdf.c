#include "fdf.h"

#include <mlx.h>

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768

#define MLX_ERROR 1

int main(int argc, char *argv[])
{
	void	*mlx_ptr;
	void	*win_ptr;
<<<<<<< HEAD
	t_map	**parsed;
=======
	map		**parsed;

	if (argc == 1)
		return (1);
>>>>>>> d7d7169147ed6f45e8ec991a3834f6065110ef7d

	if (argc != 2)
		return (1);
	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (MLX_ERROR);
	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
	if (win_ptr == NULL)
	{
		free(win_ptr);
		return (MLX_ERROR);
	}
	parsed = ft_parse(argv[1]);


<<<<<<< HEAD
=======
	parsed = ft_parse(argv[1]);
>>>>>>> d7d7169147ed6f45e8ec991a3834f6065110ef7d


	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}
