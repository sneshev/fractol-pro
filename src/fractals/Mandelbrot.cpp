#include "fract.hpp"

__m256i Mandelbrot::calcIterations8i(Vec8i cX, Vec8i cY) {
	static const Vec8i four(Fixed(4));
	Vec8i x(0), y(0);

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

__m256i Mandelbrot::calcIterations4d(Vec4d cX, Vec4d cY) {
	static const Vec4d four(4.0);
	Vec4d x(0.0), y(0.0);

	__m256i iterationCount = _mm256_set1_epi64x(0);
	__m256i aliveMask = _mm256_set1_epi64x(-1);

	for (unsigned int count = 0; count < _maxIterations; count++) {
		Vec4d x2 = x*x, y2 = y*y;

		y = x * y * 2.0 + cY;
		x = x2 - y2 + cX;

		__m256d notEscaped = (x2 + y2) < four;
		aliveMask = _mm256_and_si256(aliveMask, _mm256_castpd_si256(notEscaped));
		if (!_mm256_movemask_epi8(aliveMask))
			break;
		iterationCount = _mm256_sub_epi64(iterationCount, aliveMask);
	}
	return (iterationCount);
}
