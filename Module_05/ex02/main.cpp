#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main()
{
	Bureaucrat*	buro = NULL;
	AForm*		form = NULL;

	std::cout << "\n-----Testing Shrubbery-----\n\n";
	try {
		buro = new Bureaucrat("Buro", 10);
		form = new ShrubberyCreationForm("arara");

		std::cout << *buro << "\n";
		buro->signForm(*form);

		std::cout << "\n";
		std::cout << *form;
		buro->executeForm(*form);

	} catch (std::exception& e) {

		std::cerr << "Error: " << e.what() << "\n";
	}
	delete buro, delete form;
	buro = NULL, form = NULL;

	std::cout << "\n\n-----Testing Robotomy-----\n\n";

	try {
		buro = new Bureaucrat("Crat", 10);
		form = new RobotomyRequestForm("Neymar");

		std::cout << *buro << "\n";
		std::cout << *form << "\n";

		buro->signForm(*form);
		buro->executeForm(*form);

	} catch (std::exception& e) {

		std::cerr << "Error: " << e.what() << "\n";
	}
	delete buro, delete form;
	buro = NULL, form = NULL;

	std::cout << "\n\n-----Testing Presidential-----\n\n";

	try {
		buro = new Bureaucrat("Zaphod Beeblebrox", 5);
		form = new PresidentialPardonForm("Neymar");

		std::cout << *buro << "\n";
		std::cout << *form << "\n";

		buro->signForm(*form);
		std::cout << "\n";

		buro->executeForm(*form);

	} catch (std::exception& e) {

		std::cerr << "Error: " << e.what() << "\n";
	}

	delete buro, delete form;

	std::cout << std::endl;
	return (0);
}
