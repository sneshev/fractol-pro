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
	unsigned int	count = 0;
	
	Fixed x = 0;
	Fixed y = 0;
	do {
		Fixed newX = x*x - y*y + c[X];
		y = Fixed(2)*x*y + c[Y];
		x = newX;
		if (x*x + y*y >= 4) {
			return (count);
		}
	} while (count++ < maxIterations);
	return (count);
}

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}
static int getColor(unsigned int iterations, unsigned int max_iterations) {
    if (iterations == max_iterations)
        return ft_pixel(0, 0, 0, 255); // black, fully opaque

    int r, g, b;

    if (iterations < 6) {
        r = 255;
        g = iterations * 40;
        b = 0;
    } else {
        r = 255 - iterations * 5;
        g = 0;
        b = iterations * 10;
    }
    return ft_pixel(r, g, b, 255);
}

#include <unistd.h>

void Mandelbrot::draw() {
	cout << "drawing mandelbrot" << endl;
	Fixed c[2];

	Fixed xStep = (_xRange[MAX] - _xRange[MIN]) / WIDTH;
	Fixed yStep = (_yRange[MAX] - _yRange[MIN]) / HEIGHT;
	for (int y = 0; y < HEIGHT; y++) {
		c[Y] = _yRange[MIN] + yStep * y;
		for (int x = 0; x < WIDTH; x++) {
			c[X] = _xRange[MIN] + xStep * x;
			unsigned int iterations = calcIterations(c, _maxIterations);
			uint32_t pixelColor = getColor(iterations, _maxIterations);
			mlx_put_pixel(getImg(), x, y, pixelColor);
			// cout << "putting at " << x << y << endl;
		}
	}
}

/*
	colors like #define REDY 0xFF0000 dont work because there is no alpha
	need operators for Fixed + int, etc.

*/