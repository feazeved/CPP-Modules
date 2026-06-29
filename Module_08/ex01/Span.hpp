#pragma once

#include <vector>
#include <exception>

class Span {
public:
	Span(unsigned int n);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void	addNumber(int num);
	void	addRange(std::vector<int>::iterator first, std::vector<int>::iterator last);
	void	addRange(int first, int last);
	size_t	shortestSpan();
	size_t	longestSpan();

private:
	std::vector<int>	v;

public:
	class SpanException : public std::exception {
		public:
			const char*	what() const throw();
	};
};
