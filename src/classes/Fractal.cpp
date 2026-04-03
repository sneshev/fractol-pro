#include "Fractal.hpp"

Fractal::Fractal(Mlx &inMlx) 
	:	mlx(inMlx)
	{
	std::cout << GREEN << "Fractal constructor called" << RESET << std::endl;
}

Fractal::~Fractal() {
	std::cout << RED << "Fractal Destructor called" << RESET << std::endl;
}