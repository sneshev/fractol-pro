#include "Fractal.hpp"
#include "macros.hpp"

Fractal::Fractal(Mlx &inMlx, t_input &input) 
	:	_mlx(inMlx),
		_pixels((uint32_t*)(getImg()->pixels)),
		_type(input.type),
		_xMin(Fixed(MIN_REAL)),
		_xMax(Fixed(MAX_REAL)),
		_yMin(Fixed(MIN_IMAG)),
		_yMax(Fixed(MAX_IMAG)),
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

mlx_t* Fractal::getMlx() {
	return (_mlx.getMlx());
}

mlx_image_t* Fractal::getImg() {
	return (_mlx.getImg());
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
	cout << "x min: " <<  _xMin << endl;
	cout << "x max: " <<  _xMax << endl;
	cout << "y min: " <<  _yMin << endl;
	cout << "y max: " <<  _yMax << endl;
	cout << "x range: " <<  getXRange() << endl;
	cout << "y range: " <<  getYRange() << endl;
	cout << "maxIterations: " << _maxIterations<< endl;
}

Fixed Fractal::getXMin() const		{ return (_xMin); }
Fixed Fractal::getXMax() const		{ return (_xMax); }
Fixed Fractal::getXRange() const	{ return (_xMax - _xMin); }
Fixed Fractal::getXCenter() const	{ return ((_xMax + _xMin) / 2); }

Fixed Fractal::getYMin() const		{ return (_yMin); }
Fixed Fractal::getYMax() const		{ return (_yMax); }
Fixed Fractal::getYCenter() const	{ return ((_yMax + _yMin) / 2); }
Fixed Fractal::getYRange() const	{ return (_yMax - _yMin); }

Fixed Fractal::getXRangeHalf() const {
	Fixed f(_xMax - _xMin);
	f.halfValue();
	return (f);
}

Fixed Fractal::getYRangeHalf() const {
	Fixed f(_yMax - _yMin);
	f.halfValue();
	return (f);
}

void Fractal::setXMin(const Fixed &inX) { _xMin = inX; }
void Fractal::setYMin(const Fixed &inY) { _yMin = inY; }
void Fractal::setXMax(const Fixed &inX) { _xMax = inX; }
void Fractal::setYMax(const Fixed &inY) { _yMax = inY; }

void Fractal::adjustMaxIterations(const int i) {
	long newValue = _maxIterations + i;
	if (newValue < 10 || newValue > 2500) {
		return ;
	}
	_maxIterations += i;
	info();
	draw();
}