#include "Fixed24_10.hpp"

const int Fixed24_10::_fractionalBitAmount = 16;


		/*		CONSTRUCTORS AND DESTRUCTORS	*/
Fixed24_10::Fixed24_10() : _value(0) {
	// std::cout << GREEN << "Fixed24_10 Default constructor called" << RESET << std::endl;
}

Fixed24_10::Fixed24_10(const Fixed24_10& other) {
	// std::cout << BLUE << "Fixed24_10 Copy constructor called" << RESET << std::endl;

	_value = other.getRawBits();
}

Fixed24_10::Fixed24_10(int const i) {
	// std::cout << GREEN << "Fixed24_10 Int constructor called" << RESET << std::endl;
	_value = i << _fractionalBitAmount;
}


Fixed24_10::Fixed24_10(float const fl) {
	// std::cout << GREEN << "Fixed24_10 Float constructor called" << RESET << std::endl;
	_value = roundf(fl * (1 << _fractionalBitAmount));
}

Fixed24_10::~Fixed24_10() {
	// std::cout << RED << "Fixed24_10 Destructor called" << RESET << std::endl;
}

		/*		OPERATORS			*/
Fixed24_10& Fixed24_10::operator=(const Fixed24_10& other) {
	// std::cout << BLUE << "Fixed24_10 Copy assignment operator called" << RESET << std::endl;
	if (this != &other)
		_value = other.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream &stream, const Fixed24_10& fixed) {
	stream << fixed.toFloat();
	return (stream);
}

bool Fixed24_10::operator <	(const Fixed24_10 &other) const	{ return _value < other.getRawBits(); }
bool Fixed24_10::operator >	(const Fixed24_10 &other) const	{ return _value > other.getRawBits(); }
bool Fixed24_10::operator <=	(const Fixed24_10 &other) const	{ return _value <= other.getRawBits(); }
bool Fixed24_10::operator >=	(const Fixed24_10 &other) const	{ return _value >= other.getRawBits(); }
bool Fixed24_10::operator ==	(const Fixed24_10 &other) const	{ return _value == other.getRawBits(); }
bool Fixed24_10::operator !=	(const Fixed24_10 &other) const	{ return _value != other.getRawBits(); }

Fixed24_10 Fixed24_10::operator +	(const Fixed24_10 &other) const {
	Fixed24_10 f;
	long rawtotal = (long)_value + other.getRawBits();
	f.setRawBits(rawtotal);
	return (f);
}

Fixed24_10 Fixed24_10::operator -	(const Fixed24_10 &other) const {
	Fixed24_10 f;
	long rawtotal = (long)_value - other.getRawBits();
	f.setRawBits(rawtotal);
	return (f);
}

Fixed24_10 Fixed24_10::operator *	(const Fixed24_10 &other) const {
	Fixed24_10 f;
	long rawtotal = (long)_value * other.getRawBits();
	f.setRawBits(rawtotal >> _fractionalBitAmount);
	return (f);
}

Fixed24_10 Fixed24_10::operator /	(const Fixed24_10 &other) const {
	Fixed24_10 f;
	if (other.getRawBits() == 0)
		throw (std::runtime_error("Division by zero"));
	long rawtotal = ((long)_value << _fractionalBitAmount) / other.getRawBits();
	f.setRawBits(rawtotal);
	return (f);
}

Fixed24_10 Fixed24_10::operator +	(const int i) const {
	Fixed24_10 f;
	long rawtotal = (long)_value + (i << _fractionalBitAmount);
	f.setRawBits(rawtotal);
	return (f);
}

Fixed24_10 Fixed24_10::operator -	(const int i) const {
	Fixed24_10 f;
	long rawtotal = (long)_value - (i << _fractionalBitAmount);
	f.setRawBits(rawtotal);
	return (f);
}

Fixed24_10 Fixed24_10::operator *	(const int i) const {
	Fixed24_10 f;
	long rawtotal = (long)_value * i;
	f.setRawBits(rawtotal);
	return (f);
}

Fixed24_10 Fixed24_10::operator /	(const int i) const {
	Fixed24_10 f;
	long rawtotal = (long)_value / i;
	f.setRawBits(rawtotal);
	return (f);
}


Fixed24_10 Fixed24_10::operator++	(int) {
	Fixed24_10	old = (*this);
	_value++;
	return (old);
}

Fixed24_10 Fixed24_10::operator-- (int) {
	Fixed24_10	old = (*this);
	_value--;
	return (old);
}

Fixed24_10& Fixed24_10::operator++ () {
	_value++;
	return (*this);
}

Fixed24_10& Fixed24_10::operator-- () {
	_value--;
	return (*this);
}

		/*		GETTER / SETTERS	*/
int Fixed24_10::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void Fixed24_10::setRawBits(int const raw) {
	_value = raw;
}

		/*		OTHER FUNCTIONS		*/
int Fixed24_10::toInt(void) const {
	return (_value >> _fractionalBitAmount);
}

float Fixed24_10::toFloat() const {
	return (((float)_value / (1 << _fractionalBitAmount)));
}


void Fixed24_10::halfValue() {
	_value = _value >> 1;
}

void Fixed24_10::doubleValue() {
	_value = _value << 1;
}

Fixed24_10 Fixed24_10::getHalvedValue() const {
	Fixed24_10 f;
	f.setRawBits(_value >> 1);
	return (f);
}

Fixed24_10 Fixed24_10::getDoubledValue() const {
	Fixed24_10 f;
	f.setRawBits(_value << 1);
	return (f);
}

bool Fixed24_10::isOutOfRadius(const int a, const int b) {
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