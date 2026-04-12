#include "Mandelbrot.hpp"
#include "fract.hpp"

__m256i Mandelbrot::calcIterations4L(Vec4L cX, Vec4L cY) {
    static const Vec4L four(FixedL(4));
    Vec4L x(0), y(0);

    __m256i iterationCount = _mm256_set1_epi64x(0);
    __m256i aliveMask = _mm256_set1_epi64x(-1);

    for (unsigned int count = 0; count < _maxIterations; count++) {
        Vec4L x2 = x*x, y2 = y*y;

        y = (x*y).shiftLeft(1) + cY;
        x = x2 - y2 + cX;

        __m256i notEscaped = _mm256_cmpgt_epi64(four.v, (x2 + y2).v);
        aliveMask = _mm256_and_si256(aliveMask, notEscaped);
        if (!_mm256_movemask_epi8(aliveMask))
            break;

        iterationCount = _mm256_sub_epi64(iterationCount, aliveMask);
    }
    return (iterationCount);
}

void Mandelbrot::put4Pixels(__m256i iterations, unsigned int pixelIndex) {
    alignas(32) int64_t iterArr[4];
    _mm256_store_si256((__m256i*)iterArr, iterations);

    for (int i = 0; i < 4; i++) {
        t_v4 color = getColors((int32_t)iterArr[i], _maxIterations);
        _pixels[pixelIndex + i] = *reinterpret_cast<int32_t*>(&color);
    }
}

void Mandelbrot::drawRow4L(int yStart, int yEnd) {
    FixedL xStep = (_xMaxL - _xMinL) / width;
    FixedL yStep = (_yMaxL - _yMinL) / height;
    Vec4L increment = Vec4L(xStep * 4);

    Vec4L cXStart(
        _xMinL,
        _xMinL + xStep * 1,
        _xMinL + xStep * 2,
        _xMinL + xStep * 3
    );

    for (int y = yStart; y < yEnd; y++) {
        Vec4L cY(_yMinL + yStep * y);
        Vec4L cX = cXStart;
        int rowOffset = y * width;
        for (int x = 0; x < width; x += 4) {
            __m256i iterations = calcIterations4L(cX, cY);
            put4Pixels(iterations, rowOffset + x);
            cX = cX + increment;
        }
    }
}
