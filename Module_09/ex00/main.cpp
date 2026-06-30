#include <iostream>
#include <cstring>
#include <fstream>

#include "BitcoinExchange.hpp"

using std::cerr;
using std::endl;

int	main(int argc, char **argv)
{
	if (argc != 2) {
		cerr << "Error: Usage -> ./btc <input_file>" << endl;
		return (1);
	}

	const std::string	databaseName("data.csv");
	const std::string	requestFileName(argv[1]);

	std::ifstream		database;
	std::ifstream		requestFile;

	errno = 0;

	database.open(databaseName.c_str());
	if (!database.is_open()) {
		cerr << "Error: Could not open data.csv: " << std::strerror(errno) << endl;
		return (1);
	}

	requestFile.open(requestFileName.c_str());
	if (!requestFile.is_open()) {
		cerr << "Error: Could not open " + requestFileName << ": " << std::strerror(errno) << endl;
		return (1);
	}

	std::string	line;

	std::getline(requestFile, line);

	std::cout << line << "\n";

	// BitcoinExchange	mainDatabase(database);
	// BitcoinExchange	requestDatabase(requestFile);

}
