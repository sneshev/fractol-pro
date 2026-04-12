#include "Mandelbrot.hpp"
#include "fract.hpp"

Mandelbrot::Mandelbrot(Mlx &inMlx, t_input &input) 
	: Fractal(inMlx, input)
{
	std::cout << GREEN << "Mandelbrot constructor called" << RESET << std::endl;
}

Mandelbrot::~Mandelbrot() {
	std::cout << RED << "Mandelbrot Destructor called" << RESET << std::endl;
}

__m256i Mandelbrot::calcIterations(Vec8i cX1, Vec8i cX2, Vec8i cY, __m256i iterationCount[2]) {
	// static const __m256i one = _mm256_set1_epi32(1);
	static const Vec8i four(Fixed(4));

	Vec8i x1(0), x2(0), y1(0), y2(0);
	iterationCount[0] = _mm256_set1_epi32(0);
	iterationCount[1] = _mm256_set1_epi32(0);

	__m256i aliveMask1 = _mm256_set1_epi32(-1); // all pixels start alive
	__m256i aliveMask2 = _mm256_set1_epi32(-1); // all pixels start alive
for (unsigned int count = 0; count < _maxIterations; count++) {
    Vec8i xx1 = x1*x1, xx2 = x2*x2;
    Vec8i yy1 = y1*y1, yy2 = y2*y2;

    y1 = (x1*y1).shiftLeft(1) + cY;
    y2 = (x2*y2).shiftLeft(1) + cY;
    x1 = xx1 - yy1 + cX1;
    x2 = xx2 - yy2 + cX2;

    aliveMask1 = _mm256_and_si256(aliveMask1, _mm256_cmpgt_epi32(four.v, (xx1 + yy1).v));
    aliveMask2 = _mm256_and_si256(aliveMask2, _mm256_cmpgt_epi32(four.v, (xx2 + yy2).v));

    iterationCount[0] = _mm256_sub_epi32(iterationCount[0], aliveMask1);
    iterationCount[1] = _mm256_sub_epi32(iterationCount[1], aliveMask2);

    if (!_mm256_movemask_epi8(_mm256_or_si256(aliveMask1, aliveMask2)))
        break;
}
	return (iterationCount[0]);
}

void Mandelbrot::put8Pixels(__m256i iterations, unsigned int pixelIndex) {
    alignas(32) int32_t iterArr[8];
    _mm256_store_si256((__m256i*)iterArr, iterations);

    for (int i = 0; i < 8; i++) {
        t_v4 color = getColors(iterArr[i], _maxIterations);
        _pixels[pixelIndex + i] = color;
    }
}

void Mandelbrot::drawRow(int yStart, int yEnd) {
	Fixed xStep = (_xMax - _xMin) / width;
	Fixed yStep = (_yMax - _yMin) / height;
	Vec8i increment = Vec8i(xStep * 16);

	for (int y = yStart; y < yEnd; y++) {
		Vec8i cY(_yMin + yStep * y);
		int rowOffset = y * width;
		Vec8i cX1(
			_xMin + xStep * 0,
			_xMin + xStep * 1,
			_xMin + xStep * 2,
			_xMin + xStep * 3,
			_xMin + xStep * 4,
			_xMin + xStep * 5,
			_xMin + xStep * 6,
			_xMin + xStep * 7
		);
		Vec8i cX2(
			_xMin + xStep * 8,
			_xMin + xStep * 9,
			_xMin + xStep * 10,
			_xMin + xStep * 11,
			_xMin + xStep * 12,
			_xMin + xStep * 13,
			_xMin + xStep * 14,
			_xMin + xStep * 15
		);
		for (int x = 0; x < width; x += 16) {
			__m256i iterations[2];
			calcIterations(cX1, cX2, cY, iterations);
			unsigned int pixelIndex = rowOffset + x;
			put8Pixels(iterations[0], pixelIndex);
			put8Pixels(iterations[1], pixelIndex + 8);
			cX1 = cX1 + increment;
			cX2 = cX2 + increment;
		}
	}
}

void Mandelbrot::draw() {
	int threadAmount = thread::hardware_concurrency();
	if (!threadAmount) { threadAmount = 8; }

	std::vector<thread> threads;
	int rowsPerThread = height / threadAmount;

	for (int i = 0; i < threadAmount; i++) {
		int yStart = i * rowsPerThread;
		int yEnd = (i == threadAmount - 1) ? height : yStart + rowsPerThread;
		threads.emplace_back(&Mandelbrot::drawRow, this, yStart, yEnd);
	}
	for (thread &t: threads) {
		t.join();
	}
}