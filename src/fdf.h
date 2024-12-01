#include "../libs/libft/libft.h"
#include "../libs/MLX42/include/MLX42/MLX42.h"

#include <stdio.h>
#include <unistd.h>
#include <GLFW/glfw3.h>
#include <X11/Xlib.h>


// #define WIDTH 800	
// #define HEIGHT 600
//#define BPP sizeof(int32_t)


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
	int		x;
	int		y;
	int		z;
	int		r;
	int		g;
	int		b;
	char	*color;
} t_map;

typedef struct
{
	size_t	lines;
	size_t	cols;
	char	*save_line;
	char	*save_point;
} t_file;

//USING
void	ft_get_monitor_resolution(uint32_t *screen_w, uint32_t *screen_h);
void	ft_transform_map(t_map ****map, u_int32_t scr_w, u_int32_t scr_h);
void	ft_error(void);
t_map	***ft_parse(char *filename);
void	ft_free_map(t_map ***parsed);

//INUTILS
void	ft_init_count(char *str, t_file *fdf, int *col_check);
int		ft_columns_in_first_line(char *s);

//DEBUG
void	ft_debug_print_2D_struct(t_map ****map);

//NOT USING
GLFWmonitor* ft_get_active_monitor(void);
void draw_line(int x1, int y1, int x2, int y2, void *mlx, void *win);
