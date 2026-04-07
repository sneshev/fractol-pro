#include "fract.hpp"

// static int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// {
    // return (r << 24 | g << 16 | b << 8 | a);
// }

__m256i getColors(Vec8i iterations, unsigned int max_iterations) {
    // if (iterations == max_iterations) {
        // return ((t_v4){0, 0, 0, 255});
    // }
    // if (iterations < 6) {
        // return ((t_v4){255, (uint8_t)(iterations * 40), 0, 255});
    // }
    // else {
        // return ((t_v4){(uint8_t)(255 - iterations * 5), 0, (uint8_t)(iterations * 10), 255});
    // }
}