#include <cstdlib>
#include <iostream>

#include "PmergeMe.hpp"
#include "Timer.hpp"

int	main(int argc, char **argv)
{
	if (argc == 1) {
		std::cerr << "Error: usage -> ./PmergeMe <positive integers>\n";
		return (EXIT_FAILURE);
	}

	PmergeMe	v(argv + 1);
	PmergeMe	l(argv + 1);

	v.printVector()

	
	{
		
		Timer	clock;

		v.vectorSort();
	}

}
