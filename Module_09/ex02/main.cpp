#include <cstdlib>
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

	for (const_iterator it = container.begin(); it + 1 != container.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << *(container.end() - 1) << "\n";
}

int	main(int argc, char **argv)
{
	if (argc == 1) {
		std::cerr << "Error: usage -> ./PmergeMe <positive integers>\n";
		return (EXIT_FAILURE);
	}

	PmergeMe*	all = NULL;
	try {
		all = new PmergeMe(argv + 1);

	} catch (const std::exception& e) {
		delete all;
		std::cerr << "Error: " << e.what() << "\n";
		return (EXIT_FAILURE);
	}

	std::ostringstream oss;

	std::cout << "Before:  "; printContainer(all->getV());
	{
		oss << "Time to process a range of " << all->getV().size()
			<< "elements with std::vector : ";

		Timer	clock(oss);
		all->sortVector();
	}
	{
		oss << "Time to process a range of " << all->getL().size()
			<< "elements with std::list : ";

		Timer	clock(oss);
		all->sortList();
	}
	std::cout << "After:   "; printContainer(all->getV());

	std::cout << oss.str();

	delete all;
}
