#include "fract.hpp"

#define ZOOM_RATIO 0.7f

void zoom(Fractal &fract, Fixed zoomRatio) {
	Fixed centerX = fract.getXCenter();
	Fixed centerY = fract.getYCenter();
	Fixed newHalfRangeX = (fract.getXRange() * zoomRatio) / 2;
	Fixed newHalfRangeY = (fract.getYRange() * zoomRatio) / 2;

	fract.setXMin(centerX - newHalfRangeX);
	fract.setYMin(centerY - newHalfRangeY);
	fract.setXMax(centerX + newHalfRangeX);
	fract.setYMax(centerY + newHalfRangeY);
	fract.info();
	fract.draw();
}

void mlx_keyhooks(void *inFractal) {
	Fractal &fract = *(Fractal *)inFractal;

	mlx_t *mlx = fract.getMlx();
	// mlx_image_t *img = fract.getImg();

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);

	if (mlx_is_key_down(mlx, MLX_KEY_W)) {
		zoom(fract, Fixed(ZOOM_RATIO));
	}
	if (mlx_is_key_down(mlx, MLX_KEY_S)) {
		zoom(fract, Fixed(1 / ZOOM_RATIO));
	}
	// if (mlx_is_key_down(mlx, MLX_KEY_UP)) {

	// }
	// if (mlx_is_key_down(mlx, MLX_KEY_DOWN)) {

	// }
	// if (mlx_is_key_down(mlx, MLX_KEY_LEFT)) {

	// }
	// if (mlx_is_key_down(mlx, MLX_KEY_RIGHT)) {

	// }
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
