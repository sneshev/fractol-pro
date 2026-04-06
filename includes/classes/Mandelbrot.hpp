#ifndef FRACT_MANDELBROT_HPP
#define FRACT_MANDELBROT_HPP

#include "Fractal.hpp"
#include "macros.hpp"

class Mandelbrot : public Fractal {
	private:
		unsigned int calcIterations(Fixed c[2]);
		void drawRow(int yStart, int yEnd);
		void putPixel(unsigned int iterations, unsigned int pixelIndex);

	public:
		Mandelbrot(Mlx &inMlx, t_input &input);
		~Mandelbrot();

		void draw() override;
};

#endif