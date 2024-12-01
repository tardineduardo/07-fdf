#include "../fdf.h"

void	ft_debug_print_2D_struct(t_map ***map)
{
	int	a;
	int	b;

	a = 0;
	while (map[a])
	{
		b = 0;
		while(map[a][b])
		{
			printf("[%f, %f]\t\t", map[a][b]->x, map[a][b]->y) ;
		}
	}
}
	







