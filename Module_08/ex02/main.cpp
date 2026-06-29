#include <iostream>
#include <stack>

#include "MutantStack.hpp"

void	giantMain()
{
	std::cout << "\n===== Testing giant stack =====\n";
	const size_t			size = 10000;
	MutantStack<int>*	myStack = NULL;

	try {
		myStack = new MutantStack<int>();
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";

		delete myStack;
		return ;
	}

	std::cout << "Pushing 10000 numbers from 0 to 9999...\n";
	for (size_t i = 0; i < size; i++)
		myStack->push(i);

	MutantStack<int>::iterator	it = myStack->begin();
	MutantStack<int>::iterator	ite = myStack->end();

	std::cout << "All multiples of 67: \n";
	for (; it != ite; it++)
	{
		if (*it && *it % 67 == 0)
			std::cout << *it << " ";
	}

	std::cout << "\n\n===== Popping everything =====\n";

	std::cout << "Before: \n"
			  << "Top: " << myStack->top() << "\n"
			  << "Size: " << myStack->size() << "\n";

	for (; !myStack->empty();) {
		myStack->pop();
	}

	std::cout << "\nAfter: \n"
			  << "Top: " << (myStack->empty() ? 0 : myStack->top()) << "\n"
			  << "Size: " << myStack->size() << "\n";

	delete myStack;
}

void	subjectMain()
{
	std::cout << "\n===== Main subject =====\n";
	MutantStack<int>	myStack;

	std::cout << "Adding 5 and 17...\n";
	myStack.push(5);
	myStack.push(17);

	std::cout << "\ntop: " << myStack.top() << "\n";

	std::cout << "\npopping once...\n";
	myStack.pop();

	std::cout << "\nsize: " << myStack.size() << "\n";

	std::cout << "\nAdding 3, 5 and 7...\n\n";
	myStack.push(3);
	myStack.push(5);
	myStack.push(7);

	MutantStack<int>::iterator	it = myStack.begin();
	MutantStack<int>::iterator	ite = myStack.end();

	++it;
	--it;

	std::cout << "Stack: \n";
	while (it != ite)
	{
		std::cout << "       |" << *it << "|\n";
		++it;
	}
	std::cout << "        ^--- this is the top\n";

	std::stack<int>	s(myStack);
}

int	main()
{
	subjectMain();
	giantMain();
}
