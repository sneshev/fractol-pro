#ifndef MLX_HPP
#define MLX_HPP

#include "../MLX42/include/MLX42/MLX42.h"

class Mlx {
	private:
		mlx_t*			_mlx;
		mlx_image_t*	_img;

	public:
		Mlx();
		~Mlx();

		void loop();

		mlx_t*			getMlx();
		mlx_image_t*	getImg();
};


#endif