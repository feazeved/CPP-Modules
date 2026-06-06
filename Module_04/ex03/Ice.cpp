#include <iostream>

#include "Ice.hpp"
#include "AMateria.hpp"

Ice::Ice() :
	AMateria("ice")
{
	std::cout << "[Ice] DEFAULT constructor called!\n";
}

Ice::Ice(const Ice& other) :
	AMateria(other)
{
	std::cout << "[Ice] COPY constructor called!\n";
}

Ice& Ice::operator=(const Ice& other)
{
	std::cout << "[Ice] ASSIGNMENT copy constructor called!\n";
	if (this == &other)
		return (*this);

	AMateria::operator=(other);

	return (*this);
}

Ice::~Ice()
{
	std::cout << "[Ice] DESTRUCTOR called!\n";
}

AMateria*	Ice::clone() const
{
	return (new Ice());
}

void		Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
