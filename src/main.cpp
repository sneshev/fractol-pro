#include "fract.hpp"

void mlx_keyhooks(void *inFractal) {
	Fractal *fract = (Fractal *)inFractal;

	mlx_t *mlx = fract->getMlx();
	mlx_image_t *img = fract->getImg();

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);

	if (mlx_is_key_down(mlx, MLX_KEY_UP)) {

	}
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN)) {

	}
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT)) {

	}
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT)) {

	}
}

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
