#include "../fdf.h"

void putPixel(mlx_image_t *image, int x, int y, uint32_t color)
{
    if (x < 0 || y < 0 || x >= (int)image->width || y >= (int)image->height)
        return;
    mlx_put_pixel(image, x, y, color);
}


// void drawgl(mlx_image_t *image, t_point *start, t_point *end, uint32_t color)
// {
// 	glBegin(GL_LINES);
// 	glVertex2f(start->x0, start->y0);
// 	glVertex2f(end->x0, end->y0);
// 	glEnd();
// }

void draw_line_bresenham(mlx_image_t *image, t_point *start, t_point *end, uint32_t color)
{
    int x0;
    int y0;
    int x1;
    int y1;
    int dx;
    int dy;
    int sx;
    int sy;
    int err;
    int e2;

    x0 = start->x0;
    y0 = start->y0;
    x1 = end->x0;
    y1 = end->y0;

    dx = abs(x1 - x0);
    dy = abs(y1 - y0);

    sx = -1;
    if (x0 < x1)
        sx = 1;

    sy = -1;
    if (y0 < y1)
        sy = 1;

    err = dx - dy;

    while (1)
    {
        putPixel(image, x0, y0, color);
        
        if (x0 == x1 && y0 == y1)
            break;

        e2 = 2 * err;

        if (e2 > -dy)
        {
            err = err - dy;
            x0 = x0 + sx;
        }

        if (e2 < dx)
        {
            err = err + dx;
            y0 = y0 + sy;
        }
    }
}
