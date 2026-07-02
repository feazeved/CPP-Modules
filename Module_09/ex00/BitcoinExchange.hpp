#pragma once

#include <fstream>
#include <string>
#include <queue>
#include <utility>

typedef	std::pair<std::string, std::string>		pair;

class BitcoinExchange {
public:
	BitcoinExchange(std::ifstream& file);
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();


private:
	std::queue<pair>	q;
	std::string			delim;

	static pair	makePair(std::string& line);
};
