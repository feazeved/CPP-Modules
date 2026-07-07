#include <cstdlib>
#include <iostream>
#include <string>
#include <exception>

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Error\n";
		return (EXIT_FAILURE);
	}

	const std::string	validTokens("0123456789 +-/*");

	std::string	arg(argv[1]);
	if (arg.find_first_not_of(validTokens) != std::string::npos) {
		std::cerr << "Error\n";
		return (EXIT_FAILURE);
	}

	try {
		RPN	rpn;

		rpn.calcExpr(arg);

	} catch (const std::exception& e) {

		std::cerr << "Error\n";
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
