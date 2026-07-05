#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Error: Usage -> ./btc <input_file>" << std::endl;
		return (EXIT_FAILURE);
	}

	const std::string	databaseName("data.csv");

	std::ifstream		database;
	std::ifstream		requestFile;

	database.open(databaseName.c_str());
	if (!database.is_open()) {
		std::cerr << "Error: Could not open data.csv" << std::endl;
		return (EXIT_FAILURE);
	}

	requestFile.open(argv[1]);
	if (!requestFile.is_open()) {
		std::cerr << "Error: Could not open " << argv[1] << std::endl;
		return (EXIT_FAILURE);
	}

	try {
		BitcoinExchange	mainDatabase;

		mainDatabase.checkInput(requestFile);
	} catch (const std::exception& e) {

		std::cerr << "Error: " << e.what() << "\n";
		return (EXIT_FAILURE);
	}
}
