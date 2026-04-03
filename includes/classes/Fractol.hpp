#ifndef FRACTOL_HPP
#define FRACTOL_HPP

#include "../MLX42/include/MLX42/MLX42.h"
#include "Fixed.hpp"


typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	int			color_set;
	int			type;
	double		c[2];
	double		range_min[2];
	double		range_max[2];
	int			max_iterations;
}	t_data;


class Fractal {
	private:
		Fractal();
		

		mlx_t		*mlx;
		mlx_image_t	*img;

		Fixed	c[2];
		Fixed	range_min[2];
		Fixed	range_max[2];
		int		max_iterations;

	public:
		void draw();
		// void zoom();
		// void move();
		// ...

};
#endif