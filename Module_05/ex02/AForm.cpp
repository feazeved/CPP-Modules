#include "AForm.hpp"
#include "Bureaucrat.hpp"

const int	AForm::max_grade = 1;
const int	AForm::min_grade = 150;

// ORTHODOX CANONICAL IMPLEMENTATION
AForm::AForm(const std::string& n, const int gts, const int gte) :
	name(n), grade_to_sign(gts), grade_to_exec(gte), is_signed(false)
{
	if (grade_to_sign < max_grade || grade_to_exec < max_grade)
		throw AForm::GradeTooHighException(name + "'s grade is too high!");

	else if (grade_to_sign > min_grade || grade_to_exec > min_grade)
		throw AForm::GradeTooLowException(name + "'s grade is too low!");
}

AForm::AForm(const AForm& other) :
	name(other.name), grade_to_sign(other.grade_to_sign), grade_to_exec(other.grade_to_exec), is_signed(other.is_signed) { }

AForm&	AForm::operator=(const AForm& other)
{
	if (this == &other)
		return (*this);

	is_signed = other.is_signed;
	return (*this);
}

AForm::~AForm() { }

// GETTERS
std::string	AForm::getName() const { return (name); }
int			AForm::getGrade_to_sign() const { return (grade_to_sign); }
int			AForm::getGrade_to_exec() const { return (grade_to_exec); }
bool		AForm::getIs_signed() const { return (is_signed); }

// PUBLIC METHODS
void		AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > grade_to_sign)
		throw AForm::GradeTooLowException(b.getName() + "'s grade is too low!");
	is_signed = true;
}

void		AForm::beExecuted(Bureaucrat const & executor) const
{
	if (executor.getGrade() > grade_to_exec)
		throw AForm::GradeTooLowException(executor.getName() + "'s grade is too low!");
	else if (!is_signed)
		throw AForm::InvalidFormException(executor.getName() + " cannot execute an unsigned form!");
}

// CUSTOM EXCEPTION CLASSES
// too high exception
AForm::GradeTooHighException::GradeTooHighException(const std::string& message) :
	message(message) { }

const char* AForm::GradeTooHighException::what() const throw()
{
	return (message.c_str());
}

AForm::GradeTooHighException::~GradeTooHighException() throw() { }

// too low exception
AForm::GradeTooLowException::GradeTooLowException(const std::string& message) :
	message(message) { }

const char*	AForm::GradeTooLowException::what() const throw()
{
	return (message.c_str());
}

AForm::GradeTooLowException::~GradeTooLowException() throw() { }

// form not signed trying to be executed
AForm::InvalidFormException::InvalidFormException(const std::string& message) :
	message(message) { }

const char* AForm::InvalidFormException::what() const throw()
{
	return (message.c_str());
}

AForm::InvalidFormException::~InvalidFormException() throw() { }

// OVERLOAD TO PRINT INFO
std::ostream&	operator<<(std::ostream& os, const AForm& f)
{
	os << f.getName() << ": " << (f.getIs_signed() ? "is signed" : "is not signed") << "\n"
							  << "  Grade to sign: " << f.getGrade_to_sign() << "\n"
							  << "  Grade to exec: " << f.getGrade_to_exec() << "\n";
	return (os);
}
