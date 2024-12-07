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


void draw_line_xiaolim(mlx_image_t* image, const t_point *start, const t_point *end, uint32_t color)
{
    // Copy coordinates into local variables
    int x0 = start->x1;
    int y0 = start->y1;
    int x1 = end->x1;
    int y1 = end->y1;

    // Handle vertical line as a special case for clarity
    if (x0 == x1) {
        if (y0 > y1) {
            int temp = y0; y0 = y1; y1 = temp;
        }
        for (int y = y0; y <= y1; y++) {
            putPixel(image, x0, y, 1.0, color);
        }
        return;
    }

    // Xiaolin Wu's line algorithm
    int steep = abs(y1 - y0) > abs(x1 - x0);

    // If the line is steep, swap x and y for both points
    if (steep) {
        int temp = x0; x0 = y0; y0 = temp;
        temp = x1; x1 = y1; y1 = temp;
    }

    // Ensure x0 < x1
    if (x0 > x1) {
        int temp = x0; x0 = x1; x1 = temp;
        temp = y0; y0 = y1; y1 = temp;
    }

    float dx = (float)(x1 - x0);
    float dy = (float)(y1 - y0);
    float gradient = dx == 0.0f ? 1.0f : (dy / dx);

    // First endpoint
    float xEnd = floorf(x0 + 0.5f);
    float yEnd = y0 + gradient * (xEnd - x0);
    float xGap = 1.0f - ((x0 + 0.5f) - floorf(x0 + 0.5f));
    int xPixel1 = (int)xEnd;
    int yPixel1 = (int)floorf(yEnd);

    float alpha1 = 1.0f - (yEnd - floorf(yEnd)) * xGap;
    float alpha2 = (yEnd - floorf(yEnd)) * xGap;

    if (steep) {
        putPixel(image, yPixel1,     xPixel1, alpha1, color);
        putPixel(image, yPixel1 + 1, xPixel1, alpha2, color);
    } else {
        putPixel(image, xPixel1, yPixel1,     alpha1, color);
        putPixel(image, xPixel1, yPixel1 + 1, alpha2, color);
    }

    float interY = yEnd + gradient;

    // Second endpoint
    xEnd = floorf(x1 + 0.5f);
    yEnd = y1 + gradient * (xEnd - x1);
    xGap = (x1 + 0.5f) - floorf(x1 + 0.5f);
    int xPixel2 = (int)xEnd;
    int yPixel2 = (int)floorf(yEnd);

    float alpha3 = 1.0f - (yEnd - floorf(yEnd)) * xGap;
    float alpha4 = (yEnd - floorf(yEnd)) * xGap;

    if (steep) {
        putPixel(image, yPixel2,     xPixel2, alpha3, color);
        putPixel(image, yPixel2 + 1, xPixel2, alpha4, color);
    } else {
        putPixel(image, xPixel2, yPixel2,     alpha3, color);
        putPixel(image, xPixel2, yPixel2 + 1, alpha4, color);
    }

    // Main loop
    for (int x = xPixel1 + 1; x < xPixel2; x++) {
        float frac = interY - floorf(interY);
        float alphaTop = 1.0f - frac;
        float alphaBottom = frac;

        if (steep) {
            putPixel(image, (int)floorf(interY),     x, alphaTop,    color);
            putPixel(image, (int)floorf(interY) + 1, x, alphaBottom, color);
        } else {
            putPixel(image, x, (int)floorf(interY),     alphaTop,    color);
            putPixel(image, x, (int)floorf(interY) + 1, alphaBottom, color);
        }

        interY += gradient;
    }
}