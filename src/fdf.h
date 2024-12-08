#include "../libs/libft/libft.h"
#include "../libs/MLX42/include/MLX42/MLX42.h"
#include "../libs/MLX42/include/glad/glad.h"

#include <stdio.h>
#include <unistd.h>
#include <math.h>

#define BPP sizeof(int32_t)
#define PCT_OF_SCREEN 85
#define PCT_OF_WINDOW 100
#define PI 3.14

/*
 * Main MLX handle, carries important data in regards to the program.
 * @param window The window itself.
 * @param context Abstracted opengl data.
 * @param width The width of the window.
 * @param height The height of the window.
 * @param delta_time The time difference between the previous frame and the current frame.
 */


// typedef struct mlx_image
// {
// 	const uint32_t	width;
// 	const uint32_t	height;
// 	uint8_t*		pixels;
// 	mlx_instance_t*	instances;
// 	size_t			count;
// 	bool			enabled;
// 	void*			context;
// }	mlx_image_t;

typedef struct sizes
{
    int32_t	scr_w;
    int32_t	scr_h;
    int32_t	win_w;
    int32_t	win_h;
    int32_t	img_w;
    int32_t	img_h;
    int32_t	map_w;
    int32_t	map_h;	
}	t_sizes;

typedef struct point
{
	int		x0;
	int		y0;
	int		z0;
	int		x1;
	int		y1;
	int		z1;
	int		rot_x;
	int		rot_y;
	int		rot_z;		
	int		red;
	int		green;
	int		blue;
	int		rgba;
	char	*color;
} t_point;

typedef struct file
{
	size_t	lines;
	size_t	cols;
	char	*save_line;
	char	*save_point;
} t_file;

//USING
void	ft_get_monitor_resolution(t_sizes *size);
int		ft_set_win_and_img_sizes(t_sizes *size);
void ft_transform_map(t_point ****map, mlx_image_t *img, t_sizes *size);
void ft_transform_map_iso(t_point ****map, mlx_image_t *img, t_sizes *size);
void drawgl(t_point *start, t_point *end);
void apply_isometric_matrix(t_point *point);
void ft_fit_to_image(t_point ****map, mlx_image_t *img, t_sizes *size);


void	ft_error(void);
t_point	***ft_parse(char *filename,	t_sizes *size);
void	ft_free_map(t_point ***parsed);

void draw_line_bresenham(mlx_image_t *image, t_point *start, t_point *end, uint32_t color);
void draw_grid(mlx_image_t *img, t_point ***point, t_sizes *sizes, uint32_t color);
void draw_line_xiaolim(mlx_image_t* image, const t_point *start, const t_point *end, uint32_t color);
void draw_line_xiaolim2(mlx_image_t* image, int x0, int y0, int x1, int y1, uint32_t color);
// void test(mlx_image_t *img, t_point ****map, t_sizes *size);
void draw_horizontal_lines(mlx_image_t *img, t_point ***point, t_sizes *size, uint32_t color);
void draw_vertical_lines(mlx_image_t *img, t_point ***map, t_sizes *size, uint32_t color);



//COLORS
int ft_get_rgba(int r, int ft_g, int b, int a);
int ft_get_r(int rgba);
int ft_get_g(int rgba);
int ft_get_b(int rgba);
int ft_get_a(int rgba);

//INUTILS
void	ft_init_count(char *str, t_file *fdf, int *col_check);
int		ft_columns_in_first_line(char *s);

//DEBUG
void	ft_debug_print_2D_struct(t_point ****map);

//NOT USING
//GLFWmonitor* ft_get_active_monitor(void);
//void draw_line(int x1, int y1, int x2, int y2, void *mlx, void *win);





