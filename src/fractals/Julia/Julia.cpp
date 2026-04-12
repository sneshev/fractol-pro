#include "Julia.hpp"
#include "fract.hpp"

Julia::Julia(Mlx &inMlx, t_input &input) 
	: Fractal(inMlx, input),
	_cX(input.args[0]),
	_cY(input.args[1]),
	_cX_d(input.args[0]),
	_cY_d(input.args[1])
{

}

Julia::~Julia() {}

void Julia::draw() {
	int threadAmount = thread::hardware_concurrency();
	if (!threadAmount) { threadAmount = 8; }

	std::vector<thread> threads;
	int rowsPerThread = height / threadAmount;


	for (int i = 0; i < threadAmount; i++) {
		int yStart = i * rowsPerThread;
		int yEnd = (i == threadAmount - 1) ? height : yStart + rowsPerThread;
		if (_precise == false)
			threads.emplace_back(&Julia::drawRow8i, this, yStart, yEnd);
		else
			threads.emplace_back(&Julia::drawRow4d, this, yStart, yEnd);
	}
	for (thread &t: threads) {
		t.join();
	}
}
