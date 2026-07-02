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
BitcoinExchange::BitcoinExchange(std::ifstream& file)
{
	if (file.eof())
		throw std::runtime_error("unexpected EOF encountered");

	file.exceptions(file.failbit);
	try {
		std::string	line;
		char		delim;

		std::getline(file , line, '\n');
		delim = BitcoinExchange::parseHeader(line);

		while (std::getline(file, line, '\n'))
			m.insert(makePair(line,  delim));

	} catch (const std::ios_base::failure& e) {
		if (!file.eof())
			throw std::runtime_error("failure reading file");
	}
}

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
void	BitcoinExchange::checkInput(std::ifstream& file) const
{
	if (file.eof())
		return ;

	file.exceptions(file.failbit);
	try {
		std::string	line;
		char		delim;

		std::getline(file, line, '\n');
		delim = BitcoinExchange::parseHeader(line);

		while (std::getline(file, line, '\n'))
		{
			pair	input = makePair(line, delim);

			if (input.first.find("Error") != std::string::npos)
				std::cerr << input.first << input.second << "\n";
			else
			{
				const_iterator	it =  m.lower_bound(input.first);

				if (input.first != it->first && it != m.begin())
					it--;

				std::cout << input.first << " => " << input.second << " = ";
				std::cout << std::strtod(input.second.c_str(), NULL) * std::strtod(it->second.c_str(), NULL);

				std::cout << "\n";
			}
		}

	} catch (const std::ios_base::failure& e) {
		if (!file.eof())
			throw std::runtime_error("failure reading file");
	}
}

const std::map<std::string, std::string>&	BitcoinExchange::getMap() const { return (m); }


// ----- Private Methods -----
pair	BitcoinExchange::makePair(std::string& line, char delim = ',')
{
	pair				columns;
	std::stringstream	row(line);

	if (line.empty())
		return (std::make_pair("Error: ", "empty line."));
	row.exceptions(row.failbit);
	std::getline(row, columns.first, delim);
	std::getline(row, columns.second, delim);

	char*		endptr = NULL;
	const char*	startptr = columns.second.c_str();

	double	value = std::strtod(startptr, &endptr);
	if (*endptr || startptr == endptr)
		return (std::make_pair("Error: ", "invalid value number."));
	else if (value < 0)
		return (std::make_pair("Error: ", "not a positive number."));
	else if (value > 1000)
		return (std::make_pair("Error: ", "too large a number."));

	return (columns);
}

char	BitcoinExchange::parseHeader(std::string& line)
{
	const char*	alnum = "abcdefghijklmnopqrstuvwxyz0123456789 ";

	std::size_t delimPos = line.find_first_not_of(alnum);
	if (delimPos == std::string::npos)
		throw std::runtime_error("no separator at first line of file");

	return (line[delimPos]);
}
