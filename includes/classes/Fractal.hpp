#ifndef FRACTAL_HPP
#define FRACTAL_HPP

#include "Fixed.hpp"
#include "Mlx.hpp"
#include "typedefs.hpp"

class Fractal {
	private:
		Mlx&			_mlx;
		e_fract_type	_type;

		Fixed	_cReal;
		Fixed	_cImag;
		Fixed	_minRange[2];
		Fixed	_maxRange[2];
		int		_maxIterations;

	public:
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