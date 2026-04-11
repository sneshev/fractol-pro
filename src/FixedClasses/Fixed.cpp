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

bool Fixed::isOutOfRadius(const int a, const int b) {
	return (((a + b) >> (_fractionalBitAmount + 1)) < 1) ? false : true; 
	return (((a + b) >> (_fractionalBitAmount + 1)) > 0) ? true : false; 
}

/*


	THIS BENEATH IS ALL TOTALLY WRONG SMH...
	THE WHOLE REASON TO SQUARE IS TO GET RID OF NEGATIVE NUMBERS.
	WHAT a << 1 DOES IS MULTIPLY BY 2, NOT SQUARE... SO EVERYTHING 
	FROM THE VERY FIRST EQUASION IS WRONG.....
	but I do wonder, why does it work? because its still the mandelbrot 
	set if i do this *wrong* calculation. Why? CAN IT be optimized?








	Im confident it can be optimized but its complicated.

	A big problem are negative numbers. That's precisely the reason
	that x and y were being squared to begin with. But i dont think
	they actually need to be squared, bitwise will probably do the
	trick. 

	on this line:
		return ((((a << 1) + (b << 1)) >> (_fractionalBitAmount)) < 4) ? false : true;
	we can see the original a*a+b*b<4 condition:
		a << 1 is a squared, therefore a << 1 == a*a
	then we shift the value to the right by >> _fractionalBitAmount
	because we want to get the actual number rather than rawbits.
	then we see if its < 4 like in the original equasion

	on this line:
		return ((((a << 1) + (b << 1)) >> (_fractionalBitAmount + 2)) < 1) ? false : true;
	its the same equasion but instead of doing value <? 4 we shift both value
	and 4 to the left by 2 bits. 4 << 2 is 1, that is why i equate it to 1.
	and i also put the value << 2 at the same time that i shift the fractional bits
	so its the same equasion only everything is shifted to the right by 2 (>> 2)

	the last line:
		return (((a + b) >> (_fractionalBitAmount + 1)) < 1) ? false : true; 
	is the same equasion only i dont do the unnecessary first shift to the left
	for a and b, and therefore i also shift the right side once less. there is no
	reason to shift the left side (to square the values) when using the rawbits.

	so actually ive already gotten rid of the squaring. But i hope i can optimize it more 
	using bitwise operators because this is the MAIN calculation of the project and it 
	is called countless times. Therefore the slightest optimization will yield massive returns!

*/