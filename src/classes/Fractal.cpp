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

void Fractal::info() {
	cout << "type: ";
	switch (_type) {
		case FRCT_MANDELBROT:
			cout << "Mandelbrot" << endl;
			break ;
		case FRCT_JULIA:
			cout << "Julia" << endl;
			break ;
		default:
			break ;
	}
	cout << "c real: " <<  _cReal << endl;
	cout << "c imag: " <<  _cImag << endl;
}