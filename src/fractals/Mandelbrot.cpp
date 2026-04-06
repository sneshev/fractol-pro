#include "Mandelbrot.hpp"

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
		Fixed newX = x*x - y*y + c[X];
		y = x*y*2 + c[Y];
		x = newX;
		
		if (x.getDoubledValue() + y.getDoubledValue() >= 4)
			return (count);
	}
	return (_maxIterations);
}

void Mandelbrot::putPixel(unsigned int iterations, unsigned int pixelIndex) {
	// mlx_put_pixel(getImg(), x, y, pixelColor);
	uint8_t pixelColor[4];
	getColor(iterations, _maxIterations, pixelColor);

	_pixels[pixelIndex + 0] = pixelColor[R];
	_pixels[pixelIndex + 1] = pixelColor[G];
	_pixels[pixelIndex + 2] = pixelColor[B];
	_pixels[pixelIndex + 3] = pixelColor[A];
}

void Mandelbrot::drawRow(int yStart, int yEnd) {
	Fixed c[2];
	Fixed xStep = (_xMax - _xMin) / WIDTH;
	Fixed yStep = (_yMax - _yMin) / HEIGHT;
	for (int y = yStart; y < yEnd; y++) {
		c[Y] = _yMin + yStep * y;
		int rowOffset = y * WIDTH * 4;
		for (int x = 0; x < WIDTH; x++) {
			c[X] = _xMin + xStep * x;
			unsigned int iterations = calcIterations(c);
			unsigned int pixelIndex = rowOffset + x * 4;
			putPixel(iterations, pixelIndex);
		}
	}
}

void Mandelbrot::draw() {
	int threadAmount = thread::hardware_concurrency();
	if (!threadAmount) { threadAmount = 8; }

	std::vector<thread> threads;
	int rowsPerThread = HEIGHT / threadAmount;

	for (int i = 0; i < threadAmount; i++) {
		int yStart = i * rowsPerThread;
		int yEnd = (i == threadAmount - 1) ? HEIGHT : yStart + rowsPerThread;
		threads.emplace_back(&Mandelbrot::drawRow, this, yStart, yEnd);
	}
	for (thread &t: threads) {
		t.join();
	}
}