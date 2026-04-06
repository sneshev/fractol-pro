#include "fract.hpp"

#define MOVE_RATIO 0.05f

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
	if (mlx_is_key_down(mlx, MLX_KEY_UP)) {
		move_center(fract, Fixed(WIDTH / 2), Fixed((HEIGHT / 2 - HEIGHT * MOVE_RATIO)));
	}
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN)) {
		move_center(fract, Fixed(WIDTH / 2), Fixed((HEIGHT / 2 + HEIGHT * MOVE_RATIO)));
	}
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT)) {
		move_center(fract, Fixed(WIDTH / 2 - WIDTH * MOVE_RATIO), Fixed(HEIGHT / 2));
	}
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT)) {
		move_center(fract, Fixed(WIDTH / 2 + WIDTH * MOVE_RATIO), Fixed(HEIGHT / 2));
	}
}