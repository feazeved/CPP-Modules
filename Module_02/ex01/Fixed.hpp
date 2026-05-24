#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
public:
    explicit Fixed();
    explicit Fixed(const int v);
    explicit Fixed(const float v);
    explicit Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    int   getRawBits(void) const;
    void  setRawBits(int const raw);

    float toFloat(void) const;
    int   toInt(void) const;

private:
    static const int  fractional = 8;
    int               value;
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);

#endif
