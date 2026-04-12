#include "Mandelbrot.hpp"
#include "fract.hpp"

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

void Mandelbrot::put4Pixels(__m256i iterations, unsigned int pixelIndex) {
    alignas(32) int64_t iterArr[4];
    _mm256_store_si256((__m256i*)iterArr, iterations);

    for (int i = 0; i < 4; i++) {
        t_v4 color = getColors((int32_t)iterArr[i], _maxIterations);
        _pixels[pixelIndex + i] = *reinterpret_cast<int32_t*>(&color);
    }
}

void Mandelbrot::drawRow4d(int yStart, int yEnd) {
    double xStep = (_xMax_d - _xMin_d) / width;
    double yStep = (_yMax_d - _yMin_d) / height;
    Vec4d increment(xStep * 4);

    Vec4d cXStart(
        _xMin_d,
        _xMin_d + xStep * 1,
        _xMin_d + xStep * 2,
        _xMin_d + xStep * 3
    );

    for (int y = yStart; y < yEnd; y++) {
        Vec4d cY(_yMin_d + yStep * y);
        Vec4d cX = cXStart;
        int rowOffset = y * width;
        for (int x = 0; x < width; x += 4) {
            __m256i iterations = calcIterations4d(cX, cY);
            put4Pixels(iterations, rowOffset + x);
            cX = cX + increment;
        }
    }
}
