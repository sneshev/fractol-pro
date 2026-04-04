#include "Fractal.hpp"

Fractal::Fractal(Mlx &inMlx, t_input &input) 
	:	_mlx(inMlx),
		_type(input.type),
		_cReal(input.args[0]),
		_cImag(input.args[1])
{
	std::cout << GREEN << "Fractal constructor called" << RESET << std::endl;
}

Fractal::~Fractal() {
	std::cout << RED << "Fractal Destructor called" << RESET << std::endl;
}

void Fractal::mlxLoop() {
	_mlx.loop();
}

void Fractal::mlxTerminate() {
	_mlx.terminate();
}