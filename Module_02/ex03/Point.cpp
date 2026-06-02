#include <iostream>

#include "Point.hpp"

Point::Point() :
    x(Fixed(0)), y(Fixed(0))
{
    std::cout << "Default constructor called.\n";
}

Point::Point(const Fixed& x, const Fixed& y) :
    x(x), y(y)
{
    std::cout << "Constructor called.\n";
}

Point::Point(const Point& other) :
    x(other.x), y(other.y)
{
    std::cout << "Copy constructor called.\n";
}

Point& Point::operator=(const Point& other)
{
    if (this == &other)
        return (*this);
    (Fixed)this->x = other.getX();
    (Fixed)this->y = other.getY();
    std::cout << "Assignment constructor called.\n";
    return (*this);
}

Point::~Point()
{
    std::cout << "Destructor called.\n";
}

Fixed   Point::getX()
{
    return (this->x);
}

Fixed   Point::getY()
{
    return (this->y);
}