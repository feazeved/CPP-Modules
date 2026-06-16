#pragma once

#include <string>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

public:
	ShrubberyCreationForm(const std::string& t);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

	virtual void	execute(Bureaucrat const & executor) const;


private:
	static const int	gtSignShrubbery;
	static const int	gtExecShrubbery;
	std::string			target;

};
