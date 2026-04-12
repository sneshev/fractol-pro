#ifndef FRACT_HPP
#define FRACT_HPP

#include "../MLX42/include/MLX42/MLX42.h"
#include "Fixed.hpp"
#include "Vec8i.hpp"
#include "Vec4d.hpp"
#include "Fractal.hpp"
#include "Mandelbrot.hpp"
#include "Julia.hpp"
#include "macros.hpp"
#include "typedefs.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

constexpr int WIDTH  = WIDTH_RAW  - (WIDTH_RAW  % 16);
constexpr int HEIGHT = HEIGHT_RAW - (HEIGHT_RAW % 16);

// mlx
void mlx_keyhooks(void *inFractal);
void move_center(Fractal &fract, float rawX, float rawY);
void zoom(Fractal &fract, float zoomRatio);

// parsing
bool isValidInput(int argc, char *argv[], t_input &input);


#endif