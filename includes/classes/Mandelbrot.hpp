#ifndef FRACT_MANDELBROT_HPP
#define FRACT_MANDELBROT_HPP

#include "Fractal.hpp"
#include "macros.hpp"

class Mandelbrot : public Fractal {
	private:
		Vec8i calcIterations(Vec8i cX, Vec8i cY);
		void drawRow(int yStart, int yEnd);
		void putPixel(Vec8i iterations, unsigned int pixelIndex);

	public:
		Mandelbrot(Mlx &inMlx, t_input &input);
		~Mandelbrot();

		void draw() override;
};

#endif