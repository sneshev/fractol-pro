#include "Fractal.hpp"

Fractal::Fractal(Mlx &inMlx, t_input &input) 
	:	_mlx(inMlx),
		_type(input.type)
{
	if (input.type == FRCT_JULIA) {
		if (input.args.size() == 2) {
			_cReal = Fixed(input.args[0]);
			_cImag = Fixed(input.args[1]);
		} else {
			_cReal = Fixed(-0.7f);
			_cImag = Fixed(0.27015f);
		}
	} else {
		_cReal = Fixed(0);
		_cImag = Fixed(0);
	}
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