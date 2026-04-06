#include "fract.hpp"


// int main(int argc, char *argv[]) {
// 	t_input input;
// 	if (!isValidInput(argc, argv, input)) { return (1); }

// 	Mlx mlx = initializeMlx();
// 	Mandelbrot fract(mlx, input);

// 	fract.info();
// 	fract.draw();

// 	fract.mlxLoop();
// 	fract.mlxTerminate(); //dunno if i have to destroy image
// 	return (EXIT_SUCCESS);
// }

int main() {
	Fixed a(12.3f);
	cout << a << " + " << 2 << " = " << a+2 << endl;
	cout << a << " - " << 2 << " = " << a-2 << endl;
	cout << a << " * " << 2 << " = " << a*2 << endl;
	cout << a << " / " << 2 << " = " << a/2 << endl;
}