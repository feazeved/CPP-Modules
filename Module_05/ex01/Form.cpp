#include "Form.hpp"
#include "Bureaucrat.hpp"

const int	Form::max_grade = 1;
const int	Form::min_grade = 150;

// ORTHODOX CANONICAL IMPLEMENTATION
Form::Form(const std::string& n, const int gts, const int gte) :
	name(n), grade_to_sign(gts), grade_to_exec(gte), is_signed(false)
{
	if (grade_to_sign < max_grade || grade_to_exec < max_grade)
		throw Form::GradeTooHighException(name + "'s grade is too high!");

	else if (grade_to_sign > min_grade || grade_to_exec > min_grade)
		throw Form::GradeTooLowException(name + "'s grade is too low!");
}

Form::Form(const Form& other) :
	name(other.name), grade_to_sign(other.grade_to_sign), grade_to_exec(other.grade_to_exec), is_signed(other.is_signed) { }

Form&	Form::operator=(const Form& other)
{
	if (this == &other)
		return (*this);

	is_signed = other.is_signed;
	return (*this);
}

Form::~Form() { }

// GETTERS
std::string	Form::getName() const { return (name); }
int			Form::getGrade_to_sign() const { return (grade_to_sign); }
int			Form::getGrade_to_exec() const { return (grade_to_exec); }
bool		Form::getIs_signed() const { return (is_signed); }

// PUBLIC METHODS
void		Form::beSigned(const Bureaucrat& b)
{
	if (is_signed == true)
		throw Form::AlreadySignedException();

	if (b.getGrade() > grade_to_sign)
		throw Form::GradeTooLowException(b.getName() + "'s grade is too low!");
	is_signed = true;
}

// CUSTOM EXCEPTION CLASSES
// too high exception
Form::GradeTooHighException::GradeTooHighException(const std::string& message) :
	message(message) { }

const char* Form::GradeTooHighException::what() const throw()
{
	return (message.c_str());
}

Form::GradeTooHighException::~GradeTooHighException() throw() { }

// too low exception
Form::GradeTooLowException::GradeTooLowException(const std::string& message) :
	message(message) { }

const char*	Form::GradeTooLowException::what() const throw()
{
	return (message.c_str());
}

Form::GradeTooLowException::~GradeTooLowException() throw() { }

const char*	Form::AlreadySignedException::what() const throw()
{
	return ("this form is already signed!");
}

// OVERLOAD TO PRINT INFO
std::ostream&	operator<<(std::ostream& os, const Form& f)
{
	os << f.getName() << ": " << (f.getIs_signed() ? "is signed" : "is not signed") << "\n"
							  << "  Grade to sign: " << f.getGrade_to_sign() << "\n"
							  << "  Grade to exec: " << f.getGrade_to_exec() << "\n";
	return (os);
}
