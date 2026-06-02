#include "Fixed.hpp"

/*
void	test_operators(Fixed& a, const Fixed& b)
{
	Fixed	c;

	if (a < b)
		std::cout << "Should print! a < b\n";
	if (a > b)
		std::cout << "Shouldnt print!\n";
	if (a == c)
		std::cout << "Should print! a==c \n";

	c = a + b;
	std::cout << c << "\n";
	c = c - a;
	std::cout << c << "\n";
	c = c * a;
	std::cout << c << "\n";
}
*/

int main(void)
{
    Fixed       a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max(a, b) << std::endl;
    return (0);
}
