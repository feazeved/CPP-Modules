#pragma once

#include <exception>
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
	static const int	max_grade;
	static const int	min_grade;
	const std::string	name;
	const int			grade_to_sign;
	const int			grade_to_exec;
	bool				is_signed;


public:
	class GradeTooHighException : public std::exception {
		public:
			GradeTooHighException(const std::string& name);
			virtual ~GradeTooHighException() throw();
			virtual const char* what() const throw();

		private:
			std::string	message;
	};

	class GradeTooLowException : public std::exception {
		public:
			GradeTooLowException(const std::string& name);
			virtual ~GradeTooLowException() throw();
			virtual const char* what() const throw();

		private:
			std::string message;
	};

	class AlreadySignedException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& os, const Form& f);
