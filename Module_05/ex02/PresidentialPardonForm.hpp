#pragma once

#include <string>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm{

public:
	PresidentialPardonForm(const std::string& t);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	~PresidentialPardonForm();

	virtual void	execute(Bureaucrat const & executor) const;

private:
	static const int	gtSignPresidential;
	static const int	gtExecPresidential;
	std::string			target;
};
