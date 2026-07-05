#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>
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
	std::ifstream		inputFile;

	database.open(databaseName.c_str());
	if (!database.is_open()) {
		std::cerr << "Error: Could not open data.csv" << std::endl;
		return (EXIT_FAILURE);
	}

	inputFile.open(argv[1]);
	if (!inputFile.is_open()) {
		std::cerr << "Error: Could not open " << argv[1] << std::endl;
		return (EXIT_FAILURE);
	}

	try {
		BitcoinExchange	mainDatabase;
		std::string		line;

		mainDatabase.loadDB(database);
		while (std::getline(inputFile, line)) {
			if (line.empty())
				continue ;
			mainDatabase.checkPrice(line);
		}
		if (inputFile.bad())
			throw std::runtime_error("I/O error occured");

	} catch (const std::exception& e) {

		std::cerr << "Error: " << e.what() << "\n";
		return (EXIT_FAILURE);
	}
}
