#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
public:
    Fixed();
    Fixed(const Fixed &);
    Fixed &operator=(const Fixed &);
    ~Fixed();

    int   getRawBits(void) const;
    void  setRawBits(int const raw);

private:
    static const int  fractional;
    int               value;
};


#endif
