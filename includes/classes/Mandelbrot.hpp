#ifndef FRACT_MANDELBROT_HPP
#define FRACT_MANDELBROT_HPP

#include "Fractal.hpp"

class Mandelbrot : public Fractal {
	public:
		Mandelbrot(Mlx &inMlx, t_input &input);
		~Mandelbrot();

		void draw() override;
};

#endif