#include "fract.hpp"
#include "Mlx.hpp"

Mlx::Mlx() {
	mlx_t* 			mlx;
	mlx_image_t*	img;

	if (!(mlx = mlx_init(width, height, "Fractal", true)))
	{
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	if (!(img = mlx_new_image(mlx, width, height)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, img, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}

	_mlx = mlx;
	_img = img;
}

Mlx::~Mlx() {
	mlx_terminate(_mlx);
}

void Mlx::loop() {
	mlx_loop(_mlx);
}

mlx_t* Mlx::getMlx() {
	return (_mlx);
}
mlx_image_t* Mlx::getImg() {
	return (_img);
}
