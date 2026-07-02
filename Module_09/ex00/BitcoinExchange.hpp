#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <utility>

class BitcoinExchange {
public:
	BitcoinExchange(std::ifstream& file);
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	const std::map<std::string, std::string>&	getMap() const;

	void	checkInput(std::ifstream& file) const;


private:
	std::map<std::string, std::string>	m;

	typedef std::pair<std::string, std::string>	pair;

	static pair	makePair(std::string& line, char delim); //     -> Function to create pair values in map m.
	static char	parseHeader(std::string& line); //				-> Function to parse the first line of a .csv file
};
