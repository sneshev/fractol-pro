#include "fract.hpp"

void Fractal::put4Pixels(__m256i iterations, unsigned int pixelIndex) {
    alignas(32) int64_t iterArr[4];
    _mm256_store_si256((__m256i*)iterArr, iterations);

    for (int i = 0; i < 4; i++) {
        t_v4 color = getColors((int32_t)iterArr[i], _maxIterations);
        _pixels[pixelIndex + i] = *reinterpret_cast<int32_t*>(&color);
    }
}

void Fractal::drawRow4d(int yStart, int yEnd) {
    double xStep = (_xMax_d - _xMin_d) / WIDTH;
    double yStep = (_yMax_d - _yMin_d) / HEIGHT;
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
        int rowOffset = y * WIDTH;
        for (int x = 0; x < WIDTH; x += 4) {
            __m256i iterations = calcIterations4d(cX, cY);
            put4Pixels(iterations, rowOffset + x);
            cX = cX + increment;
        }
    }
}
