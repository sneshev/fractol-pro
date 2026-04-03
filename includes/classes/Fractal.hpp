#ifndef FRACTAL_HPP
#define FRACTAL_HPP

#include "Fixed.hpp"
#include "Mlx.hpp"


typedef struct s_data
{
	mlx_t		*_mlx;
	mlx_image_t	*_img;

	int			_color_set;
	int			_type;
	double		_c[2];
	double		_range_min[2];
	double		_range_max[2];
	int			_max_iterations;
}	t_data;

class Fractal {
	private:

		Fixed	_c[2];
		Fixed	_range_min[2];
		Fixed	_range_max[2];
		int		_max_iterations;

	public:
		Mlx &mlx;

		Fractal(Mlx &inMlx);
		~Fractal();

		// void zoom();
		// void move();
		// ...

};

#endif