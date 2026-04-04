#include "fract.hpp"

Mlx initializeMlx() {
	mlx_t*			mlx;
	mlx_image_t*	img;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true))) {
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	if (!(img = mlx_new_image(mlx, WIDTH, HEIGHT))) {
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	// if (mlx_image_to_window(mlx, img, 0, 0) == -1)
	// {
	// 	mlx_close_window(mlx);
	// 	puts(mlx_strerror(mlx_errno));
	// 	exit(EXIT_FAILURE);
	// }

	// mlx_loop_hook(mlx, ft_randomize, mlx);
	// mlx_loop_hook(mlx, ft_hook, mlx);
	return (Mlx(*mlx, *img));
}
