#ifndef FRACT_TYPEDEFS_HPP
#define FRACT_TYPEDEFS_HPP

#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <string>
#include <thread>

#define X 0
#define Y 1

#define MIN 0
#define MAX 1


#define str std::string
#define arr std::array
#define thread std::thread
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