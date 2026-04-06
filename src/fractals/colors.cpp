#include "fract.hpp"

static int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

int getColor(unsigned int iterations, unsigned int max_iterations) {
    if (iterations == max_iterations)
        return ft_pixel(0, 0, 0, 255); // black, fully opaque

    int r, g, b;

    if (iterations < 6) {
        r = 255;
        g = iterations * 40;
        b = 0;
    } else {
        r = 255 - iterations * 5;
        g = 0;
        b = iterations * 10;
    }
    return ft_pixel(r, g, b, 255);
}