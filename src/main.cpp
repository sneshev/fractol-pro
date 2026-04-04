#include "fract.hpp"


int main(int argc, char *argv[]) {
	t_input input;
	if (!isValidInput(argc, argv, input)) {
		cout << "bad input" << endl;
		return (1);
	}

	Mlx mlx = initializeMlx();
	Fractal fract(mlx, input);


	fract.info();
	//...
	//...



	fract.mlxLoop();
	fract.mlxTerminate(); //dunno if i have to destroy image
	return (EXIT_SUCCESS);
}