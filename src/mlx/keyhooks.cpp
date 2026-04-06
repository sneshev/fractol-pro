#include "fract.hpp"

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