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

bool  Fixed::operator>(const Fixed& other) const
{
    return (this->toFloat() > other.toFloat());
}

bool  Fixed::operator<(const Fixed& other) const
{
    return (this->toFloat() < other.toFloat());
}

bool  Fixed::operator>=(const Fixed& other) const
{
    return (this->toFloat() >= other.toFloat());
}

bool  Fixed::operator<=(const Fixed& other) const
{
    return (this->toFloat() <= other.toFloat());
}

bool  Fixed::operator==(const Fixed& other) const
{
    return (this->value == other.value);
}

bool  Fixed::operator!=(const Fixed& other) const
{
    return (this->toFloat() != other.toFloat());
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits(this->value + other.value);
    return (result);
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed	result;

	result.setRawBits(this->value - other.value);
    return (result);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits((long long)this->value * other.value >> fractional);
    return (result);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits((long long)this->value << fractional / other.value);
    return (result);
}

Fixed& Fixed::operator++()
{
    this->value++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed copy(*this);
    operator++();
    return (copy);
}

Fixed& Fixed::operator--()
{
    this->value--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed copy(*this);
    operator--();
    return (copy);
}

Fixed& Fixed::min(Fixed& first, Fixed& second)
{
    return (first < second ? first : second);
}

const Fixed&  Fixed::min(const Fixed& first, const Fixed& second)
{
    return (first < second ? first : second);
}

Fixed& Fixed::max(Fixed& first, Fixed& second)
{
    return (first > second ? first : second);
}

const Fixed&  Fixed::max(const Fixed& first, const Fixed& second)
{
    return (first > second ? first : second);
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj)
{
    out << obj.toFloat();
    return (out);
}
