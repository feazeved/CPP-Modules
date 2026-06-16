#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main()
{
	Intern	intern;
	Bureaucrat	eu("Felipe", 1);
	AForm*	rrf = NULL;

	try {
		rrf = intern.makeForm("robotomy request", "Wallace");

		eu.signForm(*rrf);
		eu.executeForm(*rrf);
	} catch (std::exception& e) {


	}
	return (0);
}
