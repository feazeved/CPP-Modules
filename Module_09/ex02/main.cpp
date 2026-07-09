#include <cstdlib>
#include <exception>
#include <sstream>
#include <iostream>

#include "PmergeMe.hpp"
#include "Timer.hpp"

template <class C>
void	printContainer(C& container)
{
	typedef typename C::const_iterator const_iterator;

	if (!container.size())
		return ;

	const bool	abbreviate = (container.size() >= 20);

	const_iterator	eit = (abbreviate ? container.begin() + 20 : container.end());

	for (const_iterator it = container.begin(); it != eit; it++) {
		std::cout << *it << " ";
	}

	if (abbreviate)
		std::cout << "[...] ";
	std::cout << "\n";
}

int	main(int argc, char **argv)
{
	if (argc == 1) {
		std::cerr << "Error: usage -> ./PmergeMe <positive integers...>\n";
		return (EXIT_FAILURE);
	}

	std::vector<int>*	v = NULL;
	std::deque<int>*	d = NULL;

	try {
		v = &PmergeMe::loadVector(argv + 1);
		d = &PmergeMe::loadDeque(argv + 1);

	} catch (const std::exception& e) {
		delete v; delete d;

		std::cerr << "Error: " << e.what() << "\n";
		return (EXIT_FAILURE);
	}

	std::ostringstream oss;

	std::cout << "Before:  "; printContainer(*v);
	{
		oss << "Time to process a range of " << v->size()
			<< " elements with std::vector : ";

		Timer	clock(oss);
		PmergeMe::sort(*v);
	}
	{
		oss << "Time to process a range of " << d->size()
			<< " elements with std::deque : ";

		Timer	clock(oss);
		PmergeMe::sort(*d);
	}
	std::cout << "After:   "; printContainer(*v);

	std::cout << oss.str();

	delete v; delete d;
}
