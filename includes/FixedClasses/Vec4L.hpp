#pragma once
#include "Fixed.hpp"
#include <immintrin.h>
#include <macros.hpp>

class Vec4L {
    private:
        static constexpr int _fractionalBitAmount = FIXED_LONG_FRACTIONAL_BITS;

    public:
        __m256i v;

        Vec4L() = default;

        Vec4L(__m256i val)
            : v(val) {}

        Vec4L(int64_t i)
            : Vec4L(set1(i)) {}

        Vec4L(Fixed f)
            : Vec4L(set1((int64_t)f.getRawBits())) {}

        Vec4L(Fixed f0, Fixed f1, Fixed f2, Fixed f3)
            : Vec4L(setr(
                (int64_t)f0.getRawBits(),
                (int64_t)f1.getRawBits(),
                (int64_t)f2.getRawBits(),
                (int64_t)f3.getRawBits())
            ) {}


        static inline Vec4L set1(int64_t value) {
            return Vec4L(_mm256_set1_epi64x(value));
        }

        static inline Vec4L setr(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
            return Vec4L(_mm256_setr_epi64x(a0, a1, a2, a3));
        }

        inline Vec4L operator+(const Vec4L& other) const {
            return Vec4L(_mm256_add_epi64(v, other.v));
        }

        inline Vec4L operator-(const Vec4L& other) const {
            return Vec4L(_mm256_sub_epi64(v, other.v));
        }

        inline Vec4L operator*(const Vec4L& other) const {
            // No native 64x64->64 multiply in AVX2, must emulate:
            // a * b = (aHi * bLo + aLo * bHi) << 32 + aLo * bLo
            __m256i aLo = _mm256_and_si256(v,       _mm256_set1_epi64x(0xFFFFFFFF));
            __m256i bLo = _mm256_and_si256(other.v, _mm256_set1_epi64x(0xFFFFFFFF));
            __m256i aHi = _mm256_srli_epi64(v,       32);
            __m256i bHi = _mm256_srli_epi64(other.v, 32);

            __m256i loLo = _mm256_mul_epu32(aLo, bLo);
            __m256i hiLo = _mm256_mul_epu32(aHi, bLo);
            __m256i loHi = _mm256_mul_epu32(aLo, bHi);

            __m256i cross = _mm256_add_epi64(hiLo, loHi);
            cross = _mm256_slli_epi64(cross, 32);

            __m256i prod = _mm256_add_epi64(loLo, cross);
            return Vec4L(_mm256_srli_epi64(prod, _fractionalBitAmount));
        }

        inline Vec4L shiftRight(int bits) const {
            // Note: no _mm256_srai_epi64 until AVX-512, this is unsigned shift
            return Vec4L(_mm256_srli_epi64(v, bits));
        }

        inline Vec4L shiftLeft(int bits) const {
            return Vec4L(_mm256_slli_epi64(v, bits));
        }
};