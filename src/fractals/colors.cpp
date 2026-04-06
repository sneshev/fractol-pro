#include "fract.hpp"

// static int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// {
    // return (r << 24 | g << 16 | b << 8 | a);
// }

void getColor(unsigned int iterations, unsigned int max_iterations, uint8_t pixelColor[4]) {
    if (iterations == max_iterations) {
        pixelColor[R] = 0;
        pixelColor[G] = 0;
        pixelColor[B] = 0;
        pixelColor[A] = 255;
        return ;
    }

    if (iterations < 6) {
        pixelColor[R] = 255;
        pixelColor[G] = iterations * 40;
        pixelColor[B] = 0;
        pixelColor[A] = 255;
    } else {
        pixelColor[R] = 255 - iterations * 5;
        pixelColor[G] = 0;
        pixelColor[B] = iterations * 10;
        pixelColor[A] = 255;
    }
}