#include "fract.hpp"


Fractal *getFractal(Mlx& mlx, t_input& input) {
	if (input.type == FRCT_MANDELBROT)
		return (new Mandelbrot(mlx, input));
	else if (input.type == FRCT_JULIA)
		return (new Julia(mlx, input));
	else
		exit(1);
}

int main(int argc, char *argv[]) {
	t_input input;
	if (!isValidInput(argc, argv, input)) { return (1); }

	Mlx mlx;
	Fractal *fract = getFractal(mlx, input);

	fract->info();
	fract->draw();

	mlx_loop_hook(fract->getMlx(), mlx_keyhooks, fract);

	fract->mlxLoop();
	delete fract;
	return (EXIT_SUCCESS);
}


/* ideas / to do:
	.adjust fractal bounds (when aspect ratio changes)
	.make keyhooks more chill but if you hold shift be fast 
	.make more legible (esp. zoom() and move())
	.make Julia set (duh)
	.fix zoom and move when width/height change
	.add mouse hooks like my other fract-ol
	.make iterations change automatically with zoom
	.make the 8 32-bit Vec8i into a 4 64-bit for crazy zoom 
	.make get8Colors and put8Pixels fully AVX2 style and optimize
	.when its a Fixed 32-bit the overflow creates pretty 
	 patterns away from the center but when it switches 
	 to the precise mode, the doubles dont overflow and 
	 its not there anymore. Fix the zoom so that it stops
	 at the limit of the Fixed 32-bit and it doesnt go to 
	 the precise if its not around the center 
*/