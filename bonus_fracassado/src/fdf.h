/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:20:33 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/16 19:49:43 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <float.h>
# include "../libs/libft/libft.h"
# include "../libs/MLX42/include/MLX42/MLX42.h"
# define PCT_OF_SCREEN 75
# define PCT_OF_WINDOW 100
# define PI 3.141592653589793

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
	int			r;
	int			g;
	int			b;
	int			a;
	uint32_t	rgba;
	char		*color;
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
	double		x_scr_var;
	double		y_scr_var;
	double		max_x_scr;
	double		max_y_scr;
	double		min_x_scr;
	double		min_y_scr;
	double		height_scale;
	char		*order;
	t_point 	*points;
	mlx_image_t *img;
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

typedef struct s_camera
{
    double x;       // Camera position in world space
    double y;
    double z;
    double rot_x;   // Camera orientation (pitch)
    double rot_y;   // Camera orientation (yaw)
    double rot_z;   // Camera orientation (roll)
    double fov;     // Field of view for perspective projection
} t_camera;

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
}	t_hook_param;





typedef void	(*t_ft)(t_point*, t_map*, mlx_image_t*);
typedef void	(*t_ft2)(t_map*, t_point*);

//USING ------------------------------------------------------------------------
void	ft_redraw_map(t_point *point, t_map *m, mlx_image_t *img, mlx_t *mlx);

void	ft_min_max_z(t_map **map);
void	ft_find_y_boundaries(t_point **point, t_map *map);
void	ft_find_x_boundaries(t_point **point, t_map *map);

//INITS
void	ft_inits(mlx_t **mlx, t_sizes **size, t_map **map);
void	ft_get_monitor_resolution(t_sizes *size);
int		ft_set_win_and_img_sizes(t_sizes *size);
void	ft_apply_rotations(t_map *map, t_point *point);

//DRAW
void	ft_update_points(t_point *p, mlx_image_t *img, t_map *map, t_ft func);
void	ft_update_points_rot(t_map *map, t_point *p, t_ft2 func);
void	ft_launch_iso_map(t_point *point, t_map *m, mlx_image_t *img, mlx_t *mlx);
void	ft_draw_dimetric_map(t_point *point, t_map *m, mlx_image_t *img, mlx_t *mlx);
void	ft_draw_line(mlx_image_t *img, t_point *start, t_point *end);
void	draw_hlines(mlx_image_t *img, t_point *point, t_map *m);
void	draw_vlines(mlx_image_t *img, t_point *point, t_map *m);
void	ft_draw_solid_background(mlx_image_t *img, int color);
void	ft_convert_to_dimetric(t_point *p, t_map *m, mlx_image_t *i);

//COLORS
int		ft_get_rgba(int r, int ft_g, int b, int a);
int		ft_get_r(int rgba);
int		ft_get_g(int rgba);
int		ft_get_b(int rgba);
int		ft_get_a(int rgba);

//MOVES
void	ft_x_rot_w(t_point *point, double radian);
void	ft_y_rot_w(t_point *point, double radian);
void	ft_z_rot_w(t_point *point, double radian);
void	ft_x_rot_s(t_point *point, double radian);
void	ft_y_rot_s(t_point *point, double radian);
void	ft_z_rot_s(t_point *point, double radian);


void	ft_translate(t_point *point, t_map *map, mlx_image_t *img);
void	ft_fit_to_image(t_point *point, t_map *map, mlx_image_t *img);
void	ft_convert_to_isometric(t_point *point, t_map *map, mlx_image_t *img);

//PARSING
void	ft_parse(char *filename, t_map **map);
int		ft_columns_in_first_line(char *s);
void	ft_init_count(char *str, t_file *fdf, int *col_check);

//ERROR
void	ft_error(void);

//DEBUG
void	ft_put_points(t_point *p, t_map *m);

//HOOKS
void	ft_key_hooks(mlx_key_data_t keydata, void *param);

double rad(double angle);

#endif