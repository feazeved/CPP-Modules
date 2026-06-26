#include <limits>
#include <algorithm>
#include <cstdlib>

#include "Span.hpp"

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


void	Span::addNumber(int num)
{
	v.push_back(num);
}

int		Span::shortestSpan()
{
	int	pos = std::numeric_limits<int>::max();

	if (v.size() <= 1)
		throw Span::SpanException();

	std::sort(v.begin(), v.end());

	for (std::vector<int>::iterator out = v.begin(); out != v.end(); out++)
	{
		for (std::vector<int>::iterator in = (out + 1); in != v.end(); in++)
		{
			if (std::abs(*in - *out) < pos)
				pos = std::abs(*in - *out);
		}
	}
	return (pos);
}

int		Span::longestSpan()
{
	if (v.size() <= 1)
		throw Span::SpanException();

	std::sort(v.begin(), v.end());

	int	distance = std::abs(v.at(v.size() - 1) - v.at(0));

	return (distance);
}

const char*	Span::SpanException::what() const throw() { return ("Cannot check span when size is 0 or 1"); }
