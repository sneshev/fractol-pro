#include "Fractal.hpp"
#include "macros.hpp"

Fractal::Fractal(Mlx &inMlx, t_input &input) 
	:	_mlx(inMlx),
		_type(input.type),
		_cReal(input.args[0]),
		_cImag(input.args[1]),
		_xRange({Fixed(MIN_REAL), Fixed(MAX_REAL)}),
		_yRange({Fixed(MIN_IMAG), Fixed(MAX_IMAG)}),
		_maxIterations(MAX_ITERATIONS)
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
	cout << "minRangeX: " << _xRange[MIN] << endl;
	cout << "minRangeX: " << _xRange[MAX] << endl;
	cout << "maxRangeX: " << _yRange[MIN] << endl;
	cout << "maxRangeX: " << _yRange[MAX] << endl;
	cout << "maxIterations: " << _maxIterations<< endl;
}

mlx_t* Fractal::getMlx() {
	return (_mlx.getMlx());
}

mlx_image_t* Fractal::getImg() {
	return (_mlx.getImg());
}