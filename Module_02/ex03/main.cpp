#include <iostream>

#include "Fixed.hpp"
#include "Point.hpp"

int	main()
{
	Point	A(1, 4);
	Point	B(4, 2);
	Point	C(3, -5);

	Point	D(4, 3);
	Point	F(3, 0);
	Point	E(float(3.0183), float(0.8));

	std::cout << "\n\n\n-----Testing bsp-----\n";

	if (bsp(A, B, C, D))
		std::cout << "Point D is inside the triangle.\n";
	else
		std::cout << "Point D is not inside the triangle.\n";


	if (bsp(A, B, C, F))
		std::cout << "Point F is inside the triangle.\n";
	else
		std::cout << "Point F is not inside the triangle.\n";


	if (bsp(A, B, C, E))
		std::cout << "Point E is inside the triangle.\n";
	else
		std::cout << "Point E is not inside the triangle.\n";

	return (0);
}
