#include "fract.hpp"


int main(int argc, char *argv[]) {
	t_input input;
	if (!isValidInput(argc, argv, input)) { return (1); }

	Mlx mlx;
	Mandelbrot fract(mlx, input);

	fract.info();
	fract.draw();

	fract.mlxLoop();

	return (EXIT_SUCCESS);
}
