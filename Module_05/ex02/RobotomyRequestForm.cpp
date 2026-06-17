#include <iostream>
#include <cstdlib>

#include "RobotomyRequestForm.hpp"

const int	RobotomyRequestForm::gtSignRobotomy = 72;
const int	RobotomyRequestForm::gtExecRobotomy = 45;

// ORTHODOX CANONICAL IMPLEMENTATION
RobotomyRequestForm::RobotomyRequestForm(const std::string& t) :
	AForm("robotomy request", gtSignRobotomy, gtExecRobotomy), target(t) { }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
	AForm(other), target(other.target) { }

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this == &other)
		return (*this);

	AForm::operator=(other);
	target = other.target;

	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() { }

// PUBLIC METHODS
void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	AForm::beExecuted(executor);


	std::cout << "\nvruuuuuuuuuuuuuum\n"
			  << "robotomizing...\n\n";

	srand((unsigned) time(NULL));
	int	random = rand() % 2;

	if (random == 0)
		std::cout << target << " has been succesfully robotomized!\n";
	else
		std::cout << target << ", the robotomization failed...\n";
}
