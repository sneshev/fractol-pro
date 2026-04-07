#ifndef FRACT_MACROS_HPP
#define FRACT_MACROS_HPP

#include <iostream>
#include <vector>

const std::vector<std::string> validTypes = {
	"mandelbrot",
	"julia"
};

#define FIXED_FRACTIONAL_BITS 22

#define WIDTH	512
#define HEIGHT	512

#define ZOOM_RATIO 0.7f

#define MAX_ITERATIONS 50
#define ITERATION_RATIO 20

#define MIN_REAL -2.0f
#define MAX_REAL  2.0f
#define MIN_IMAG -2.0f
#define MAX_IMAG  2.0f





#endif