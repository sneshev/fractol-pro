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

e_fract_type Fractal::getType() {
	return (_type);
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
	if (_precise) {
		cout << "precise: true" << endl;
		cout << "x min d: " <<  _xMin_d << endl;
		cout << "x max d: " <<  _xMax_d << endl;
		cout << "y min d: " <<  _yMin_d << endl;
		cout << "y max d: " <<  _yMax_d << endl;
		cout << "x range d: " <<  getXRange_d() << endl;
		cout << "y range d: " <<  getYRange_d() << endl;

	} else {
		cout << "precise: false" << endl;
		cout << "x min: " <<  _xMin << endl;
		cout << "x max: " <<  _xMax << endl;
		cout << "y min: " <<  _yMin << endl;
		cout << "y max: " <<  _yMax << endl;
		cout << "x range: " <<  getXRange() << endl;
		cout << "y range: " <<  getYRange() << endl;
	}
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

bool Fractal::isPrecise() const {
	return (_precise);
}

void Fractal::setPrecise(bool type) {
	if (type == false) {
		_xMin = Fixed((float)_xMin_d);
		_xMax = Fixed((float)_xMax_d);
		_yMin = Fixed((float)_yMin_d);
		_yMax = Fixed((float)_yMax_d);
		_precise = false;
	} else {
		_xMin_d = (double)_xMin.toFloat();
		_xMax_d = (double)_xMax.toFloat();
		_yMin_d = (double)_yMin.toFloat();
		_yMax_d = (double)_yMax.toFloat();
		_precise = true;
	}
}


void Fractal::setXMin(const Fixed &inX) { _xMin = inX; }
void Fractal::setYMin(const Fixed &inY) { _yMin = inY; }
void Fractal::setXMax(const Fixed &inX) { _xMax = inX; }
void Fractal::setYMax(const Fixed &inY) { _yMax = inY; }

double Fractal::getXMin_d() const		{ return (_xMin_d); }
double Fractal::getXMax_d() const		{ return (_xMax_d); }
double Fractal::getXRange_d() const		{ return (_xMax_d - _xMin_d); }
double Fractal::getXCenter_d() const	{ return ((_xMax_d + _xMin_d) / 2); }
double Fractal::getXRangeHalf_d() const	{ return ((_xMax_d - _xMin_d) / 2); }

double Fractal::getYMin_d() const		{ return (_yMin_d); }
double Fractal::getYMax_d() const		{ return (_yMax_d); }
double Fractal::getYRange_d() const		{ return (_yMax_d - _yMin_d); }
double Fractal::getYCenter_d() const	{ return ((_yMax_d + _yMin_d) / 2); }
double Fractal::getYRangeHalf_d() const	{ return ((_yMax_d - _yMin_d) / 2); }

void Fractal::setXMin_d(const double inX) { _xMin_d = inX; }
void Fractal::setXMax_d(const double inX) { _xMax_d = inX; }
void Fractal::setYMin_d(const double inY) { _yMin_d = inY; }
void Fractal::setYMax_d(const double inY) { _yMax_d = inY; }

void Fractal::adjustMaxIterations(const int i) {
	long newValue = _maxIterations + i;
	if (newValue < 10 || newValue > 2500) {
		return ;
	}
	_maxIterations += i;
	info();
	draw();
}