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

static void	stt_printChar(const double& value)
{
	char	c = static_cast<unsigned char>(value);

	std::cout << "char: ";
	if (value != value)
		std::cout << "impossible";
	else if (!std::isprint(c))
		std::cout << "Non displayable";
	else
		std::cout << "'" << c << "'";

	std::cout << "\n";
}

static void	stt_printInt(const double& value)
{
	int	i = static_cast<int>(value);

	std::cout << "int: ";
	if (value != value
		|| value < std::numeric_limits<int>::min()
		|| value > std::numeric_limits<int>::max())
		std::cout << "impossible";
	else
		std::cout << i;

	std::cout << "\n";
}

static void	stt_printFloat(const double& value)
{
	float	f = static_cast<float>(value);

	std::cout << "float: ";
	if (value != value
		|| value < std::numeric_limits<float>::min()
		|| value > std::numeric_limits<float>::max())
		std::cout << "impossible";
	else
		std::cout << f << "f";

	std::cout << "\n";
}

static void	stt_printDouble(const double& value)
{
	std::cout << "double: ";

	if (value != value)
		std::cout << "impossible";
	else
		std::cout << value;

	std::cout << "\n";
}


// PUBLIC METHODS
void	ScalarConverter::convert(std::string str)
{
	const char* startptr = str.c_str();
	char*		endptr = NULL;
	double		value;

	stt_trim(str);
	if (str.empty() || stt_isHex(str) || stt_isOct(str))
		return ;

	errno = 0;
	if (std::isprint(str.at(0)) && !str.at(1))
		value = static_cast<double>(str.at(0));
	else
	{
		value = std::strtod(startptr, &endptr);
		if (stt_strtodInvalid(startptr, endptr))
			return ;
	}

	stt_printChar(value);
	stt_printInt(value);
	stt_printFloat(value);
	stt_printDouble(value);
}
