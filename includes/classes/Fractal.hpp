#ifndef FRACTAL_HPP
#define FRACTAL_HPP

#include "Fixed.hpp"
#include "Mlx.hpp"
#include "typedefs.hpp"

class Fractal {
	private:
		Mlx&			_mlx;

		Fixed	_minRange[2];
		Fixed	_maxRange[2];
		int		_maxIterations;

	public:
		e_fract_type	_type;
		Fixed	_cReal;

		Fixed	_cImag;
		Fractal(Mlx &inMlx, t_input &input);
		~Fractal();

		void mlxLoop();
		void mlxTerminate();
		// void draw();
		// void zoom();
		// void move();
		// ...

};

#endif