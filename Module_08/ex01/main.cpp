#include <iostream>

#include "Span.hpp"

int	main()
{
	Span	sp(2);

	sp.addNumber(10);
	sp.addNumber(1);
	sp.addNumber(10);

	std::cout << sp.longestSpan() << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	return (0);
}
