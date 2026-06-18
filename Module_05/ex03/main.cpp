#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main()
{
	Intern	intern;
	Bureaucrat	eu("Felipe", 1);
	AForm*	creator = NULL;

	std::cout << "\n\n-----Testing Intern-----\n\n";
	try {
		creator = intern.makeForm("robotomy request", "Wallace");

		eu.signForm(*creator);
		eu.executeForm(*creator);
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << "\n";

	}

	delete creator;

	std::cout << std::endl;
	return (0);
}
