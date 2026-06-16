#pragma once

#include <string>

#include "AForm.hpp"

class Intern {

public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	AForm*	makeForm(const std::string& name, const std::string& target) const;

	class InvalidFormException : public std::exception {
		public:
			const char* what() const throw();
	};

private:
	static size_t	numForms;
	static AForm*	makeShrubbery(std::string const & target);
	static AForm*	makeRobotomy(std::string const & target);
	static AForm*	makePresidential(std::string const & target);
};
