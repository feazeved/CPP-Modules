#include <cstring>
#include <string>
#include <cctype>
#include <cstddef>
#include <stdexcept>

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::ifstream& file)
{
	const char*	alnum = "abcdefghijklmnopqrstuvwxyz0123456789 ";
	std::string	firstLine;
	std::getline(file, firstLine, '\n');

	if (file.eof())
		throw std::runtime_error("unexpected EOF encountered");

	std::size_t delimPos = firstLine.find_first_not_of(alnum);
	if (delimPos == std::string::npos)
		throw std::runtime_error("no separator at first line of file");

	delim = firstLine[delimPos];

	file.exceptions(file.failbit);
	try {
		std::string	line;

		while (std::getline(file, line))
		{
			q.push(BitcoinExchange::makePair(line))
			if (stt_invalidLine(line))
			{
				q.push(std::make_pair(T1 &&t1, T2 &&t2));
				continue ;
			}

			std::string	date = line.substr(line.find(delim.at(0)));
			std::string	value = line.substr(line.find(delim.at(0)) + delim.size(), line.size());

			m.insert(std::make_pair(date, value));
		}
	} catch (const std::ios_base::failure& e) {
		if (!file.eof())
			throw std::runtime_error("failure reading file");
	}

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) :
	q(other.q) { }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this == &other)
		return (*this);

	q = other.q;

	return (*this);
}

BitcoinExchange::~BitcoinExchange() { }


// ----- Private Methods -----
pair	BitcoinExchange::makePair(std::string& line)
{

}
