#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <errno.h>
#include <cstdlib>

#include "ScalarConverter.hpp"

const std::string ScalarConverter::digits("0123456789");

// ORTHODOX CANONICAL IMPLEMENTATION
ScalarConverter::ScalarConverter() { }
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter() { }

// PUBLIC METHODS
void	ScalarConverter::convert(const std::string& str)
{
	char	*endptr;
	double	value;
	size_t	pos;

	if (str.empty())
		return ;

	errno = 0;
	value = std::strtod(str.c_str(), &endptr);
	pos = str.find_first_not_of(ScalarConverter::digits);
	


	//pos = str.find_first_not_of("DIGITS");

	std::cout << ScalarConverter::digits << "\n";
	if (*endptr)
	{
		double temp = std::strtod(str.c_str(), &endptr);
		
		return ;
	}

	std::cout << value << "\n";
}
