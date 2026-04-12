#include "Julia.hpp"
#include "fract.hpp"

Julia::Julia(Mlx &inMlx, t_input &input) 
	: Fractal(inMlx, input),
	_cX(input.args[0]),
	_cY(input.args[1]),
	_cX_d(input.args[0]),
	_cY_d(input.args[1]) {}

Julia::~Julia() {}

__m256i Julia::calcIterations8i(Vec8i xStart, Vec8i yStart) {
	static const Vec8i four(Fixed(4));
	Vec8i x(xStart), y(yStart);

	__m256i iterationCount = _mm256_set1_epi32(0);
	__m256i aliveMask = _mm256_set1_epi32(-1);
	for (unsigned int count = 0; count < _maxIterations; count++) {
		Vec8i x2=x*x, y2=y*y;

		y = (x*y).shiftLeft(1) + _cY;
		x = x2 - y2 + _cX;

		__m256i notEscaped = _mm256_cmpgt_epi32(four.v, (x2 + y2).v);
		aliveMask = _mm256_and_si256(aliveMask, notEscaped);
		if (!_mm256_movemask_epi8(aliveMask))
			break;

		iterationCount = _mm256_sub_epi32(iterationCount, aliveMask);
	}
	return (iterationCount);
}

__m256i Julia::calcIterations4d(Vec4d xStart, Vec4d yStart) {
	static const Vec4d four(4.0);
	Vec4d x(xStart), y(yStart);

	__m256i iterationCount = _mm256_set1_epi64x(0);
	__m256i aliveMask = _mm256_set1_epi64x(-1);

	for (unsigned int count = 0; count < _maxIterations; count++) {
		Vec4d x2 = x*x, y2 = y*y;

		y = x * y * 2.0 + _cY_d;
		x = x2 - y2 + _cX_d;

		__m256d notEscaped = (x2 + y2) < four;
		aliveMask = _mm256_and_si256(aliveMask, _mm256_castpd_si256(notEscaped));
		if (!_mm256_movemask_epi8(aliveMask))
			break;
		iterationCount = _mm256_sub_epi64(iterationCount, aliveMask);
	}
	return (iterationCount);
}
