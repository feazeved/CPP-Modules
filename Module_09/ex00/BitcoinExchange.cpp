#include <cstring>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <cstddef>
#include <stdexcept>

#include "BitcoinExchange.hpp"

// ----- Orthodox Canonical Implementation -----
BitcoinExchange::BitcoinExchange(std::ifstream& file)
{
	if (file.eof())
		throw std::runtime_error("unexpected EOF encountered");

	file.exceptions(file.failbit);
	try {
		std::string	line;

		std::getline(file , line, '\n');
		delim = BitcoinExchange::parseHeader(line);

		while (std::getline(file, line, '\n'))
			m.insert(BitcoinExchange::makePair(line, delim));

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


// ----- Public Methods -----
const std::map<std::string, std::string>&	BitcoinExchange::getMap() const { return (m); }


// ----- Private Methods -----
typedef std::pair<std::string, std::string>	pair;

pair	BitcoinExchange::makePair(std::string& line, char delim)
{
	std::stringstream	row(line);
	pair				columns;

	row.exceptions(row.failbit);
	std::getline(row, columns.first, delim);
	std::getline(row, columns.second, delim);

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
