#ifndef FRACTAL_HPP
#define FRACTAL_HPP

#include "Fixed.hpp"
#include "Vec8i.hpp"
#include "Vec4d.hpp"
#include "Mlx.hpp"
#include "typedefs.hpp"
#include <immintrin.h>

class Fractal {
	protected:
		Mlx&			_mlx;
		uint32_t*		_pixels;
		e_fract_type	_type;

		Fixed			_xMin;
		Fixed			_xMax;
		Fixed			_yMin;
		Fixed			_yMax;

		bool			_precise = false;
		double			_xMin_d;
		double			_xMax_d;
		double			_yMin_d;
		double			_yMax_d;

		unsigned int	_maxIterations;

		virtual __m256i calcIterations8i(Vec8i cX, Vec8i cY) = 0;
		virtual __m256i calcIterations4d(Vec4d cX, Vec4d cY) = 0;
		void drawRow8i(int yStart, int yEnd);
		void drawRow4d(int yStart, int yEnd);
		void put4Pixels(__m256i iterations, unsigned int pixelIndex);
		void put8Pixels(__m256i iterations, unsigned int pixelIndex);

	public:
		Fractal(Mlx &inMlx, t_input &input);
		virtual ~Fractal();

		void info();
		void mlxLoop();

		void draw();

		e_fract_type	getType();
		mlx_image_t*	getImg();
		mlx_t*			getMlx();

		Fixed getXMin() const;
		Fixed getXMax() const;
		Fixed getXCenter() const;
		Fixed getXRange() const;
		Fixed getXRangeHalf() const;

		Fixed getYMin() const;
		Fixed getYMax() const;
		Fixed getYCenter() const;
		Fixed getYRange() const;
		Fixed getYRangeHalf() const;

		void setXMin(const Fixed &inX);
		void setXMax(const Fixed &inX);
		void setYMin(const Fixed &inY);
		void setYMax(const Fixed &inY);

		bool isPrecise() const;
		virtual void setPrecise(bool type);

		double getXMin_d() const;
		double getXMax_d() const;
		double getXCenter_d() const;
		double getXRange_d() const;
		double getXRangeHalf_d() const;

		double getYMin_d() const;
		double getYMax_d() const;
		double getYCenter_d() const;
		double getYRange_d() const;
		double getYRangeHalf_d() const;

		void setXMin_d(const double inX);
		void setXMax_d(const double inX);
		void setYMin_d(const double inY);
		void setYMax_d(const double inY);

		void adjustMaxIterations(const int i);
};

t_v4 getColors(int iterations, int max_iterations);

#endif