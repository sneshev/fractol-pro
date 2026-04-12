#include "FixedL.hpp"

        /*      CONSTRUCTORS AND DESTRUCTORS    */
FixedL::FixedL()
    : _value(0)
{
}

FixedL::FixedL(const FixedL& other)
    : _value(other.getRawBits())
{
}

FixedL::FixedL(int const i)
    : _value((int64_t)i << _fractionalBitAmount)
{
}

FixedL::FixedL(int64_t const inRawBits, int inFractionalBitAmount)
{
    int diff = inFractionalBitAmount - FIXED_LONG_FRACTIONAL_BITS;

    if (diff > 0)
    {
        bool negative = inRawBits < 0;
        uint64_t abs = negative ? -inRawBits : inRawBits;
        _value = negative ? -(int64_t)(abs >> diff) : (int64_t)(abs >> diff);
    }
    else
    {
        _value = inRawBits << -diff;
    }
}

FixedL::FixedL(double const d)
{
    _value = (int64_t)round(d * ((int64_t)1 << _fractionalBitAmount));
}

FixedL::~FixedL()
{
}

        /*      OPERATORS           */
FixedL& FixedL::operator=(const FixedL& other) {
    if (this != &other)
        _value = other.getRawBits();
    return (*this);
}

std::ostream& operator<<(std::ostream &stream, const FixedL& fixed) {
    stream << fixed.toDouble();
    return (stream);
}

bool FixedL::operator <  (const FixedL &other) const { return _value < other.getRawBits(); }
bool FixedL::operator >  (const FixedL &other) const { return _value > other.getRawBits(); }
bool FixedL::operator <= (const FixedL &other) const { return _value <= other.getRawBits(); }
bool FixedL::operator >= (const FixedL &other) const { return _value >= other.getRawBits(); }
bool FixedL::operator == (const FixedL &other) const { return _value == other.getRawBits(); }
bool FixedL::operator != (const FixedL &other) const { return _value != other.getRawBits(); }

FixedL FixedL::operator + (const FixedL &other) const {
    FixedL f;
    f.setRawBits(_value + other.getRawBits());
    return (f);
}

FixedL FixedL::operator - (const FixedL &other) const {
    FixedL f;
    f.setRawBits(_value - other.getRawBits());
    return (f);
}

FixedL FixedL::operator * (const FixedL &other) const {
    FixedL f;
    __int128 rawtotal = (__int128)_value * other.getRawBits();
    f.setRawBits((int64_t)(rawtotal >> _fractionalBitAmount));
    return (f);
}

FixedL FixedL::operator / (const FixedL &other) const {
    FixedL f;
    if (other.getRawBits() == 0)
        throw (std::runtime_error("Division by zero"));
    __int128 rawtotal = ((__int128)_value << _fractionalBitAmount) / other.getRawBits();
    f.setRawBits((int64_t)rawtotal);
    return (f);
}

FixedL FixedL::operator + (const int i) const {
    FixedL f;
    f.setRawBits(_value + ((int64_t)i << _fractionalBitAmount));
    return (f);
}

FixedL FixedL::operator - (const int i) const {
    FixedL f;
    f.setRawBits(_value - ((int64_t)i << _fractionalBitAmount));
    return (f);
}

FixedL FixedL::operator * (const int i) const {
    FixedL f;
    f.setRawBits(_value * i);
    return (f);
}

FixedL FixedL::operator / (const int i) const {
    FixedL f;
    f.setRawBits(_value / i);
    return (f);
}

FixedL FixedL::operator++ (int) {
    FixedL old = (*this);
    _value++;
    return (old);
}

FixedL FixedL::operator-- (int) {
    FixedL old = (*this);
    _value--;
    return (old);
}

FixedL& FixedL::operator++ () {
    _value++;
    return (*this);
}

FixedL& FixedL::operator-- () {
    _value--;
    return (*this);
}

        /*      GETTER / SETTERS    */
int64_t FixedL::getRawBits(void) const {
    return (_value);
}

void FixedL::setRawBits(int64_t const raw) {
    _value = raw;
}

        /*      OTHER FUNCTIONS     */
int FixedL::toInt(void) const {
    return (int)(_value >> _fractionalBitAmount);
}

double FixedL::toDouble() const {
    return ((double)_value / ((int64_t)1 << _fractionalBitAmount));
}

void FixedL::halfValue() {
    _value = _value >> 1;
}

void FixedL::doubleValue() {
    _value = _value << 1;
}

FixedL FixedL::getHalvedValue() const {
    FixedL f;
    f.setRawBits(_value >> 1);
    return (f);
}

FixedL FixedL::getDoubledValue() const {
    FixedL f;
    f.setRawBits(_value << 1);
    return (f);
}
