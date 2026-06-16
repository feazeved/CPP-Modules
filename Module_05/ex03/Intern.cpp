#include <string>

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// STATIC FUNCTIONS
size_t	Intern::numForms = 3;
AForm*	Intern::makeShrubbery(std::string const & t) { return (new ShrubberyCreationForm(t)); }
AForm*	Intern::makeRobotomy(std::string const & t) { return (new RobotomyRequestForm(t)); }
AForm*	Intern::makePresidential(std::string const & t) { return (new PresidentialPardonForm(t)); }

// CANONICAL CLASS IMPLEMENTATION
Intern::Intern() { }

Intern::Intern(const Intern& other) { (void)other; }

Intern& Intern::operator=(const Intern& other) { (void)other; return (*this); }

Intern::~Intern() { }

AForm* Intern::makeForm(const std::string& name, const std::string& target) const
{
	typedef	AForm*(*fptr)(const std::string&);

	const fptr			ptr[3] = {&Intern::makeShrubbery, &Intern::makeRobotomy, &Intern::makePresidential};

	const	std::string	functions[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (size_t i = 0; i < numForms; i++)
		if (functions[i] == name)
			return (ptr[i](target));

	throw Intern::InvalidFormException();
}

const char* Intern::InvalidFormException::what() const throw()
{
	return ("there is no form with this name!");
}
