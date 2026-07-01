#pragma once

#include <fstream>
#include <string>
#include <map>
#include <utility>

class BitcoinExchange {
public:
	BitcoinExchange(std::ifstream& file);
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

private:
	std::map<std::string, std::string>	m;
	std::string							delim;
};
