#pragma once

#include <string>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm{

public:
	RobotomyRequestForm(const std::string& t);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	virtual void	execute(Bureaucrat const & executor) const;

private:
	static const int	gtSignRobotomy;
	static const int	gtExecRobotomy;
	std::string			target;
};
