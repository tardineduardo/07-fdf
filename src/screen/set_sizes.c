#include "../fdf.h"

int	ft_set_win_and_img_sizes(t_sizes *size)
{
	if (PCT_OF_SCREEN < 30 || PCT_OF_SCREEN > 100)
	{	
		ft_dprintf(STDERR_FILENO, "Window percent must be > 30 and < 100.\n");
		return (0);	
	}
	size->win_w = size->scr_w * PCT_OF_SCREEN / 100;
	size->win_h = size->scr_h * PCT_OF_SCREEN / 100;
	if (PCT_OF_WINDOW < 10 || PCT_OF_WINDOW > 100)
	{	
		ft_dprintf(STDERR_FILENO, "Image percent must be > 1 and < 100.\n");
		return (0);	
	}
	size->img_w = size->win_w * PCT_OF_WINDOW / 100;
	size->img_h = size->win_h * PCT_OF_WINDOW / 100;

	return (1);
}
