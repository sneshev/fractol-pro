#include "fract.hpp"

void mlx_keyhooks(void *inFractal) {
	Fractal &fract = *(Fractal *)inFractal;
	mlx_t *mlx = fract.getMlx();
	
	{ /* quit program */
		if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
			mlx_close_window(mlx);
	}
	
	{ /* zoom in/out */
		if (mlx_is_key_down(mlx, MLX_KEY_W))
			zoom(fract, ZOOM_RATIO);
		if (mlx_is_key_down(mlx, MLX_KEY_S))
			zoom(fract, 1 / ZOOM_RATIO);
	}

	{ /* move center */
		if (mlx_is_key_down(mlx, MLX_KEY_UP)) {
			move_center(fract, (float)(width / 2), ((float)height / 2 - (float)height * MOVE_RATIO));
		}
		if (mlx_is_key_down(mlx, MLX_KEY_DOWN)) {
			move_center(fract, (float)(width / 2), ((float)height / 2 + (float)height * MOVE_RATIO));
		}
		if (mlx_is_key_down(mlx, MLX_KEY_LEFT)) {
			move_center(fract, ((float)width / 2 - (float)width * MOVE_RATIO), (float)(height / 2));
			}
		if (mlx_is_key_down(mlx, MLX_KEY_RIGHT)) {
			move_center(fract, ((float)width / 2 + (float)width * MOVE_RATIO), (float)(height / 2));
		}
	}

	{ /* change max iterations */
		if (mlx_is_key_down(mlx, MLX_KEY_COMMA))
			fract.adjustMaxIterations(-ITERATION_RATIO);
		if (mlx_is_key_down(mlx, MLX_KEY_PERIOD))
			fract.adjustMaxIterations(ITERATION_RATIO);
	}
}