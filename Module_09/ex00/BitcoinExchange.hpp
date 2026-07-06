#pragma once

#include <fstream>
#include <string>
#include <map>
#include <utility>

class BitcoinExchange {
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void	loadDB(std::ifstream& file);
	void	checkPrice(const std::string& input) const;

private:
	std::map<std::string, std::string>	m;
	typedef std::pair<std::string, std::string>	pair;

	static void	trimLine(std::string& line);
	static bool	makePair(const std::string& line, pair& columns, char delim, bool inputMode);
	static bool	makeDate(const std::string& date, std::string& mapKey);
	static bool	makeValue(const std::string& value, std::string& mapValue, bool inputMode);
};
