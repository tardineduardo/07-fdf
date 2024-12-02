#include "../libs/libft/libft.h"
#include "../libs/MLX42/include/MLX42/MLX42.h"

#include <stdio.h>
#include <unistd.h>
#include <math.h>

#define BPP sizeof(int32_t)
#define PCT_OF_SCREEN 70
#define PCT_OF_WINDOW 100
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
    uint32_t	color;
    mlx_image_t *image;
} t_draw;


typedef struct
{
    int32_t	scr_w;
    int32_t	scr_h;
    int32_t	win_w;
    int32_t	win_h;
    int32_t	img_w;
    int32_t	img_h;
}	t_sizes;

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
void	ft_get_monitor_resolution(t_sizes *size);
int		ft_set_win_and_img_sizes(t_sizes *size);
void	ft_transform_map(t_map ****map, u_int32_t scr_w, u_int32_t scr_h);
void	ft_error(void);
t_map	***ft_parse(char *filename);
void	ft_free_map(t_map ***parsed);
void draw_grid(mlx_image_t *image, t_map ***matrix, t_sizes *sizes, uint32_t color);


//INUTILS
void	ft_init_count(char *str, t_file *fdf, int *col_check);
int		ft_columns_in_first_line(char *s);

//DEBUG
void	ft_debug_print_2D_struct(t_map ****map);

//NOT USING
//GLFWmonitor* ft_get_active_monitor(void);
//void draw_line(int x1, int y1, int x2, int y2, void *mlx, void *win);
