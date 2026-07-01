#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::ifstream& file)
{

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
