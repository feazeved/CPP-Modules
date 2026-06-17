#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat*	Wallace = NULL;
	Bureaucrat*	Jenna = NULL;
	std::cout << "\n-----Testing exception at creation-----\n\n";
	try {
		Wallace = new Bureaucrat("Wallace", 3); // NEW
		Bureaucrat	Afonso("Afonso", 0);

	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << "\n";
	}
	try {
		Jenna = new Bureaucrat("Jenna", 150); // NEW
		Bureaucrat	Bia("Bia", 151);

	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << "\n";
	}

	std::cout << "\n";
	std::cout << Wallace->getName() << " and " << Jenna->getName() << " are alloc'd\n\n";

	std::cout << *Jenna;
	std::cout << *Wallace;


	std::cout << "\n-----Testing increment / decrement-----\n\n";

	try {
		Wallace->incrementGrade();
		std::cout << *Wallace;

		Wallace->incrementGrade();
		Wallace->incrementGrade();

	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << "\n";
	}

	std::cout << "\n";

	try {
		Jenna->incrementGrade();
		std::cout << *Jenna;

		Jenna->decrementGrade();

	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << "\n";
	}

	std::cout << std::endl;

	delete Jenna, delete Wallace;

	return (0);
}
