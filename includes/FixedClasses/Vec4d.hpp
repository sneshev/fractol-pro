#pragma once
// #include "FixedL.hpp"
#include <immintrin.h>
#include <macros.hpp>

class Vec4d {
    public:
        __m256d v;

        /* constructors */
        Vec4d() = default;

        Vec4d(__m256d val)
            : v(val) {}

        Vec4d(double d)
            : v(_mm256_set1_pd(d)) {}

        Vec4d(double d0, double d1, double d2, double d3)
            : Vec4d(_mm256_setr_pd( d0, d1, d2, d3)) {}

        Vec4d(float f)
            : v(_mm256_set1_pd(f)) {}

        Vec4d(float f0, float f1, float f2, float f3)
            : Vec4d(_mm256_setr_pd( f0, f1, f2, f3)) {}

        /* operators with Vec4d */

        inline Vec4d operator+(const Vec4d& other) const {
            return Vec4d(_mm256_add_pd(v, other.v));
        }

        inline Vec4d operator-(const Vec4d& other) const {
            return Vec4d(_mm256_sub_pd(v, other.v));
        }

        inline Vec4d operator*(const Vec4d& other) const {
            return Vec4d(_mm256_mul_pd(v, other.v));
        }

        inline Vec4d operator/(const Vec4d& other) const {
            return Vec4d(_mm256_div_pd(v, other.v));
        }

        /* operators with double */

        inline Vec4d operator+(double d) {
            return Vec4d(_mm256_add_pd(v, _mm256_set1_pd(d)));
        }
        inline Vec4d operator-(double d) {
            return Vec4d(_mm256_sub_pd(v, _mm256_set1_pd(d)));
        }
        inline Vec4d operator*(double d) {
            return Vec4d(_mm256_mul_pd(v, _mm256_set1_pd(d)));
        }
        inline Vec4d operator/(double d) {
            return Vec4d(_mm256_div_pd(v, _mm256_set1_pd(d)));
        }

        /* other */

        inline __m256d operator<(const Vec4d& other) const {
            return (_mm256_cmp_pd(v, other.v, _CMP_LT_OQ));
        }
        inline __m256d operator>(const Vec4d& other) const {
            return (_mm256_cmp_pd(v, other.v, _CMP_GT_OQ));
        }
};
