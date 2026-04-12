#include "Mandelbrot.hpp"
#include "fract.hpp"

Mandelbrot::Mandelbrot(Mlx &inMlx, t_input &input) 
	: Fractal(inMlx, input) {}

Mandelbrot::~Mandelbrot() {}

void Mandelbrot::draw() {
	int threadAmount = thread::hardware_concurrency();
	if (!threadAmount) { threadAmount = 8; }

	std::vector<thread> threads;
	int rowsPerThread = height / threadAmount;


	for (int i = 0; i < threadAmount; i++) {
		int yStart = i * rowsPerThread;
		int yEnd = (i == threadAmount - 1) ? height : yStart + rowsPerThread;
		if (_precise == false)
			threads.emplace_back(&Mandelbrot::drawRow8i, this, yStart, yEnd);
		else
			threads.emplace_back(&Mandelbrot::drawRow4L, this, yStart, yEnd);
	}
	for (thread &t: threads) {
		t.join();
	}
}