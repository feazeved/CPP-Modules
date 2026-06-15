#pragma once

#include <exception>
#include <ostream>
#include <string>

#include "AForm.hpp"

class AForm;

class Bureaucrat {
public:
	Bureaucrat(const std::string& n, int g);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	const std::string	getName() const;
	int					getGrade() const;

	void				incrementGrade();
	void				decrementGrade();
	void				signForm(AForm& form) const;

private:
	static const int	max_grade;
	static const int	min_grade;
	const std::string	name;
	int					grade;


public:
	class GradeTooHighException : public std::exception {
		public:
			GradeTooHighException(const std::string& message);
			virtual const char* what() const throw();
			virtual ~GradeTooHighException() throw();

		private:
			std::string	message;
	};

	class GradeTooLowException : public std::exception {
		public:
			GradeTooLowException(const std::string& message);
			virtual const char* what() const throw();
			virtual ~GradeTooLowException() throw();

		private:
			std::string message;
	};
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b);
