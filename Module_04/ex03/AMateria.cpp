#include <iostream>

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) :
	type(type)
{
	std::cout << "[AMateria] DEFAULT constructor called!\n";
}

AMateria::AMateria(const AMateria& other) :
	type(other.type)
{
	std::cout << "[AMateria] COPY constructor called!\n";
}

AMateria& AMateria::operator=(const AMateria& other)
{
	std::cout << "[AMateria] ASSIGNMENT copy constructor called!\n";
	if (this == &other)
		return (*this);
	type = other.type;

	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "[AMateria] DESTRUCTOR called!\n";
}

std::string	const & AMateria::getType() const { return (type); }
void	AMateria::setType(std::string type) { this->type = type; }


void	use(ICharacter& target)
{
	std::cout << "* uses A Materia at " << target.getName() << " *\n";
}
