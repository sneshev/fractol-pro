#ifndef FRACT_HPP
#define FRACT_HPP

#include "../MLX42/include/MLX42/MLX42.h"
#include "Fixed.hpp"
#include "Fractal.hpp"
#include "Mandelbrot.hpp"
#include "macros.hpp"
#include "typedefs.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

constexpr int width  = WIDTH  - (WIDTH  % 8);
constexpr int height = HEIGHT - (HEIGHT % 8);

// mlx
void mlx_keyhooks(void *inFractal);
void zoom(Fractal &fract, Fixed zoomRatio);
void move_center(Fractal &fract, Fixed rawX, Fixed rawY);

// parsing
bool isValidInput(int argc, char *argv[], t_input &input);


#endif