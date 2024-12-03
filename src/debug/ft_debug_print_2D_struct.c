#include "../fdf.h"

void	ft_debug_print_2D_struct(t_map ****map)
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
				printf("[%i, %s]\t", (*map)[a][b]->z, (*map)[a][b]->color);
			else
				printf("[%i, NULL]\t", (*map)[a][b]->z);


			b++;
		}
		printf("\n");	
		a++;
	}
	printf("\n");	
}
	







