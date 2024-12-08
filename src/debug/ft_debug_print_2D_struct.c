#include "../fdf.h"

void	ft_debug_print_2D_struct(t_point ****map)
{
	int	a;
	int	b;

	a = 0;
	while ((*map)[a])
	{
		b = 0;
		while((*map)[a][b])
		{
			if ((*map)[a][b]->color)
				printf("[%i, %i, %i, %s]\t", (*map)[a][b]->x0, (*map)[a][b]->y0, (*map)[a][b]->z0, (*map)[a][b]->color);
			else
				printf("[%i, %i, %i]\t", (*map)[a][b]->x0, (*map)[a][b]->y0, (*map)[a][b]->z0);


			b++;
		}
		printf("\n");	
		a++;
	}
	printf("\n");	
}
	







