#ifndef FRACTAL_HPP
#define FRACTAL_HPP

#include "Fixed.hpp"
#include "Mlx.hpp"
#include "typedefs.hpp"

class Fractal {
	protected:
		Mlx&			_mlx;
		e_fract_type	_type;

		Fixed			_cReal;
		Fixed			_cImag;
		arr<Fixed, 2> 	_xRange;
		arr<Fixed, 2> 	_yRange;
		unsigned int	_maxIterations;

	public:
		Fractal(Mlx &inMlx, t_input &input);
		~Fractal();

		void info();
		void mlxLoop();
		void mlxTerminate();

		virtual void draw() = 0;
		// void zoom();
		// void move();
		// ...

};

#endif