#ifndef FRACTAL_HPP
#define FRACTAL_HPP

#include "Fixed.hpp"
#include "Mlx.hpp"
#include "typedefs.hpp"

class Fractal {
	protected:
		Mlx&			_mlx;
		__m256i*		_pixels;
		e_fract_type	_type;

		Fixed			_xMin;
		Fixed			_xMax;
		Fixed			_yMin;
		Fixed			_yMax;

		unsigned int	_maxIterations;

	public:
		Fractal(Mlx &inMlx, t_input &input);
		~Fractal();

		void info();
		void mlxLoop();

		virtual void draw() = 0;
		// void zoom();
		// void move();
		// ...

		mlx_t*			getMlx();
		mlx_image_t*	getImg();

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

		void adjustMaxIterations(const int i);
};

__m256i getColors(Vec8i iterations, unsigned int max_iterations);

#endif