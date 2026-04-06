#include "fract.hpp"

void draw_fractal(void *inFractal) {
	Fractal *fract = (Fractal *)inFractal;

	fract->draw();
}

int main(int argc, char *argv[]) {
	t_input input;
	if (!isValidInput(argc, argv, input)) { return (1); }

	Mlx mlx;
	Mandelbrot fract(mlx, input);

	fract.info();
	fract.draw();

	mlx_loop_hook(fract.getMlx(), mlx_keyhooks, &fract);

	fract.mlxLoop();

	return (EXIT_SUCCESS);
}
