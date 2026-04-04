#include "fract.hpp"


int main(int argc, char *argv[]) {
	t_input input;
	if (!isValidInput(argc, argv, input)) {
		cout << "bad input" << endl;
	} else { cout << "good input" << endl; }
	Mlx mlx = initializeMlx();
	Fractal fract(mlx, input);

	//...
	//...



	fract.mlxLoop();
	fract.mlxTerminate(); //dunno if i have to destroy image
	return (EXIT_SUCCESS);
}