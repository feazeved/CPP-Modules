#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iterator>
#include <sstream>
#include <string>
#include <cctype>
#include <cstddef>
#include <stdexcept>
#include <iostream>
#include <utility>

#include "BitcoinExchange.hpp"

// ----- Orthodox Canonical Implementation -----
BitcoinExchange::BitcoinExchange() { }

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) :
	m(other.m) { }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this == &other)
		return (*this);

	m = other.m;

	return (*this);
}

BitcoinExchange::~BitcoinExchange() { }


typedef std::pair<std::string, std::string>					pair;
typedef std::map<std::string, std::string>::const_iterator	const_iterator;

// ----- Public Methods -----
void	BitcoinExchange::loadDB(std::ifstream& file)
{
	std::string	line;
	char		delim;

	for (int i = 0; std::getline(file, line, '\n'); i++) {
		if (i == 0) {
			delim = parseHeader(line);
			continue ;
		}
		trimLine(line);
		if (line.empty())
			continue ;

		pair	columns;
		if (!makePair(line, columns, delim))
			throw std::runtime_error("database error at line" + std::to_string(i + 1));

		m.insert(columns);
	}
	if (file.bad())
		throw std::runtime_error("failure loading database");
}

void	BitcoinExchange::checkPrice(std::string& input) const
{

}


// ----- Private Methods -----
bool	BitcoinExchange::makePair(std::string& line, pair& columns, char delim)
{
	std::string::iterator	first = line.begin();
	std::size_t				second = line.find_first_of(delim, 0);

	if (second == std::string::npos) {
		columns = std::make_pair(line, "");
		return (false);
	}




	return (columns);
}

static int	daysInMonth(int month, int year);
static bool	isValidDate(int year, int month, int day);

void	BitcoinExchange::trimLine(std::string& line)
{
	for (std::string::iterator it = line.begin(); it != line.end(); it++) {
		if (*it == ' ' || *it == '\t')
			line.erase(it);
	}
}

void	BitcoinExchange::makeDate(std::stringstream& row, pair& columns, char delim)
{
	if (row.fail() && !row.eof())
	{
		columns = std::make_pair("Error: ", "bad input => ");
		return ;
	}

	const char*	startptr = columns.first.c_str();
	char*		endptr = NULL;

	if (columns.first.size() != 10 && (columns.first.size() != 11 || columns.first.at(columns.first.size() - 1) != ' '))
	{
		columns = std::make_pair("Error: bad input => ", columns.first);
		return ;
	}
	if (columns.first.at(4) != '-' || columns.first.at(7) != '-')
	{
		columns = std::make_pair("Error: bad input => ", columns.first);
		return ;
	}

	errno = 0;
	const long	year = std::strtol(startptr, &endptr, 10);
	if (*endptr != '-' || errno == ERANGE)
	{
		columns = std::make_pair("Error: bad input => ", columns.first);
		return ;
	}

	const long	month = std::strtol(endptr + 1, &endptr, 10);
	if (*endptr != '-' || errno == ERANGE)
	{
		columns = std::make_pair("Error: bad input => ", columns.first);
		return ;
	}

	const long day = std::strtol(endptr + 1, &endptr, 10);
	if (errno == ERANGE || (*endptr && *endptr != ' ' && *endptr != delim && *endptr != '\t'))
	{
		columns = std::make_pair("Error: bad input => ", columns.first);
		return ;
	}

	if (!isValidDate(year, month, day))
		columns = std::make_pair("Error: bad input => ", columns.first);
}

void	BitcoinExchange::makeValue(std::stringstream& row, pair& columns)
{
	if (row.fail() && !row.eof())
	{
		columns = std::make_pair("Error: ", "bad input => ");
		return ;
	}

	char*		endptr = NULL;
	const char*	startptr = columns.second.c_str();

	errno = 0;
	double	value = std::strtod(startptr, &endptr);
	if (*endptr || startptr == endptr)
	{
		columns = std::make_pair("Error: ", "bad input =>");
		return ;
	}
	else if (value < 0)
	{
		columns = std::make_pair("Error: ", "not a positive number.");
		return ;
	}
	else if (value > 1000 || errno == ERANGE)
		columns = std::make_pair("Error: ", "too large a number.");
}

char	BitcoinExchange::parseHeader(std::string& line)
{
	const char*	alnum = "abcdefghijklmnopqrstuvwxyz0123456789 ";

	std::size_t delimPos = line.find_first_not_of(alnum);
	if (delimPos == std::string::npos)
		throw std::runtime_error("no separator at first line of file");

	return (line[delimPos]);
}

static int	daysInMonth(int month, int year)
{
	int	days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2
		&& ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		return (29);
	return (days[month - 1]);
}

static bool	isValidDate(int year, int month, int day)
{
	if (year < 2009 || (month < 1 || month > 12))
		return (false);
	if (day < 1 || day > daysInMonth(month, year))
		return (false);
	return (true);
}

bool	operator!(const pair& pair)
{
	return (pair.first.find("Error") != std::string::npos);
}
