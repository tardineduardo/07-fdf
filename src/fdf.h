/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:20:33 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/28 21:22:59 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "../libs/libft/libft.h"
# include "../libs/MLX42/include/MLX42/MLX42.h"
# define PCT_OF_SCREEN 80
# define PCT_OF_WINDOW 100
# define PI 3.141592653589793
# define DBL_MAX 1.7976931348623157e+308
# define DBL_MIN 2.2250738585072014e-308

typedef struct s_sizes
{
	int32_t	scr_w;
	int32_t	scr_h;
	int32_t	win_w;
	int32_t	win_h;
	int32_t	img_w;
	int32_t	img_h;
}	t_sizes;

typedef struct s_point
{
	int			x_map;
	int			y_map;
	int			z_map;
	double		x_wld;
	double		y_wld;
	double		z_wld;
	int			x_scr;
	int			y_scr;
	int			x_scr_old;
	int			y_scr_old;
	uint32_t	rgba_original;
	uint32_t	rgba;
}	t_point;

typedef struct s_map
{
	int			map_w;
	int			map_h;
	double		rot_x;
	double		rot_y;
	double		rot_z;
	int			minz;
	int			maxz;
	int			deltaz;
	double		x_scr_var;
	double		y_scr_var;
	double		max_x_scr;
	double		max_y_scr;
	double		min_x_scr;
	double		min_y_scr;
	double		extrusion;
	double		translate_x;
	int			center_type;
	double		zoom;
	u_int32_t	bg_color;
	u_int32_t	gradient_start_color;
	u_int32_t	gradient_end_color;
	t_point		*points;
	mlx_image_t	*img;
	void		*proj;
}	t_map;

typedef struct s_line
{
	double	x;
	double	y;
	double	delta_x;
	double	delta_y;
	double	x_inc;
	double	y_inc;
	int		steps;
	int		i;
}	t_line;

typedef struct s_file
{
	int		lines;
	int		cols;
	char	*save_line;
	char	*save_point;
}	t_file;

typedef struct s_hook_param
{
	t_point		*points;
	t_map		*map;
	t_sizes		*sizes;
	mlx_t		*mlx;
	mlx_image_t	*img;
	bool		shift_pressed;
}	t_hook_param;

typedef void		(*t_ft)(t_point*, t_map*, mlx_image_t*);
typedef uint32_t	t_ui32;

//HOOKS
void	ft_key_hooks(mlx_key_data_t keydata, void *param);
void	ft_scroll_hooks(double xdelta, double ydelta, void *param);
void	ft_min_max_z(t_map **map);
void	ft_find_y_boundaries(t_point **point, t_map *map);
void	ft_find_x_boundaries(t_point **point, t_map *map);
void	ft_change_view(t_map *m, mlx_t **mlx, int key);
void	ft_init_hooks(mlx_t **mlx, t_map **map, t_sizes **sizes,
			t_hook_param *hooks);

//MAIN INITS
void	ft_inits(mlx_t **mlx, t_sizes **size, t_map **m, t_hook_param **hooks);
void	ft_get_monitor_resolution(t_sizes *size);
int		ft_set_win_and_img_sizes(t_sizes *size);
void	ft_launch_iso_map(t_point *point, t_map *m, mlx_image_t *img,
			mlx_t **mlx);

//UPDATE PARAMS
void	ft_update_points(t_point *p, mlx_image_t *img, t_map *map, t_ft func);
void	ft_update_points_new(t_map *map, t_ft func);
void	ft_rotate_z(t_map *m, mlx_t **mlx, int key);
void	ft_rotate_x(t_map *m, mlx_t **mlx, int key);
void	ft_rotate_y(t_map *m, mlx_t **mlx, int key);
void	ft_extrude(t_map *m, mlx_t **mlx, int key);
void	ft_zoom(t_map *m, mlx_t **mlx, int key);
void	ft_translate_key(t_map *m, mlx_t **mlx, int key);
void	ft_center(t_map *map);
void	ft_center_map_in_place(t_point *point, t_map *map, mlx_image_t *img);
void	ft_center_map_in_image(t_point *point, t_map *map, mlx_image_t *img);

//DRAW
void	ft_redraw(t_map *m, mlx_t **mlx);
void	ft_draw_line(mlx_image_t *img, t_point *start, t_point *end);
void	ft_draw_hlines(mlx_image_t *img, t_point *point, t_map *m);
void	ft_draw_vlines(mlx_image_t *img, t_point *point, t_map *m);
void	ft_draw_solid_background(mlx_image_t *img, int color);
void	ft_launch_dim_map(t_point *point, t_map *m, mlx_image_t *img,
			mlx_t **mlx);
void	ft_launch_top_map(t_point *point, t_map *m, mlx_image_t *img,
			mlx_t **mlx);

//COLORS
int		ft_get_rgba(int r, int ft_g, int b, int a);
int		ft_get_r(int rgba);
int		ft_get_g(int rgba);
int		ft_get_b(int rgba);
int		ft_get_a(int rgba);
void	ft_apply_original_colors(t_map *map);
void	ft_apply_gradient_colors(t_map *map);
void	ft_change_color_hooks(t_map *map, mlx_t *mlx, int key);
void	ft_set_color_pallet_1(t_map *map);
void	ft_set_color_pallet_2(t_map *map);
void	ft_set_color_pallet_3(t_map *map);
void	ft_set_color_pallet_4(t_map *map);
t_ui32	ft_interpolate(u_int32_t start_color, u_int32_t end_color,
			int total_steps, int curr_step);

//MOVES
void	ft_x_rot(t_point *point, t_map *map, mlx_image_t *i);
void	ft_y_rot(t_point *point, t_map *map, mlx_image_t *i);
void	ft_z_rot(t_point *point, t_map *map, mlx_image_t *i);
void	ft_fit_to_image(t_point *point, t_map *map, mlx_image_t *img);
void	ft_convert_to_isometric(t_point *point, t_map *map, mlx_image_t *img);
void	ft_convert_to_dimetric(t_point *p, t_map *m, mlx_image_t *i);
void	ft_convert_to_top(t_point *p, t_map *m, mlx_image_t *i);

//PARSING
void	ft_parse(char *filename, t_map **map);
int		ft_columns_in_first_line(char *s);
void	ft_init_count(char *str, t_file *fdf, int *col_check);

//ERROR
void	ft_error(void);

//DEBUG
void	ft_put_points(t_point *p, t_map *m);

#endif
