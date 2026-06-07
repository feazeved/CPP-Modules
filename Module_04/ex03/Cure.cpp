#include <iostream>

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() :
	AMateria("cure")
{
}

Cure::Cure(const Cure& other) :
	AMateria(other)
{
}

Cure& Cure::operator=(const Cure& other)
{
	if (this == &other)
		return (*this);

	AMateria::operator=(other);

	return (*this);
}

Cure::~Cure()
{
}

AMateria*	Cure::clone() const
{
	return (new Cure());
}

void		Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
