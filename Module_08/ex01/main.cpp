#include <iostream>

#include "Span.hpp"

static void	testException()
{
	std::cout << "\n===== Testing Exceptions =====\n";
	try {

		Span	sp(3);

		std::cout << "testing empty span...\n";

		std::cout << "sp -> {}\n\n";
		std::cout << "shortest: " << sp.shortestSpan() << "\n";

	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
	}

	std::cout << "\n\n";

	try {
		Span	sp(3);

		std::cout << "testing span with size 1...\n";
		sp.addNumber(67);

		std::cout << "sp -> {67}\n\n";
		std::cout << "shortest: " << sp.shortestSpan() << "\n";

	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
	}

	std::cout << "\n\n";

	try {
		Span	sp(3);

		std::cout << "testing span with size 2...\n";
		sp.addNumber(67);
		sp.addNumber(69);

		std::cout << "sp -> {67, 69}\n\n";
		std::cout << "shortest: " << sp.shortestSpan() << "\n";

	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
	}
}

static void	testRange()
{
	std::cout << "\n===== Testing addRange functions =====\n";
	try {
		Span	sp(3);

		std::cout << "adding with overload (int start, int end) 0 : 2 ...\n";
		sp.addRange(0, 2);

		std::cout << "sp -> {0, 1, 2}\n\n";
		std::cout << "shortest: " << sp.shortestSpan() << "\n";
		std::cout << "longest : " << sp.longestSpan() << "\n";

	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
	}

	std::cout << "\n\n";

	try {
		Span	sp(3);

		int					arr[] = {0, 1, 2};
		std::vector<int>	other(arr, arr + (sizeof(arr) / sizeof(arr[0])));

		std::cout << "adding with overload (std::vector<int> start, std::vector<int> end) 0 : 2 ...\n";
		sp.addRange(other.begin(), other.end());

		std::cout << "sp -> {0, 1, 2}\n\n";
		std::cout << "shortest: " << sp.shortestSpan() << "\n";
		std::cout << "longest : " << sp.longestSpan() << "\n";

	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
	}
}

static void	testSpans()
{
	std::cout << "\n===== Testing span functions =====\n";
	try {
		Span	sp(0);

		sp.addNumber(0);
		sp.addNumber(10);
		sp.addNumber(0);

		std::cout << "sp -> {0, 10, 0}\n\n";
		std::cout << "shortest: " << sp.shortestSpan() << "\n";
		std::cout << "longest : " << sp.longestSpan() << "\n";

	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
	}
}

static void	testSubject()
{
	std::cout << "\n===== Testing like in the subject =====\n";
	try {

		Span	sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "shortest: " << sp.shortestSpan() << "\n";
		std::cout << "longest : " << sp.longestSpan() << "\n";

	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
	}
}

int	main()
{
	testSubject();
	testSpans();
	testRange();
	testException();

	std::cout << std::endl;
}
