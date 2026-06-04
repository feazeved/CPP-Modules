#include <iostream>
#include <cmath>

#include "Fixed.hpp"

const int	Fixed::fractional = 8;

Fixed::Fixed() :
    value(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int v_int) :
    value(v_int << fractional)
{
    std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float v_float) :
    value(roundf(v_float * (1 << fractional)))
{
    std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed& other) :
    value(other.value)
{
    std::cout << "Copy constructor called\n";
}


Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called\n";
    if (this == &other)
        return (*this);
    this->value = other.value;
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called\n";
    return (value);
}

void  Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called\n";
    value = raw;
}

float Fixed::toFloat(void) const
{
    return (float(value) / float(1 << fractional));
}

int   Fixed::toInt(void) const
{
    return (value >> fractional);
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj)
{
    out << obj.toFloat();
    return (out);
}
