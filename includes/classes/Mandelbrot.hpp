#ifndef FRACT_MANDELBROT_HPP
#define FRACT_MANDELBROT_HPP

#include "Fractal.hpp"
#include "macros.hpp"

class Mandelbrot : public Fractal {
	private:
		unsigned int calcIterations(Fixed c[2], unsigned int maxIterations);
		void drawRow(int yStart, int yEnd);
	
	public:
		Mandelbrot(Mlx &inMlx, t_input &input);
		~Mandelbrot();

		void draw() override;
};

#endif