#include <cstdlib>
#include <exception>
#include <sstream>
#include <iostream>
#include <vector>

#include "PmergeMe.hpp"
#include "Timer.hpp"

template <class C>
void	printContainer(C& container)
{
	typedef typename C::const_iterator const_iterator;

	if (!container.size())
		return ;

	for (const_iterator it = container.begin(); it + 1 != container.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << *(container.end() - 1) << "\n";
}

int	main(int argc, char **argv)
{
	if (argc == 1) {
		std::cerr << "Error: usage -> ./PmergeMe <positive integers...>\n";
		return (EXIT_FAILURE);
	}

	std::vector<int>*	v = NULL;
	std::list<int>*		l = NULL;

	try {
		v = &PmergeMe::loadVector(argv + 1);
		l = &PmergeMe::loadList(argv + 1);

	} catch (const std::exception& e) {
		delete v; delete l;

		std::cerr << "Error: " << e.what() << "\n";
		return (EXIT_FAILURE);
	}

	std::ostringstream oss;

	std::cout << "Before:  "; printContainer(*v);
	{
		oss << "Time to process a range of " << v->size()
			<< " elements with std::vector : ";

		Timer	clock(oss);
		// PmergeMe::sortVector(*v);
	}
	{
		oss << "Time to process a range of " << l->size()
			<< " elements with std::list : ";

		Timer	clock(oss);
		// PmergeMe::sortList(*l);
	}
	std::cout << "After:   "; printContainer(*v);

	std::cout << oss.str();

}
