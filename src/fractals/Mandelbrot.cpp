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

Vec8i Mandelbrot::calcIterations(Vec8i cX, Vec8i cY) {
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
	Fixed xStep = (_xMax - _xMin) / width;
	Fixed yStep = (_yMax - _yMin) / height;
	for (int y = yStart; y < yEnd; y++) {
		Vec8i cY(_yMin + yStep * y);
		int rowOffset = y * width;
		for (int x = 0; x < width; x += 8) {
			Vec8i cX(
				_xMin + xStep * (x + 7),
				_xMin + xStep * (x + 6),
				_xMin + xStep * (x + 5),
				_xMin + xStep * (x + 4),
				_xMin + xStep * (x + 3),
				_xMin + xStep * (x + 2),
				_xMin + xStep * (x + 1),
				_xMin + xStep * (x + 0)
			);
			Vec8i iterations = calcIterations(cX, cY);
			unsigned int pixelIndex = rowOffset + x;
			// putPixel(iterations, pixelIndex);
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