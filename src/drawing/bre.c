#include "../fdf.h"



void putPixel(t_draw *data, int x, int y) {
    if (x >= 0 && y >= 0 && x < sizes->img_w && y < data->sizes->img_h) {
        mlx_put_pixel(data->image, x, y, data->color);
    }
}

void drawLineBresenham(t_draw *data, int x0, int y0, int x1, int y1)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;

    while (1) {
        putPixel(data, x0, y0);

        if (x0 == x1 && y0 == y1) break;

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}
