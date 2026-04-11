#pragma once

#include "../MLX42/include/MLX42/MLX42.h"
#include "macros.hpp"
#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

#include <cmath>

class Fixed16_16 {
	private:
		int 				_value;
		static const int	_fractionalBitAmount;

	public:
		Fixed16_16();
		Fixed16_16(int const i);
		Fixed16_16(float const fl);
		Fixed16_16(const Fixed16_16& fx);
		~Fixed16_16();

		Fixed16_16& operator=(const Fixed16_16& other);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		bool	operator< (const Fixed16_16 &other) const;
		bool	operator> (const Fixed16_16 &other) const;
		bool	operator<=(const Fixed16_16 &other) const;
		bool	operator>=(const Fixed16_16 &other) const;
		bool	operator==(const Fixed16_16 &other) const;
		bool	operator!=(const Fixed16_16 &other) const;

		Fixed16_16	operator+(const Fixed16_16 &other) const;
		Fixed16_16	operator-(const Fixed16_16 &other) const;
		Fixed16_16	operator*(const Fixed16_16 &other) const;
		Fixed16_16	operator/(const Fixed16_16 &other) const;

		Fixed16_16	operator+(const int) const;
		Fixed16_16	operator-(const int) const;
		Fixed16_16	operator*(const int) const;
		Fixed16_16	operator/(const int) const;

		Fixed16_16	operator++(int);
		Fixed16_16&	operator++(void);
		Fixed16_16	operator--(int);
		Fixed16_16&	operator--(void);

		void	halfValue();
		void	doubleValue();
		Fixed16_16	getHalvedValue() const;
		Fixed16_16	getDoubledValue() const;

		static bool isOutOfRadius(const int a, const int b);
};

std::ostream& operator<<(std::ostream &stream, const Fixed16_16& fixed);
