#ifndef FRACT_JULIA_HPP
#define FRACT_JULIA_HPP

#include "Fractal.hpp"
#include "macros.hpp"

class Julia : public Fractal {
	private:
		Fixed _cX;
		Fixed _cY;

		double _cX_d;
		double _cY_d;

		__m256i calcIterations8i(Vec8i cX, Vec8i cY);
		__m256i calcIterations4d(Vec4d cX, Vec4d cY);
		void drawRow8i(int yStart, int yEnd);
		void drawRow4d(int yStart, int yEnd);
		void put4Pixels(__m256i iterations, unsigned int pixelIndex);
		void put8Pixels(__m256i iterations, unsigned int pixelIndex);

	public:
		Julia(Mlx &inMlx, t_input &input);
		~Julia();

		void draw() override;
};

#endif