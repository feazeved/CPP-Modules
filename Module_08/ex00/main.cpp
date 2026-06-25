#include "easyfind.hpp"

#include <vector>

int	main()
{
	const size_t		len = 2;
	std::vector<int>	test1;

	for (size_t i = 0; i < len; i++)
	{
		test1.push_back(i);
	}

	::easyfind(test1, 1);


	return (0);
}
