#ifndef FRACT_MANDELBROT_HPP
#define FRACT_MANDELBROT_HPP

#include "Fractal.hpp"
#include "macros.hpp"

class Mandelbrot : public Fractal {
	private:
		__m256i calcIterations8i(Vec8i cX, Vec8i cY) override;
		__m256i calcIterations4d(Vec4d cX, Vec4d cY) override;

	public:
		Mandelbrot(Mlx &inMlx, t_input &input);
		~Mandelbrot();
};

#endif