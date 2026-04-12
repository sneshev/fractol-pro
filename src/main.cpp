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


/* ideas / to do:
	.make Julia set (duh)
	.fix zoom and move when width/height change
	.make iterations change automatically with zoom
	.make the 8 32-bit Vec8i into a 4 64-bit for crazy zoom 
	.make get8Colors and put8Pixels fully AVX2 style and optimize

*/