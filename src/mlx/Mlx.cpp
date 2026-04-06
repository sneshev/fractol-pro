#include "Mlx.hpp"

Mlx::Mlx(mlx_t &inMlx, mlx_image_t &inImg) 
	: _mlx(inMlx), _img(inImg)
{

}

Mlx::~Mlx() {
	mlx_terminate(&_mlx);
}

void Mlx::loop() {
	mlx_loop(&_mlx);
}

mlx_t* Mlx::getMlx() {
	return (&_mlx);
}
mlx_image_t* Mlx::getImg() {
	return (&_img);
}