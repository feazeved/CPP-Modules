#include <limits>
#include <algorithm>
#include <cstdlib>

#include "Span.hpp"

// ----- Orthodox Canonical Implementation -----
Span::Span(unsigned int n)
{
	v.reserve(n);
}

Span::Span(const Span& other) :
	v(other.v) { }

Span& Span::operator=(const Span& other)
{
	if (this == &other)
		return (*this);

	v = other.v;

	return (*this);
}

Span::~Span() { }

// ----- Public Methods -----
// ----- To Add numbers -----
void	Span::addNumber(int num)
{
	v.push_back(num);
}

void	Span::addRange(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
	for (; first != last; first++)
		addNumber(*first);
}

void	Span::addRange(int first, int last)
{
	int	increment = (first < last) ? 1 : -1;

	for (; first <= last; first += increment)
		addNumber(first);
}

// ----- To return Spans -----
size_t	Span::shortestSpan()
{
	if (v.size() <= 1)
		throw Span::SpanException();

	size_t	pos = std::numeric_limits<size_t>::max();

	std::vector<int> copy = v;

	std::sort(copy.begin(), copy.end());

	for (std::vector<int>::iterator it = copy.begin(); it != copy.end(); it++)
	{
		if (it + 1 != copy.end() && std::abs(*(it + 1) - *it) < pos)
			pos = std::abs(*(it + 1) - *it);
	}
	return (pos);
}

size_t	Span::longestSpan()
{
	if (v.size() <= 1)
		throw Span::SpanException();

	std::vector<int>::iterator smallest = std::min_element(v.begin(), v.end());
	std::vector<int>::iterator biggest = std::max_element(v.begin(), v.end());

	size_t	distance = std::abs(*biggest - *smallest);

	return (distance);
}

// ----- Custom exception to be thrown when can't check span -----
const char*	Span::SpanException::what() const throw() { return ("Cannot check span when size is 0 or 1"); }
