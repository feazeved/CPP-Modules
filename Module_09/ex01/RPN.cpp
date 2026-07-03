#include <cstddef>
#include <stdexcept>

#include "RPN.hpp"

// ----- Orthodox Canonical Implementation -----
RPN::RPN() { }

RPN::RPN(std::string& arg)
{
	trimSpaces(arg);
	for (std::size_t i = 0; i < arg.size(); i++)
	{
		if (arg.at(i) != ' ' && (arg.at(i) < '*' || arg.at(i) > '9'
			|| arg.at(i) == ',' || arg.at(i) == '.'))
			throw std::runtime_error("invalid token");

		if ()
	}
}

RPN::RPN(const RPN& other) : s(other.s) { }

RPN&	RPN::operator=(const RPN& other)
{
	if (this == &other)
		return (*this);

	s = other.s;

	return (*this);
}

RPN::~RPN() { }

// ----- Private Methods -----
void	RPN::trimSpaces(std::string& arg)
{
	while (arg.size() && arg.at(0) == ' ')
		arg.erase(0);
	while (arg.size() && arg.at(arg.size() - 1) == ' ')
		arg.erase(arg.size() - 1);
}
