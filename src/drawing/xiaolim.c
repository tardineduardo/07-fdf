#include "../fdf.h"

static uint32_t blendColor(uint32_t baseColor, float brightness)
{
    uint8_t r = (uint8_t)((baseColor >> 16) & 0xFF);
    uint8_t g = (uint8_t)((baseColor >> 8) & 0xFF);
    uint8_t b = (uint8_t)(baseColor & 0xFF);

    r = (uint8_t)(r * brightness);
    g = (uint8_t)(g * brightness);
    b = (uint8_t)(b * brightness);

    return (0xFF << 24) | (r << 16) | (g << 8) | b;
}

static void putPixel(mlx_image_t* image, int x, int y, float brightness, uint32_t color)
{
    if (x < 0 || y < 0 || x >= (int)image->width || y >= (int)image->height) return;
    uint32_t blendedColor = blendColor(color, brightness);
    mlx_put_pixel(image, x, y, blendedColor);
}

void draw_line_xiaolim2(mlx_image_t* image, int x0, int y0, int x1, int y1, uint32_t color)
{
    int steep = abs(y1 - y0) > abs(x1 - x0);
    if (steep) {
        int temp = x0; x0 = y0; y0 = temp;
        temp = x1; x1 = y1; y1 = temp;
    }
    if (x0 > x1) {
        int temp = x0; x0 = x1; x1 = temp;
        temp = y0; y0 = y1; y1 = temp;
    }
    float dx = x1 - x0, dy = y1 - y0, gradient = dy / dx;
    float xEnd = round(x0), yEnd = y0 + gradient * (xEnd - x0);
    float xGap = 1.0 - (x0 + 0.5 - floor(x0 + 0.5));
    int xPixel1 = xEnd, yPixel1 = (int)yEnd;
    if (steep) {
        putPixel(image, yPixel1, xPixel1, 1.0 - (yEnd - floor(yEnd)) * xGap, color);
        putPixel(image, yPixel1 + 1, xPixel1, (yEnd - floor(yEnd)) * xGap, color);
    } else {
        putPixel(image, xPixel1, yPixel1, 1.0 - (yEnd - floor(yEnd)) * xGap, color);
        putPixel(image, xPixel1, yPixel1 + 1, (yEnd - floor(yEnd)) * xGap, color);
    }
    float interY = yEnd + gradient;
    xEnd = round(x1);
    yEnd = y1 + gradient * (xEnd - x1);
    xGap = x1 + 0.5 - floor(x1 + 0.5);
    int xPixel2 = xEnd, yPixel2 = (int)yEnd;
    if (steep) {
        putPixel(image, yPixel2, xPixel2, 1.0 - (yEnd - floor(yEnd)) * xGap, color);
        putPixel(image, yPixel2 + 1, xPixel2, (yEnd - floor(yEnd)) * xGap, color);
    } else {
        putPixel(image, xPixel2, yPixel2, 1.0 - (yEnd - floor(yEnd)) * xGap, color);
        putPixel(image, xPixel2, yPixel2 + 1, (yEnd - floor(yEnd)) * xGap, color);
    }
    for (int x = xPixel1 + 1; x < xPixel2; x++) {
        if (steep) {
            putPixel(image, (int)interY, x, 1.0 - (interY - floor(interY)), color);
            putPixel(image, (int)interY + 1, x, interY - floor(interY), color);
        } else {
            putPixel(image, x, (int)interY, 1.0 - (interY - floor(interY)), color);
            putPixel(image, x, (int)interY + 1, interY - floor(interY), color);
        }
        interY += gradient;
    }
}


void draw_line_xiaolim(mlx_image_t* image, t_point *start, t_point *end, uint32_t color)
{
    // Special case for vertical lines
    if (start->x0 == end->x0) {
        int y_start = start->y0;
        int y_end = end->y0;
        
        // Ensure y_start is smaller
        if (y_start > y_end) {
            int temp = y_start;
            y_start = y_end;
            y_end = temp;
        }
        
        // Draw the vertical line directly
        for (int y = y_start; y <= y_end; y++) {
            putPixel(image, start->x0, y, 1.0, color);
        }
        return;
    }

    // Original code for non-vertical lines
    int steep = abs(end->y0 - start->y0) > abs(end->x0 - start->x0);
    if (steep) {
        int temp = start->x0; start->x0 = start->y0; start->y0 = temp;
        temp = end->x0; end->x0 = end->y0; end->y0 = temp;
    }
    if (start->x0 > end->x0) {
        int temp = start->x0; start->x0 = end->x0; end->x0 = temp;
        temp = start->y0; start->y0 = end->y0; end->y0 = temp;
    }
    float dx = end->x0 - start->x0, dy = end->y0 - start->y0, gradient = dy / dx;
    float xEnd = round(start->x0), yEnd = start->y0 + gradient * (xEnd - start->x0);
    float xGap = 1.0 - (start->x0 + 0.5 - floor(start->x0 + 0.5));
    int xPixel1 = xEnd, yPixel1 = (int)yEnd;
    if (steep) {
        putPixel(image, yPixel1, xPixel1, 1.0 - (yEnd - floor(yEnd)) * xGap, color);
        putPixel(image, yPixel1 + 1, xPixel1, (yEnd - floor(yEnd)) * xGap, color);
    } else {
        putPixel(image, xPixel1, yPixel1, 1.0 - (yEnd - floor(yEnd)) * xGap, color);
        putPixel(image, xPixel1, yPixel1 + 1, (yEnd - floor(yEnd)) * xGap, color);
    }
    float interY = yEnd + gradient;
    xEnd = round(end->x0);
    yEnd = end->y0 + gradient * (xEnd - end->x0);
    xGap = end->x0 + 0.5 - floor(end->x0 + 0.5);
    int xPixel2 = xEnd, yPixel2 = (int)yEnd;
    if (steep) {
        putPixel(image, yPixel2, xPixel2, 1.0 - (yEnd - floor(yEnd)) * xGap, color);
        putPixel(image, yPixel2 + 1, xPixel2, (yEnd - floor(yEnd)) * xGap, color);
    } else {
        putPixel(image, xPixel2, yPixel2, 1.0 - (yEnd - floor(yEnd)) * xGap, color);
        putPixel(image, xPixel2, yPixel2 + 1, (yEnd - floor(yEnd)) * xGap, color);
    }
    for (int x = xPixel1 + 1; x < xPixel2; x++) {
        if (steep) {
            putPixel(image, (int)interY, x, 1.0 - (interY - floor(interY)), color);
            putPixel(image, (int)interY + 1, x, interY - floor(interY), color);
        } else {
            putPixel(image, x, (int)interY, 1.0 - (interY - floor(interY)), color);
            putPixel(image, x, (int)interY + 1, interY - floor(interY), color);
        }
        interY += gradient;
    }
}