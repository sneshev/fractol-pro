#pragma once

#include "../MLX42/include/MLX42/MLX42.h"
#include "macros.hpp"
#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

#include <cmath>

class Fixed24_10 {
	private:
		int 				_value;
		static const int	_fractionalBitAmount;

	public:
		Fixed24_10();
		Fixed24_10(int const i);
		Fixed24_10(float const fl);
		Fixed24_10(const Fixed24_10& fx);
		~Fixed24_10();

		Fixed24_10& operator=(const Fixed24_10& other);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		bool	operator< (const Fixed24_10 &other) const;
		bool	operator> (const Fixed24_10 &other) const;
		bool	operator<=(const Fixed24_10 &other) const;
		bool	operator>=(const Fixed24_10 &other) const;
		bool	operator==(const Fixed24_10 &other) const;
		bool	operator!=(const Fixed24_10 &other) const;

		Fixed24_10	operator+(const Fixed24_10 &other) const;
		Fixed24_10	operator-(const Fixed24_10 &other) const;
		Fixed24_10	operator*(const Fixed24_10 &other) const;
		Fixed24_10	operator/(const Fixed24_10 &other) const;

		Fixed24_10	operator+(const int) const;
		Fixed24_10	operator-(const int) const;
		Fixed24_10	operator*(const int) const;
		Fixed24_10	operator/(const int) const;

		Fixed24_10	operator++(int);
		Fixed24_10&	operator++(void);
		Fixed24_10	operator--(int);
		Fixed24_10&	operator--(void);

		void	halfValue();
		void	doubleValue();
		Fixed24_10	getHalvedValue() const;
		Fixed24_10	getDoubledValue() const;

		static bool isOutOfRadius(const int a, const int b);
};

std::ostream& operator<<(std::ostream &stream, const Fixed24_10& fixed);
