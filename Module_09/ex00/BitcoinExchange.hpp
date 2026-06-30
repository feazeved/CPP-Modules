#pragma once

#include <fstream>
#include <string>
#include <map>

class BitcoinExchange {
public:
	BitcoinExchange(std::ifstream& file);
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

private:
	std::map<std::string, float>	m;
};
