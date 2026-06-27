#include <iostream>

#include "Span.hpp"

int	main()
{
	Span	sp(10);

	int					arr[] = {0, 1, 2, 3, 4, 5, 6, 7};
	std::vector<int>	toAdd(arr, arr + (sizeof(arr) / sizeof(arr[0])));

	sp.addRange(toAdd.begin(), toAdd.end());

	std::cout << sp.longestSpan() << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	return (0);
}
