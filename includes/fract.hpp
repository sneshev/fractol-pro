#ifndef FRACT_HPP
#define FRACT_HPP

#include "../MLX42/include/MLX42/MLX42.h"
#include "Fixed.hpp"
#include "Fractal.hpp"
#include "macros.hpp"
#include "typedefs.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// mlx
Mlx initializeMlx();

// parsing
bool isValidInput(int argc, char *argv[], t_input &input);


#endif