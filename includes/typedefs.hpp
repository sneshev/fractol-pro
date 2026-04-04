#ifndef FRACT_TYPEDEFS_HPP
#define FRACT_TYPEDEFS_HPP

#include <array>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define X 0
#define Y 1

#define MIN 0
#define MAX 1


#define str std::string
#define arr std::array
using std::cout;
using std::cin;
using std::endl;

typedef enum s_fract_type {
	FRCT_MANDELBROT,
	FRCT_JULIA,
	FRCT_CLEANUP_TYPE_COUNT
}	e_fract_type;

typedef struct s_input {
	e_fract_type		type;
	std::vector<float>	args;
}	t_input;

#endif