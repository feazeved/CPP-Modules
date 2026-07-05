#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <utility>

class BitcoinExchange {
public:
	BitcoinExchange();
	BitcoinExchange(std::ifstream& file);
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void	loadDB(std::ifstream& file);
	void	checkPrice(std::string& input) const;


private:
	std::map<std::string, std::string>	m;

	typedef std::pair<std::string, std::string>	pair;

	static void	trimLine(std::string& line);

	static bool	makePair(std::string& line, pair& columns, char delim); //     -> Function to create pair values in map m.
	static void	makeDate(std::stringstream& row, pair& columns, char delim);
	static void	makeValue(std::stringstream& row, pair& columns);
	static char	parseHeader(std::string& line);
};

bool	operator!(const std::pair<std::string, std::string>& pair);
