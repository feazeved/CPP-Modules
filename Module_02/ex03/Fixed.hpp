#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
public:
    Fixed();
    Fixed(const int v);
    Fixed(const float v);
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    int   getRawBits(void) const;
    void  setRawBits(int const raw);

    float toFloat(void) const;
    int   toInt(void) const;

    bool  operator>(const Fixed& other) const;
    bool  operator<(const Fixed& other) const;
    bool  operator>=(const Fixed& other) const;
    bool  operator<=(const Fixed& other) const;
    bool  operator==(const Fixed& other) const;
    bool  operator!=(const Fixed& other) const;

    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;


    Fixed &operator++();
    Fixed operator++(int);

    Fixed &operator--();
    Fixed operator--(int);


    static Fixed& min(Fixed& first, Fixed& second);
    static const  Fixed&  min(const Fixed& first, const Fixed& second);
    
    static Fixed& max(Fixed& first, Fixed& second);
    static const  Fixed&  max(const Fixed& first, const Fixed& second);

private:
    static const int  fractional;
    int               value;
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);

#endif
