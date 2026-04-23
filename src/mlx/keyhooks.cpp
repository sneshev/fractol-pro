#include "fract.hpp"
void juliaAdjustC(Julia* fract, keys_t key);

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
			move_center(fract, (float)(WIDTH / 2), ((float)HEIGHT / 2 - (float)HEIGHT * MOVE_RATIO));
		}
		if (mlx_is_key_down(mlx, MLX_KEY_DOWN)) {
			move_center(fract, (float)(WIDTH / 2), ((float)HEIGHT / 2 + (float)HEIGHT * MOVE_RATIO));
		}
		if (mlx_is_key_down(mlx, MLX_KEY_LEFT)) {
			move_center(fract, ((float)WIDTH / 2 - (float)WIDTH * MOVE_RATIO), (float)(HEIGHT / 2));
			}
		if (mlx_is_key_down(mlx, MLX_KEY_RIGHT)) {
			move_center(fract, ((float)WIDTH / 2 + (float)WIDTH * MOVE_RATIO), (float)(HEIGHT / 2));
		}
	}

	{ /* change max iterations */
		if (mlx_is_key_down(mlx, MLX_KEY_COMMA))
			fract.adjustMaxIterations(-ITERATION_RATIO);
		if (mlx_is_key_down(mlx, MLX_KEY_PERIOD))
			fract.adjustMaxIterations(ITERATION_RATIO);
	}

	{ /* julia change c */
		if (fract.getType() == FRCT_JULIA) {
			if (mlx_is_key_down(mlx, MLX_KEY_Q)) {
				juliaAdjustC(static_cast<Julia*>(&fract), MLX_KEY_Q);
			}
			if (mlx_is_key_down(mlx, MLX_KEY_A)) {
				juliaAdjustC(static_cast<Julia*>(&fract), MLX_KEY_A);
			}
			if (mlx_is_key_down(mlx, MLX_KEY_E)) {
				juliaAdjustC(static_cast<Julia*>(&fract), MLX_KEY_E);
			}
			if (mlx_is_key_down(mlx, MLX_KEY_D)) {
				juliaAdjustC(static_cast<Julia*>(&fract), MLX_KEY_D);
			}
		}
	}
}
