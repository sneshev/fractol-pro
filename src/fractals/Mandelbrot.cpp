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

__m256i Mandelbrot::calcIterations(Vec8i cX, Vec8i cY) {
	static const Vec8i four(Fixed(4));
	Vec8i x(0); Vec8i y(0);

	__m256i iterationCount = _mm256_set1_epi32(0);
	__m256i aliveMask = _mm256_set1_epi32(-1); // all pixels start alive
	for (unsigned int count = 0; count < _maxIterations; count++) {
		Vec8i x2=x*x, y2=y*y;

		y = (x*y).shiftLeft(1) + cY;
		x = x2 - y2 + cX;

		__m256i notEscaped = _mm256_cmpgt_epi32(four.v, (x2 + y2).v);
		aliveMask = _mm256_and_si256(aliveMask, notEscaped);
		if (!_mm256_movemask_epi8(aliveMask))
			break;

		iterationCount = _mm256_sub_epi32(iterationCount, aliveMask);
	}
	return (iterationCount);
}

/* dont actually need to cast to array at all eventually */
void Mandelbrot::put8Pixels(__m256i iterations, unsigned int pixelIndex) {
    alignas(32) int32_t iterArr[8];
    _mm256_store_si256((__m256i*)iterArr, iterations);

    alignas(32) int32_t colorArr[8];

    for (int i = 0; i < 8; i++) {
        t_v4 color = getColors(iterArr[i], _maxIterations);
        // Reinterpret the 4-byte RGBA struct as a single int32_t
        colorArr[i] = *reinterpret_cast<int32_t*>(&color);
    }

    _mm256_storeu_si256(
		(__m256i*)(&_pixels[pixelIndex]),
		_mm256_load_si256((__m256i*)colorArr)
	);
}
void Mandelbrot::drawRow(int yStart, int yEnd) {
	Fixed xStep = (_xMax - _xMin) / width;
	Fixed yStep = (_yMax - _yMin) / height;
	Vec8i increment = Vec8i(xStep * 8);

	for (int y = yStart; y < yEnd; y++) {
		Vec8i cY(_yMin + yStep * y);
		int rowOffset = y * width;
		Vec8i cX(
			_xMin + xStep * 0,
			_xMin + xStep * 1,
			_xMin + xStep * 2,
			_xMin + xStep * 3,
			_xMin + xStep * 4,
			_xMin + xStep * 5,
			_xMin + xStep * 6,
			_xMin + xStep * 7
		);
		for (int x = 0; x < width; x += 8) {
			__m256i iterations = calcIterations(cX, cY);
			unsigned int pixelIndex = rowOffset + x;
			put8Pixels(iterations, pixelIndex);
			cX = cX + increment;
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