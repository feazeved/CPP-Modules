#include <iostream>

#include "Fixed.hpp"
#include "Point.hpp"

int	main()
{
	Point	A(Fixed(0), Fixed(0));
	Point	B(Fixed(0), Fixed(5));
	Point	C(Fixed(3), Fixed(2.5f));

	Point	D(Fixed(0.1f), Fixed(2));
	Point	F(Fixed(0), Fixed(0));
	Point	E(Fixed(float(3.0183)), Fixed(float(0.8)));

	std::cout << "\n\n\n-----Testing bsp-----\n";

	if (bsp(A, B, C, D))
		std::cout << "Point D is inside the triangle\n";
	else
		std::cout << "Point D is not inside the triangle\n";


	if (bsp(A, B, C, F))
		std::cout << "Point F is inside the triangle\n";
	else
		std::cout << "Point F is not inside the triangle\n";


	if (bsp(A, B, C, E))
		std::cout << "Point E is inside the triangle\n";
	else
		std::cout << "Point E is not inside the triangle\n";

	return (0);
}
