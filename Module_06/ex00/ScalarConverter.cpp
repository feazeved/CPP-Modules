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

static void	stt_trim(std::string& str)
{
	const char*	begin;
	size_t		start_pos;
	size_t		toDelete;

	if (!str.at(0))
		return ;

	begin = str.c_str();
	start_pos = str.find_first_not_of(" ");

	toDelete = static_cast<size_t>((begin + start_pos) - begin);
	str.erase(0, toDelete);


	const char* end;
	size_t		end_pos;

	begin = str.c_str();
	end = str.c_str() + str.length() - 1;
	end_pos = str.find_last_not_of(" ");

	toDelete = static_cast<size_t>(end - (begin + end_pos));
	str.erase(end_pos, toDelete);
}

static bool stt_isHex(const std::string& str)
{
	if (str.at(0) == '0' && (str.at(1) == 'x' || str.at(1) == 'X'))
		return (true);
	return (false);
}

static bool	stt_isOct(const std::string& str)
{
	if (str.at(0) == '0' && (str.at(1) >= '0' && str.at(1) <= '9'))
		return (true);
	return (false);
}

static bool	stt_strtodInvalid(const char* startptr, char *endptr)
{
	if (errno == ERANGE
		|| startptr == endptr
		|| (*endptr && *endptr != 'f')
		|| (*endptr == 'f' && *(endptr + 1)))
	{
		std::cerr << "Error: Invalid input.\n";
		return (true);
	}
	return (false);
}

// PUBLIC METHODS
void	ScalarConverter::convert(std::string str)
{
	const char	*startptr;
	char	*endptr = NULL;
	double	value;

	stt_trim(str);
	if (str.empty() || stt_isHex(str) || stt_isOct(str))
		return ;

	errno = 0;
	startptr = str.c_str();
	value = std::strtod(startptr, &endptr);

	if (stt_strtodInvalid(startptr, endptr))
		return ;

	std::cout << value << "\n";
}
