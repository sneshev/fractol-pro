#ifndef FRACTAL_HPP
#define FRACTAL_HPP

#include "Fixed.hpp"
#include "FixedL.hpp"
#include "Vec8i.hpp"
#include "Vec4L.hpp"
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
		FixedL			_xMinL;
		FixedL			_xMaxL;
		FixedL			_yMinL;
		FixedL			_yMaxL;

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

		bool isPrecise() const;
		void setPrecise(bool type);

		FixedL getXMinL() const;
		FixedL getXMaxL() const;
		FixedL getXCenterL() const;
		FixedL getXRangeL() const;
		FixedL getXRangeHalfL() const;

		FixedL getYMinL() const;
		FixedL getYMaxL() const;
		FixedL getYCenterL() const;
		FixedL getYRangeL() const;
		FixedL getYRangeHalfL() const;

		void setXMinL(const FixedL &inX);
		void setXMaxL(const FixedL &inX);
		void setYMinL(const FixedL &inY);
		void setYMaxL(const FixedL &inY);

		void adjustMaxIterations(const int i);
};

t_v4 getColors(int iterations, int max_iterations);

#endif