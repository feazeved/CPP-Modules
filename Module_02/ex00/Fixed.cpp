#include <iostream>

#include "Fixed.hpp"

const int	Fixed::fractional = 8;

Fixed::Fixed() :
    value(0)
{
    std::cout << "Default constructor called\n";
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
    this->setRawBits(other.getRawBits());
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called\n";
    return (this->value);
}

void  Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called\n";
    this->value = raw;
}
