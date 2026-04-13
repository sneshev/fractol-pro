#include "fract.hpp"

void juliaAdjustC(Julia* fract, keys_t key) {
	if (key == MLX_KEY_Q)
		fract->adjustCY(-JULIA_ADJUST_AMOUNT);
	else if (key == MLX_KEY_E)
		fract->adjustCY(JULIA_ADJUST_AMOUNT);
	else if (key == MLX_KEY_A)
		fract->adjustCX(-JULIA_ADJUST_AMOUNT);
	else if (key == MLX_KEY_D)
		fract->adjustCX(JULIA_ADJUST_AMOUNT);
	fract->draw();
	fract->info();
}