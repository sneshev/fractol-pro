#include "fract.hpp"

// void Mandelbrot::put8Pixels(__m256i iterations, unsigned int pixelIndex) {
    // __m256i colors = get8Colors(iterations, _maxIterations);
    // _mm256_storeu_si256((__m256i*)(&_pixels[pixelIndex]), colors);
// }

/* dont actually need to cast to array at all eventually */
void Fractal::put8Pixels(__m256i iterations, unsigned int pixelIndex) {
    alignas(32) int32_t iterArr[8];
    _mm256_store_si256((__m256i*)iterArr, iterations);

    alignas(32) int32_t colorArr[8];

    for (int i = 0; i < 8; i++) {
        t_v4 color = getColors(iterArr[i], _maxIterations);
        colorArr[i] = *reinterpret_cast<int32_t*>(&color);
    }

    _mm256_storeu_si256(
		(__m256i*)(&_pixels[pixelIndex]),
		_mm256_load_si256((__m256i*)colorArr)
	);
}
void Fractal::drawRow8i(int yStart, int yEnd) {
	Fixed xStep = (_xMax - _xMin) / WIDTH;
	Fixed yStep = (_yMax - _yMin) / HEIGHT;
	Vec8i increment = Vec8i(xStep * 8);

	Vec8i cXStart(
		_xMin,
		_xMin + xStep * 1,
		_xMin + xStep * 2,
		_xMin + xStep * 3,
		_xMin + xStep * 4,
		_xMin + xStep * 5,
		_xMin + xStep * 6,
		_xMin + xStep * 7
	);
	for (int y = yStart; y < yEnd; y++) {
		Vec8i cY(_yMin + yStep * y);
		Vec8i cX = cXStart;
		int rowOffset = y * WIDTH;
		for (int x = 0; x < WIDTH; x += 8) {
			__m256i iterations = calcIterations8i(cX, cY);
			unsigned int pixelIndex = rowOffset + x;
			put8Pixels(iterations, pixelIndex);
			cX = cX + increment;
		}
	}
}