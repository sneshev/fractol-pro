#include "Vec8i.hpp"

const int Vec8i::_fractionalBitAmount = FIXED_FRACTIONAL_BITS;

Vec8i::Vec8i(__m256i val) : v(val) {}

Vec8i Vec8i::set1(int value) {
	return Vec8i(_mm256_set1_epi32(value));
}

Vec8i Vec8i::set(int a7, int a6, int a5, int a4, int a3, int a2, int a1, int a0) {
	return Vec8i(_mm256_setr_epi32(a0, a1, a2, a3, a4, a5, a6, a7));
}

Vec8i Vec8i::operator+(const Vec8i& other) const {
	return Vec8i(_mm256_add_epi32(v, other.v));
}

Vec8i Vec8i::operator-(const Vec8i& other) const {
	return Vec8i(_mm256_sub_epi32(v, other.v));
}

Vec8i Vec8i::operator*(const Vec8i& other) const {
	//...
}

Vec8i Vec8i::shiftRight(int bits) const {
	return Vec8i(_mm256_srai_epi32(v, bits));
}

Vec8i Vec8i::shiftLeft(int bits) const {
	return Vec8i(_mm256_slli_epi32(v, bits));
}