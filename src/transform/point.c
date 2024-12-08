#include "../fdf.h"

void ft_x_rot(t_point *point)
{
    double radian = point->rot_x * (PI / 180.0);
    point->x1 = point->x0;
    point->y1 = point->y0 * cos(radian) - point->z0 * sin(radian);
    point->z1 = point->y0 * sin(radian) + point->z0 * cos(radian);
}

void ft_y_rot(t_point *point)
{
    double radian = point->rot_y * (PI / 180.0);
    point->x1 = point->x0 * cos(radian) + point->z0 * sin(radian);
    point->y1 = point->y0;
    point->z1 = -point->x0 * sin(radian) + point->z0 * cos(radian);
}

void ft_z_rot(t_point *point)
{
    double radian = point->rot_z * (PI / 180.0);
    point->x1 = point->x0 * cos(radian) - point->y0 * sin(radian);
    point->y1 = point->x0 * sin(radian) + point->y0 * cos(radian);
    point->z1 = point->z0;
}

void ft_zoom(t_point *point, double increment)
{
	point->x1 = point->x1 * increment;
	point->y1 = point->y1 * increment;
	point->z1 = point->z1 * increment;
}

void ft_move_on_screen(t_point *point, double x_inc, double y_inc)
{
	point->x1 += x_inc;
	point->y1 += y_inc;
}







/*

rotate x
|1	0		0		|	| x	|
|0	cos(θ)  -sin(θ)	| *	| y	|
|0	sin(θ)   cos(θ)	| 	z	|

rotate y
|cos(θ)		0	sin(θ)	|	| x	|
|0			1	0		| *	| y	|
|-sin(θ)	0	cos(θ)	|	| z	|

rotate z
|cos(θ)	-sin(θ)	0	|	| x	|
|sin(θ)	cos(θ)	0	| *	| y	|
|0		0		1	|	| z	|

scale x, y, z
|i	0	0| 	 | x | 
|0	i	0| * | y |
|0	0	i| 	 | z |

*/