#include <exception>
#include <ostream>
#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

const int	Bureaucrat::max_grade = 1;
const int	Bureaucrat::min_grade = 150;

// ORTHODOX CANONICAL IMPLEMENTATION
Bureaucrat::Bureaucrat(const std::string& n, int g) :
	name(n), grade(g)
{
	if (grade < max_grade)
		throw Bureaucrat::GradeTooHighException(name);
	else if (grade > min_grade)
		throw Bureaucrat::GradeTooLowException(name);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :
	name(other.name), grade(other.grade) { }

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this == &other)
		return (*this);

	grade = other.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() { }

// GETTERS
const std::string	Bureaucrat::getName() const { return(name); }
int					Bureaucrat::getGrade() const { return(grade); }

// PUBLIC METHODS
void				Bureaucrat::incrementGrade()
{
	if (grade == max_grade)
		throw GradeTooHighException(name);
	grade -= 1;
}

void				Bureaucrat::decrementGrade()
{
	if (grade == min_grade)
		throw GradeTooLowException(name);
	grade += 1;
}

void				Bureaucrat::signForm(Form& form) const
{
	try {
		form.Form::beSigned(*this);

		std::cout << name << " signed " << form.getName() << "\n";

	} catch (const std::exception& e) {
		std::cerr << name << " couldn't sign " << form.getName() << " because ";
		std::cerr << e.what() << "\n";
	}
}

// CUSTOM EXCEPTION CLASSES
// too high exception
Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& name) :
	message(name + "'s grade is too high!") { }

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return (message.c_str());
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() { }

// too low exception
Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& name) :
	message(name + "'s grade is too low!") { }

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return (message.c_str());
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() { }

// OVERLOAD TO PRINT INFO
std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << "\n";
	return (os);
}
