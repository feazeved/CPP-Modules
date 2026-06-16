#include <cstdio>
#include <fstream>

#include "ShrubberyCreationForm.hpp"

const int	ShrubberyCreationForm::gtSignShrubbery = 145;
const int	ShrubberyCreationForm::gtExecShrubbery = 137;

// ORTHODOX CANONICAL IMPLEMENTATION
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& t) :
	AForm("Shrubbery Creation", gtSignShrubbery, gtExecShrubbery), target(t + "_shrubbery") { }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
	AForm(other), target(other.target) { }

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this == &other)
		return (*this);

	AForm::operator=(other);
	target = other.target;

	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() { }

// PUBLIC METHODS
void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	AForm::beExecuted(executor);


	std::ofstream	file;

	file.open(target);

	if (!file.is_open())
		perror(("Error opening file " + target).c_str());

	file << "   ^\n"
		 << "  $$$\n"
		 << " $$$$$\n"
		 << "$$$$$$$\n"
		 << "   ||\n";

	if (file.bad())
		perror(("Error writing to file" + target).c_str());

	file.close();
}
