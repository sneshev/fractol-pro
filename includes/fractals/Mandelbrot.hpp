#ifndef FRACT_MANDELBROT_HPP
#define FRACT_MANDELBROT_HPP

#include "Fractal.hpp"
#include "macros.hpp"

class Mandelbrot : public Fractal {
	private:
		__m256i calcIterations8i(Vec8i cX, Vec8i cY);
		__m256i calcIterations4d(Vec4d cX, Vec4d cY);
		void drawRow8i(int yStart, int yEnd);
		void drawRow4d(int yStart, int yEnd);
		void put4Pixels(__m256i iterations, unsigned int pixelIndex);
		void put8Pixels(__m256i iterations, unsigned int pixelIndex);

	public:
		Mandelbrot(Mlx &inMlx, t_input &input);
		~Mandelbrot();

		void draw() override;
};

#endif