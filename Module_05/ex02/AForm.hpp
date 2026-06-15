#pragma once

#include <ostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
public:
	AForm(const std::string& n, const int gts, const int gte);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	std::string			getName() const;
	int					getGrade_to_sign() const;
	int					getGrade_to_exec() const;
	bool				getIs_signed() const;

	void				beSigned(const Bureaucrat& b);
	void				beExecuted(Bureaucrat const & executor);
	virtual void		execute(Bureaucrat const & executor) const = 0;

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

std::ostream&	operator<<(std::ostream& os, const AForm& f);
