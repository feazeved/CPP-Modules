#include <cerrno>
#include <cstdlib>
#include <cstddef>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <iostream>
#include <utility>

#include "BitcoinExchange.hpp"

// ----- Orthodox Canonical Implementation -----
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) :
	m(other.m) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this == &other)
		return (*this);

	m = other.m;

	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

typedef std::pair<std::string, std::string>					pair;
typedef std::map<std::string, std::string>::const_iterator	const_iterator;

// ----- Public Methods -----
void	BitcoinExchange::loadDB(std::ifstream& file)
{
	std::string	line;
	char		delim = ',';
	int			i = 0;

	while (std::getline(file, line)) {
		trimLine(line);
		if (line.empty())
			continue;
		if (i == 0) {
			delim = parseHeader(line);
			i++;
			continue;
		}
		pair	columns;
		if (!makePair(line, columns, delim, false)) {
			std::ostringstream oss;
			oss << "database error at line " << (i + 1);
			throw std::runtime_error(oss.str());
		}
		m.insert(columns);
		i++;
	}
	if (file.bad())
		throw std::runtime_error("I/O failure loading database");
}

void	BitcoinExchange::checkPrice(const std::string& input) const
{
	static bool	headerSkipped = false;
	if (!headerSkipped) {
		headerSkipped = true;
		return;
	}

	pair	inputPair;
	if (!makePair(input, inputPair, '|', true)) {
		if (inputPair.second == "-")
			std::cerr << "Error: not a positive number.\n";
		else if (inputPair.second == "+")
			std::cerr << "Error: too large a number.\n";
		else
			std::cerr << "Error: bad input => " << inputPair.first << "\n";
		return;
	}

	const_iterator	it = m.lower_bound(inputPair.first);
	if (it == m.end() || it->first != inputPair.first) {
		if (it == m.begin()) {
			std::cerr << "Error: date not found in database.\n";
			return;
		}
		--it;
	}

	double	inputValue = std::strtod(inputPair.second.c_str(), NULL);
	double	mapValue   = std::strtod(it->second.c_str(), NULL);

	std::cout << inputPair.first << " => " << inputPair.second
			  << " = " << inputValue * mapValue << "\n";
}

// ----- Private Methods -----
bool	BitcoinExchange::makePair(const std::string& line, pair& columns, char delim, bool inputMode)
{
	std::size_t	delimPos = line.find(delim);

	if (delimPos == std::string::npos) {
		columns = std::make_pair(line, "");
		return (false);
	}

	if (!makeDate(line.substr(0, delimPos), columns.first))
		return (false);

	if (!makeValue(line.substr(delimPos), columns.second, inputMode))
		return (false);

	return (true);
}

void	BitcoinExchange::trimLine(std::string& line)
{
	std::string::iterator	it = line.begin();
	while (it != line.end()) {
		if (*it == ' ' || *it == '\t' || *it == '\r')
			it = line.erase(it);
		else
			++it;
	}
}

static int	daysInMonth(int month, int year);
static bool	isValidDate(int year, int month, int day);

bool	BitcoinExchange::makeDate(const std::string& date, std::string& mapKey)
{
	std::size_t	end = date.find_last_not_of(" \t\r");
	if (end == std::string::npos) {
		mapKey = date;
		return (false);
	}
	const std::string	trimmed = date.substr(0, end + 1);

	if (trimmed.size() != 10 || trimmed[4] != '-' || trimmed[7] != '-') {
		mapKey = trimmed;
		return (false);
	}

	char*		endptr;
	errno = 0;
	const long	year = std::strtol(trimmed.c_str(), &endptr, 10);
	if (errno == ERANGE || *endptr != '-') { mapKey = trimmed; return (false); }

	errno = 0;
	const long	month = std::strtol(endptr + 1, &endptr, 10);
	if (errno == ERANGE || *endptr != '-') { mapKey = trimmed; return (false); }

	errno = 0;
	const long	day = std::strtol(endptr + 1, &endptr, 10);
	if (errno == ERANGE || *endptr != '\0') { mapKey = trimmed; return (false); }

	if (!isValidDate(static_cast<int>(year), static_cast<int>(month), static_cast<int>(day))) {
		mapKey = trimmed;
		return (false);
	}

	mapKey = trimmed;
	return (true);
}

bool	BitcoinExchange::makeValue(const std::string& value, std::string& mapValue, bool inputMode)
{
	std::size_t	start = value.find_first_not_of(",| \t");
	if (start == std::string::npos) {
		mapValue = "";
		return (false);
	}

	std::size_t			end     = value.find_last_not_of(" \t\r");
	const std::string	trimmed = value.substr(start, end - start + 1);

	const char*	startptr = trimmed.c_str();
	char*		endptr;
	errno = 0;
	const double	val = std::strtod(startptr, &endptr);

	if (endptr == startptr || *endptr != '\0') {
		mapValue = "";
		return (false);
	}
	if (errno == ERANGE) {
		mapValue = "+";
		return (false);
	}
	if (val < 0) {
		mapValue = "-";
		return (false);
	}
	if (inputMode && val > 1000) {
		mapValue = "+";
		return (false);
	}

	mapValue = trimmed;
	return (true);
}

char	BitcoinExchange::parseHeader(const std::string& line)
{
	const char*	alnum = "abcdefghijklmnopqrstuvwxyz0123456789 ";

	std::size_t	delimPos = line.find_first_not_of(alnum);
	if (delimPos == std::string::npos)
		throw std::runtime_error("no separator found in file header");

	return (line[delimPos]);
}

static int	daysInMonth(int month, int year)
{
	int	days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		return (29);
	return (days[month - 1]);
}

static bool	isValidDate(int year, int month, int day)
{
	if (year < 2009 || month < 1 || month > 12)
		return (false);
	if (day < 1 || day > daysInMonth(month, year))
		return (false);
	return (true);
}
