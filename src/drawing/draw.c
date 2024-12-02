#include "../fdf.h"

#include <math.h>

typedef struct
{
    int x0, y0, x1, y1; // Start and end coordinates for the line
    uint32_t color;     // Color for the line
} t_line;

// Function to draw a line using Bresenham's algorithm
void draw_line(mlx_image_t *image, t_line *line)
{
    int dx = abs(line->x1 - line->x0);
    int dy = abs(line->y1 - line->y0);

    int sx, sy;
    if (line->x0 < line->x1)
        sx = 1;
    else
        sx = -1;

    if (line->y0 < line->y1)
        sy = 1;
    else
        sy = -1;

    int err = dx - dy;

    int x = line->x0;
    int y = line->y0;

    while (1)
    {
        // Put a pixel at (x, y)
        mlx_put_pixel(image, x, y, line->color);

        // If we have reached the end point, break
        if (x == line->x1 && y == line->y1)
            break;

        // Update error and coordinates
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y += sy;
        }
    }
}

// Function to draw a grid based on t_map
void draw_grid(mlx_image_t *image, t_map ***matrix, t_sizes *sizes, uint32_t color)
{
    t_line line;

    for (int y = 0; y < sizes->img_h; y++)
    {
        for (int x = 0; x < sizes->img_w; x++)
        {
            // Calculate screen positions
            int screen_x0 = x * (sizes->win_w / sizes->img_w);
            int screen_y0 = y * (sizes->win_h / sizes->img_h);

            // Horizontal line: Connect (x, y) to (x+1, y)
            if (x + 1 < sizes->img_w)
            {
                line.x0 = screen_x0;
                line.y0 = screen_y0;
                line.x1 = (x + 1) * (sizes->win_w / sizes->img_w);
                line.y1 = screen_y0;
                line.color = color;
                draw_line(image, &line);
            }

            // Vertical line: Connect (x, y) to (x, y+1)
            if (y + 1 < sizes->img_h)
            {
                line.x0 = screen_x0;
                line.y0 = screen_y0;
                line.x1 = screen_x0;
                line.y1 = (y + 1) * (sizes->win_h / sizes->img_h);
                line.color = color;
                draw_line(image, &line);
            }
        }
    }
}
