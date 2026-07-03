#include <iostream>
#include <cstring>
#include <fstream>
#include <iterator>

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Error: Usage -> ./btc <input_file>" << std::endl;
		return (1);
	}

	const std::string	databaseName("data.csv");
	const std::string	requestFileName(argv[1]);

	std::ifstream		database;
	std::ifstream		requestFile;

	errno = 0;

	database.open(databaseName.c_str());
	if (!database.is_open()) {
		std::cerr << "Error: Could not open data.csv: " << std::strerror(errno) << std::endl;
		return (1);
	}

	requestFile.open(requestFileName.c_str());
	if (!requestFile.is_open()) {
		std::cerr << "Error: Could not open " + requestFileName << ": " << std::strerror(errno) << std::endl;
		return (1);
	}

	try {
		BitcoinExchange	mainDatabase(database);

		mainDatabase.checkInput(requestFile);
	} catch (const std::exception& e) {

		std::cerr << "Error: " << e.what() << "\n";
		return (1);
	}
}
