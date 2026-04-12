#ifndef FRACT_MANDELBROT_HPP
#define FRACT_MANDELBROT_HPP

#include "Fractal.hpp"
#include "macros.hpp"

class Mandelbrot : public Fractal {
	private:
		__m256i calcIterations(Vec8i cX1, Vec8i cX2, Vec8i cY, __m256i iterationCount[2]);
		void drawRow(int yStart, int yEnd);
		void put8Pixels(__m256i iterations, unsigned int pixelIndex);

	public:
		Mandelbrot(Mlx &inMlx, t_input &input);
		~Mandelbrot();

		void draw() override;
};

#endif