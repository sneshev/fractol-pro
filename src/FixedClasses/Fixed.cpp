#include "Fixed.hpp"

const int Fixed::_fractionalBitAmount = FIXED_FRACTIONAL_BITS;


		/*		CONSTRUCTORS AND DESTRUCTORS	*/
Fixed::Fixed()
	: _value(0)
{

}

Fixed::Fixed(const Fixed& other) 
	: _value(other.getRawBits())
{

}

Fixed::Fixed(int const i)
	: _value(i << _fractionalBitAmount)
{
}

Fixed::Fixed(int const inRawBits, int inFractionalBitAmount)
{
	int diff = inFractionalBitAmount - FIXED_FRACTIONAL_BITS;

	if (diff > 0) /* in > FIXED_FRACTIONAL_BITS */
	{
		bool negative = inRawBits < 0;
		unsigned int abs = negative ? -inRawBits : inRawBits;
		_value = negative ? -(int)(abs >> diff) : (int)(abs >> diff);
	}
	else
	{
		_value = inRawBits << -diff;
	}
}


Fixed::Fixed(float const fl) {
	// std::cout << GREEN << "Fixed Float constructor called" << RESET << std::endl;
	_value = roundf(fl * (1 << _fractionalBitAmount));
}

Fixed::~Fixed() {
	// std::cout << RED << "Fixed Destructor called" << RESET << std::endl;
}

		/*		OPERATORS			*/
Fixed& Fixed::operator=(const Fixed& other) {
	// std::cout << BLUE << "Fixed Copy assignment operator called" << RESET << std::endl;
	if (this != &other)
		_value = other.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream &stream, const Fixed& fixed) {
	stream << fixed.toFloat();
	return (stream);
}

bool Fixed::operator <	(const Fixed &other) const	{ return _value < other.getRawBits(); }
bool Fixed::operator >	(const Fixed &other) const	{ return _value > other.getRawBits(); }
bool Fixed::operator <=	(const Fixed &other) const	{ return _value <= other.getRawBits(); }
bool Fixed::operator >=	(const Fixed &other) const	{ return _value >= other.getRawBits(); }
bool Fixed::operator ==	(const Fixed &other) const	{ return _value == other.getRawBits(); }
bool Fixed::operator !=	(const Fixed &other) const	{ return _value != other.getRawBits(); }

Fixed Fixed::operator +	(const Fixed &other) const {
	Fixed f;
	long rawtotal = (long)_value + other.getRawBits();
	f.setRawBits(rawtotal);
	return (f);
}

Fixed Fixed::operator -	(const Fixed &other) const {
	Fixed f;
	long rawtotal = (long)_value - other.getRawBits();
	f.setRawBits(rawtotal);
	return (f);
}

Fixed Fixed::operator *	(const Fixed &other) const {
	Fixed f;
	long rawtotal = (long)_value * other.getRawBits();
	f.setRawBits(rawtotal >> _fractionalBitAmount);
	return (f);
}

Fixed Fixed::operator /	(const Fixed &other) const {
	Fixed f;
	if (other.getRawBits() == 0)
		throw (std::runtime_error("Division by zero"));
	long rawtotal = ((long)_value << _fractionalBitAmount) / other.getRawBits();
	f.setRawBits(rawtotal);
	return (f);
}

Fixed Fixed::operator +	(const int i) const {
	Fixed f;
	long rawtotal = (long)_value + (i << _fractionalBitAmount);
	f.setRawBits(rawtotal);
	return (f);
}

Fixed Fixed::operator -	(const int i) const {
	Fixed f;
	long rawtotal = (long)_value - (i << _fractionalBitAmount);
	f.setRawBits(rawtotal);
	return (f);
}

Fixed Fixed::operator *	(const int i) const {
	Fixed f;
	long rawtotal = (long)_value * i;
	f.setRawBits(rawtotal);
	return (f);
}

Fixed Fixed::operator /	(const int i) const {
	Fixed f;
	long rawtotal = (long)_value / i;
	f.setRawBits(rawtotal);
	return (f);
}


Fixed Fixed::operator++	(int) {
	Fixed	old = (*this);
	_value++;
	return (old);
}

Fixed Fixed::operator-- (int) {
	Fixed	old = (*this);
	_value--;
	return (old);
}

Fixed& Fixed::operator++ () {
	_value++;
	return (*this);
}

Fixed& Fixed::operator-- () {
	_value--;
	return (*this);
}

		/*		GETTER / SETTERS	*/
int Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void Fixed::setRawBits(int const raw) {
	_value = raw;
}

		/*		OTHER FUNCTIONS		*/
int Fixed::toInt(void) const {
	return (_value >> _fractionalBitAmount);
}

float Fixed::toFloat() const {
	return (((float)_value / (1 << _fractionalBitAmount)));
}


void Fixed::halfValue() {
	_value = _value >> 1;
}

void Fixed::doubleValue() {
	_value = _value << 1;
}

Fixed Fixed::getHalvedValue() const {
	Fixed f;
	f.setRawBits(_value >> 1);
	return (f);
}

Fixed Fixed::getDoubledValue() const {
	Fixed f;
	f.setRawBits(_value << 1);
	return (f);
}
