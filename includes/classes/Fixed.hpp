#ifndef FIXED_HPP
#define FIXED_HPP

#include "../MLX42/include/MLX42/MLX42.h"

#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

#include <cmath>

class Fixed {
	private:
		int 				_value;
		static const int	_fractionalBitAmount;

	public:
		Fixed();
		Fixed(int const i);
		Fixed(float const fl);
		Fixed(const Fixed& fx);
		~Fixed();

		Fixed& operator=(const Fixed& other);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		bool	operator< (const Fixed &other) const;
		bool	operator> (const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator!=(const Fixed &other) const;

		Fixed	operator+(const Fixed &other) const;
		Fixed	operator-(const Fixed &other) const;
		Fixed	operator*(const Fixed &other) const;
		Fixed	operator/(const Fixed &other) const;

		Fixed	operator+(const int) const;
		Fixed	operator-(const int) const;
		Fixed	operator*(const int) const;
		Fixed	operator/(const int) const;

		Fixed	operator++(int);
		Fixed&	operator++(void);
		Fixed	operator--(int);
		Fixed&	operator--(void);

		void halfValue();
		void doubleValue();
};

std::ostream& operator<<(std::ostream &stream, const Fixed& fixed);

#endif