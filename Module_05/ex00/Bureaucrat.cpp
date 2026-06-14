#include "Bureaucrat.hpp"
#include <ostream>
#include <string>

Bureaucrat::Bureaucrat(const std::string& n, int g) :
	name(n), grade(g)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException(name);
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException(name);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :
	name(other.name), grade(other.grade) { }

// Only copy the grade since name is constant!
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this == &other)
		return (*this);

	grade = other.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() { }

const std::string	Bureaucrat::getName() const { return(name); }
int					Bureaucrat::getGrade() const { return(grade); }

void				Bureaucrat::incrementGrade()
{
	grade -= 1;
	if (grade < 1)
		throw GradeTooHighException(name);
}

void				Bureaucrat::decrementGrade()
{
	grade += 1;
	if (grade > 150)
		throw GradeTooLowException(name);
}


Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& name) :
	message(name + "'s grade is too high!") { }

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return (message.c_str());
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() { }

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& name) :
	message(name + "'s grade is too high!") { }

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return (message.c_str());
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() { }

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << "\n";
	return (os);
}
