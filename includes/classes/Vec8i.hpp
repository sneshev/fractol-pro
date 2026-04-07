#pragma once
#include <immintrin.h>
#include <macros.hpp>

class Vec8i {
	private:
		static const int _fractionalBitAmount;

	public:
	__m256i v;

	Vec8i() = default;
	Vec8i(__m256i val);
	
	static Vec8i set1(int value);
	static Vec8i set(int a7, int a6, int a5, int a4, int a3, int a2, int a1, int a0);
	
	Vec8i operator+(const Vec8i& other) const;
	Vec8i operator-(const Vec8i& other) const;
	Vec8i operator*(const Vec8i& other) const;
	
	Vec8i shiftRight(int bits) const;
	Vec8i shiftLeft(int bits) const;
};
