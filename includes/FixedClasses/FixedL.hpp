#ifndef FIXEDL_HPP
#define FIXEDL_HPP

#include "../MLX42/include/MLX42/MLX42.h"
#include "macros.hpp"
#include <iostream>
#include <cmath>

class FixedL {
    private:
        int64_t             _value;
        static constexpr int _fractionalBitAmount = FIXED_LONG_FRACTIONAL_BITS;

    public:
        FixedL();
        FixedL(int const i);
        FixedL(int64_t const inRawBits, int inFractionalBitAmount);
        FixedL(double const d);
        FixedL(const FixedL& fx);
        ~FixedL();

        FixedL& operator=(const FixedL& other);

        int64_t getRawBits(void) const;
        void    setRawBits(int64_t const raw);
        double  toDouble(void) const;
        int     toInt(void) const;

        bool    operator< (const FixedL &other) const;
        bool    operator> (const FixedL &other) const;
        bool    operator<=(const FixedL &other) const;
        bool    operator>=(const FixedL &other) const;
        bool    operator==(const FixedL &other) const;
        bool    operator!=(const FixedL &other) const;

        FixedL  operator+(const FixedL &other) const;
        FixedL  operator-(const FixedL &other) const;
        FixedL  operator*(const FixedL &other) const;
        FixedL  operator/(const FixedL &other) const;

        FixedL  operator+(const int) const;
        FixedL  operator-(const int) const;
        FixedL  operator*(const int) const;
        FixedL  operator/(const int) const;

        FixedL  operator++(int);
        FixedL& operator++(void);
        FixedL  operator--(int);
        FixedL& operator--(void);

        void    halfValue();
        void    doubleValue();
        FixedL  getHalvedValue() const;
        FixedL  getDoubledValue() const;

        static bool isOutOfRadius(const int64_t a, const int64_t b);
};

std::ostream& operator<<(std::ostream &stream, const FixedL& fixed);

#endif