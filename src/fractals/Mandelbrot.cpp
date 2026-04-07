#include "Mandelbrot.hpp"
#include "fract.hpp"

Mandelbrot::Mandelbrot(Mlx &inMlx, t_input &input) 
	: Fractal(inMlx, input)
{
	std::cout << GREEN << "Mandelbrot constructor called" << RESET << std::endl;
}

Mandelbrot::~Mandelbrot() {
	std::cout << RED << "Mandelbrot Destructor called" << RESET << std::endl;
}

unsigned int Mandelbrot::calcIterations(Fixed c[2]) {
	Fixed x = 0;
	Fixed y = 0;

	for (unsigned int count = 0; count < _maxIterations; count++) {
		Fixed x2=x*x;
		Fixed y2=y*y;
		Fixed newX = x2 - y2 + c[X];
		y = x*y*2 + c[Y];
		x = newX;
		
		if (x2+y2 > 4)
			return (count);
	}
	return (_maxIterations);
}

void Mandelbrot::putPixel(unsigned int iterations, unsigned int pixelIndex) {
	// mlx_put_pixel(getImg(), x, y, pixelColor);
	t_v4 color = getColor(iterations, _maxIterations);

	_pixels[pixelIndex] = color;
}

void Mandelbrot::drawRow(int yStart, int yEnd) {
	Fixed c[2];
	Fixed xStep = (_xMax - _xMin) / width;
	Fixed yStep = (_yMax - _yMin) / height;
	for (int y = yStart; y < yEnd; y++) {
		c[Y] = _yMin + yStep * y;
		int rowOffset = y * width;
		for (int x = 0; x < width; x++) {
			c[X] = _xMin + xStep * x;
			unsigned int iterations = calcIterations(c);
			unsigned int pixelIndex = rowOffset + x;
			putPixel(iterations, pixelIndex);
		}
	}
}

void Mandelbrot::draw() {
	int threadAmount = thread::hardware_concurrency();
	if (!threadAmount) { threadAmount = 8; }

	std::vector<thread> threads;
	int rowsPerThread = height / threadAmount;

	for (int i = 0; i < threadAmount; i++) {
		int yStart = i * rowsPerThread;
		int yEnd = (i == threadAmount - 1) ? height : yStart + rowsPerThread;
		threads.emplace_back(&Mandelbrot::drawRow, this, yStart, yEnd);
	}
	for (thread &t: threads) {
		t.join();
	}
}