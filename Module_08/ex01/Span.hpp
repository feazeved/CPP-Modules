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
	int		shortestSpan();
	int		longestSpan();

private:
	std::vector<int>	v;


public:
	class SpanException : public std::exception {
		public:
			const char*	what() const throw();
	};
};
