#pragma once

#include <ostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:
	Form(const std::string& n, const int gts, const int gte);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	std::string			getName() const;
	int					getGrade_to_sign() const;
	int					getGrade_to_exec() const;
	bool				getIs_signed() const;

	void				beSigned(const Bureaucrat& b);

private:
	const std::string	name;
	const int			grade_to_sign;
	const int			grade_to_exec;
	bool				is_signed;


public:
	class GradeTooHighException : public std::exception {
		public:
			GradeTooHighException(const std::string& name);
			virtual const char* what() const throw();
			virtual ~GradeTooHighException() throw();

		private:
			std::string	message;
	};

	class GradeTooLowException : public std::exception {
		public:
			GradeTooLowException(const std::string& name);
			virtual const char* what() const throw();
			virtual ~GradeTooLowException() throw();

		private:
			std::string message;
	};
};

std::ostream&	operator<<(std::ostream& os, const Form& f);
