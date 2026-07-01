#include <cstring>
#include <string>
#include <cctype>
#include <cstddef>
#include <stdexcept>

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::ifstream& file)
{
	const char*	alnum = "abcdefghijklmnopqrstuvwxyz0123456789";
	std::string	firstLine;
	std::getline(file, firstLine, '\n');

	if (file.eof())
		throw std::runtime_error("unexpected EOF encountered");

	std::size_t startDelim = firstLine.find_first_not_of(alnum);
	if (startDelim == std::string::npos)
		throw std::runtime_error("no separator in file");

	std::size_t endDelim = firstLine.find_first_of(alnum, startDelim);
	if (endDelim == std::string::npos)
		throw std::runtime_error("file must have two columns");

	delim = firstLine.substr(startDelim, endDelim - startDelim);

	file.exceptions(file.failbit);
	try {
		std::string	line;

		while (std::getline(file, line))
		{
			std::string	date = std::strtok(const_cast<char*>(line.c_str()), delim.c_str());
			
		}
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
