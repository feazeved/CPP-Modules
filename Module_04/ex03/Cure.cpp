#include <iostream>

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() :
	AMateria("cure")
{
	std::cout << "[Cure] DEFAULT constructor called!\n";
}

Cure::Cure(const Cure& other) :
	AMateria("cure")
{
	std::cout << "[Cure] COPY constructor called!\n";
}

Cure& Cure::operator=(const Cure& other)
{
	std::cout << "[Cure] ASSIGNMENT copy constructor called!\n";
	if (this == &other)
		return (*this);

	AMateria::operator=(other);

	return (*this);
}

Cure::~Cure()
{
	std::cout << "[Cure] DESTRUCTOR called!\n";
}

AMateria*	Cure::clone() const
{
	return (new Cure());
}

void		Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
