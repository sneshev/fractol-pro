#include "Julia.hpp"
#include "fract.hpp"

__m256i Julia::calcIterations8i(Vec8i xStart, Vec8i yStart) {
	static const Vec8i four(Fixed(4));
	Vec8i x(_cX), y(_cY);

	__m256i iterationCount = _mm256_set1_epi32(0);
	__m256i aliveMask = _mm256_set1_epi32(-1);
	for (unsigned int count = 0; count < _maxIterations; count++) {
		Vec8i x2=x*x, y2=y*y;

		y = (x*y).shiftLeft(1) + yStart;
		x = x2 - y2 + xStart;

		__m256i notEscaped = _mm256_cmpgt_epi32(four.v, (x2 + y2).v);
		aliveMask = _mm256_and_si256(aliveMask, notEscaped);
		if (!_mm256_movemask_epi8(aliveMask))
			break;

		iterationCount = _mm256_sub_epi32(iterationCount, aliveMask);
	}
	return (iterationCount);
}

void Julia::put8Pixels(__m256i iterations, unsigned int pixelIndex) {
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
void Julia::drawRow8i(int yStart, int yEnd) {
	Fixed xStep = (_xMax - _xMin) / width;
	Fixed yStep = (_yMax - _yMin) / height;
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
		int rowOffset = y * width;
		for (int x = 0; x < width; x += 8) {
			__m256i iterations = calcIterations8i(cX, cY);
			unsigned int pixelIndex = rowOffset + x;
			put8Pixels(iterations, pixelIndex);
			cX = cX + increment;
		}
	}
}
