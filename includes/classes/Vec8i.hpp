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
		Vec8i(__m256i val);
		Vec8i(Fixed f);
		Vec8i(Fixed f7, Fixed f6, Fixed f5, Fixed f4, Fixed f3, Fixed f2, Fixed f1, Fixed f0);
		Vec8i(int32_t i);
		Vec8i(int32_t a7, int32_t a6, int32_t a5, int32_t a4, int32_t a3, int32_t a2, int32_t a1, int32_t a0);

		static Vec8i set1(int value);
		static Vec8i set(int a7, int a6, int a5, int a4, int a3, int a2, int a1, int a0);

		Vec8i operator+(const Vec8i& other) const;
		Vec8i operator-(const Vec8i& other) const;
		Vec8i operator*(const Vec8i& other) const;

		Vec8i shiftRight(int bits) const;
		Vec8i shiftLeft(int bits) const;
};
