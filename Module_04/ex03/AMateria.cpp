#include <iostream>

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) :
	type(type)
{
}

AMateria::AMateria(const AMateria& other) :
	type(other.type)
{
}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this == &other)
		return (*this);
	return (*this);
}

AMateria::~AMateria()
{
}

std::string	const & AMateria::getType() const { return (type); }
void	AMateria::setType(std::string type) { this->type = type; }


void	AMateria::use(ICharacter& target)
{
	std::cout << "* uses A Materia at " << target.getName() << " *\n";
}
