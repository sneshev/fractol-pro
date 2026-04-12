#include "fract.hpp"

void Fractal::draw() {
	int threadAmount = thread::hardware_concurrency();
	if (!threadAmount) { threadAmount = 8; }

	std::vector<thread> threads;
	int rowsPerThread = HEIGHT / threadAmount;

	for (int i = 0; i < threadAmount; i++) {
		int yStart = i * rowsPerThread;
		int yEnd = (i == threadAmount - 1) ? HEIGHT : yStart + rowsPerThread;
		if (_precise == false)
			threads.emplace_back(&Fractal::drawRow8i, this, yStart, yEnd);
		else
			threads.emplace_back(&Fractal::drawRow4d, this, yStart, yEnd);
	}
	for (thread &t: threads) {
		t.join();
	}
}