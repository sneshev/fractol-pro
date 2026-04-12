#pragma once
#include "Fixed.hpp"
#include <immintrin.h>
#include <macros.hpp>

class Vec8i {
	private:
		static const int _fractionalBitAmount;

	public:
		__m256i v;

		Vec8i() = default;

		Vec8i(__m256i val)
			: v(val) {}

		Vec8i(Fixed f)
			: Vec8i(set1(f.getRawBits())) {}

		Vec8i(int32_t i)
			: Vec8i(set1(i)) {}


		Vec8i(Fixed f0, Fixed f1, Fixed f2, Fixed f3, Fixed f4, Fixed f5, Fixed f6, Fixed f7)
			: Vec8i(setr(
				f0.getRawBits(),
				f1.getRawBits(), 
				f2.getRawBits(), 
				f3.getRawBits(), 
				f4.getRawBits(), 
				f5.getRawBits(), 
				f6.getRawBits(), 
				f7.getRawBits()) 
			) {}



		inline Vec8i set1(int value) {
			return Vec8i(_mm256_set1_epi32(value));
		}

		inline Vec8i setr(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) {
			return Vec8i(_mm256_setr_epi32(a0, a1, a2, a3, a4, a5, a6, a7));
		}

		inline Vec8i operator+(const Vec8i& other) const {
			return Vec8i(_mm256_add_epi32(v, other.v));
		}

		inline Vec8i operator-(const Vec8i& other) const {
			return Vec8i(_mm256_sub_epi32(v, other.v));
		}

		inline Vec8i operator*(const Vec8i& other) const {
		    __m256i prodEven = _mm256_mul_epi32(v, other.v);
		    __m256i prodOdd  = _mm256_mul_epi32(_mm256_srli_epi64(v, 32), _mm256_srli_epi64(other.v, 32));
		
		    prodEven = _mm256_srli_epi64(prodEven, _fractionalBitAmount);
		    prodOdd  = _mm256_srli_epi64(prodOdd,  _fractionalBitAmount);
		
		    prodOdd = _mm256_slli_epi64(prodOdd, 32);
		
		    return Vec8i(_mm256_blend_epi32(prodEven, prodOdd, 0b10101010));
		}

		inline Vec8i shiftRight(int bits) const {
			return Vec8i(_mm256_srai_epi32(v, bits));
		}

		inline Vec8i shiftLeft(int bits) const {
			return Vec8i(_mm256_slli_epi32(v, bits));
		}
};
