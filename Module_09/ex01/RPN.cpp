#include <cstddef>
#include <stdexcept>
#include <iostream>

#include "RPN.hpp"

// ----- Orthodox Canonical Implementation -----
RPN::RPN() { }

RPN::RPN(const RPN& other) : s(other.s) { }

RPN&	RPN::operator=(const RPN& other)
{
	if (this == &other)
		return (*this);

	s = other.s;

	return (*this);
}

RPN::~RPN() { }


// ----- Public  Methods -----
void	RPN::calcExpr(std::string& arg)
{
	const std::string	operators("+-*/");

	for (std::size_t i = 0; i < arg.size(); i++)
	{
		if (!s.empty() && arg.at(i - 1) != ' ' && arg.at(i) != ' ')
			throw std::runtime_error("consecutive tokens.");

		if (operators.find(arg.at(i)) != std::string::npos)
		{
			std::pair<RPN::Type, int>	p;

			p.first = RPN::Int;
			p.second = doOp(arg.at(i));

			s.push(p);
		}
		else if (arg.at(i) != ' ')
			s.push(std::make_pair(RPN::Char, arg.at(i)));
	}
	if (s.size() > 1)
		throw std::runtime_error("not enough operators");
	std::cout << s.top().second << "\n";
}

// ----- Private Methods -----
int	RPN::doOp(char op)
{
	if (s.size() < 2)
		throw std::runtime_error("not enough numbers for an operation.");

	int	firstValue;
	int	secondValue;

	firstValue = s.top().second - (s.top().first == RPN::Char ? '0' : 0);
	s.pop();

	secondValue = s.top().second - (s.top().first == RPN::Char ? '0' : 0);
	s.pop();

	if (op == '/' && firstValue == 0)
		throw std::runtime_error("division by 0");

	switch (op)
	{
		case ('*'): return (secondValue * firstValue);
		case ('+'): return (secondValue + firstValue);
		case ('-'): return (secondValue - firstValue);
		case ('/'): return (secondValue / firstValue);
		default: throw std::runtime_error("invalid operator");
	}
}
