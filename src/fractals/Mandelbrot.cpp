#include "Mandelbrot.hpp"

Mandelbrot::Mandelbrot(Mlx &inMlx, t_input &input) 
	: Fractal(inMlx, input)
{
	std::cout << GREEN << "Mandelbrot constructor called" << RESET << std::endl;
}

Mandelbrot::~Mandelbrot() {
	std::cout << RED << "Mandelbrot Destructor called" << RESET << std::endl;
}

unsigned int Mandelbrot::calcIterations(Fixed c[2], unsigned int maxIterations) {
	Fixed x = 0;
	Fixed y = 0;

	for (unsigned int count = 0; count < maxIterations; count++) {
		Fixed newX = x*x - y*y + c[X];
		y = Fixed(2)*x*y + c[Y];
		x = newX;

		if (x*x + y*y >= 4)
			return (count);
	}
	return (maxIterations);
}

void Mandelbrot::drawRow(int yStart, int yEnd) {
	Fixed c[2];

	Fixed xStep = (_xMax - _xMin) / WIDTH;
	Fixed yStep = (_yMax - _yMin) / HEIGHT;
	for (int y = yStart; y < yEnd; y++) {
		c[Y] = _yMin + yStep * y;
		for (int x = 0; x < WIDTH; x++) {
			c[X] = _xMin + xStep * x;
			unsigned int iterations = calcIterations(c, _maxIterations);
			uint32_t pixelColor = getColor(iterations, _maxIterations);
			mlx_put_pixel(getImg(), x, y, pixelColor);
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