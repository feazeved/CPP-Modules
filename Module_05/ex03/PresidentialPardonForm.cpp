#include <iostream>

#include "PresidentialPardonForm.hpp"

const int	PresidentialPardonForm::gtSignPresidential = 25;
const int	PresidentialPardonForm::gtExecPresidential = 5;

// ORTHODOX CANONICAL IMPLEMENTATION
PresidentialPardonForm::PresidentialPardonForm(const std::string& t) :
	AForm("presidential pardon", gtSignPresidential, gtExecPresidential), target(t) { }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
	AForm(other), target(other.target) { }

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this == &other)
		return (*this);

	AForm::operator=(other);
	target = other.target;

	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() { }

// PUBLIC METHODS
void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	AForm::beExecuted(executor);

	std::cout << target << " has been pardoned by Zaphod Beeblebrox\n";
}
