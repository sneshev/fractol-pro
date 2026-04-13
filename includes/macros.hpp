#ifndef FRACT_MACROS_HPP
#define FRACT_MACROS_HPP

#include <iostream>
#include <vector>

const std::vector<std::string> validTypes = {
	"mandelbrot",
	"julia"
};

#define FIXED_FRACTIONAL_BITS 28

#define WIDTH_RAW	1024
#define HEIGHT_RAW	1024

#define ZOOM_RATIO 0.9f
#define MOVE_RATIO 0.03f
#define ITERATION_RATIO 20
#define JULIA_ADJUST_AMOUNT 0.001f

#define MAX_ITERATIONS 50

#define MIN_REAL -2.0f
#define MAX_REAL  2.0f
#define MIN_IMAG -2.0f
#define MAX_IMAG  2.0f


#endif