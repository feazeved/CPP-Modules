#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"

int	main()
{
	std::cout << "\n-----Testing increment throw-----\n\n";
	try {
		Bureaucrat	Afonso("Afonso", 3);
		Bureaucrat	Bia("Bia" , 2);

		Afonso.incrementGrade();
		Afonso.incrementGrade();
		std::cout << Afonso;

		Bia.incrementGrade();
		Bia.incrementGrade();
		std::cout << Bia;

	} catch (std::exception& e) {

		std::cerr << "Error: " << e.what() << "\n";
	}

	std::cout << "\n-----Testing COPY and ASSIGN-----\n\n";

	try {
		Bureaucrat	Main("Main", 149);
		Bureaucrat	Copy(Main);
		Bureaucrat	Assign("Assign", 10);

		Main.decrementGrade();

		Assign = Main;
		std::cout << Main;
		std::cout << Copy;
		std::cout << Assign;

		Assign.decrementGrade();
	} catch (const std::exception& e) {

		std::cerr << "Error: " << e.what() << "\n";
	}

	std::cout << std::endl;
	return (0);
}
