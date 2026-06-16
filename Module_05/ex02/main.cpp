



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

	try {
		buro = new Bureaucrat("Buro", 10);
		form = new ShrubberyCreationForm("arara");

		std::cout << *buro;
		buro->signForm(*form);

		std::cout << *form;
		buro->executeForm(*form);

	} catch (std::exception& e) {

		std::cerr << "Error: " << e.what() << "\n";
	}
	delete buro, delete form;
	buro = NULL, form = NULL;


	try {
		buro = new Bureaucrat("Crat", 10);
		form = new RobotomyRequestForm("Neymar");

		std::cout << *buro;
		std::cout << *form;

		buro->signForm(*form);
		buro->executeForm(*form);

	} catch (std::exception& e) {

		std::cerr << "Error: " << e.what() << "\n";
	}
	delete buro, delete form;
	buro = NULL, form = NULL;


	try {
		buro = new Bureaucrat("Zaphod Beeblebrox", 5);
		form = new PresidentialPardonForm("Neymar");

		std::cout << *buro;
		std::cout << *form;

		buro->signForm(*form);
		buro->executeForm(*form);

	} catch (std::exception& e) {

		std::cerr << "Error: " << e.what() << "\n";
	}

	delete buro, delete form;

	return (0);
}
