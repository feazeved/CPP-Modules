#include <cstddef>

#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
	for (size_t i = 0; i < 4; i++) inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (size_t i = 0; i < 4; i++) {
		inventory[i] = NULL;
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this == &other)
		return (*this);

	for (size_t i = 0; i < 4; i++) {
		if (inventory[i])
			delete inventory[i];
		inventory[i] = NULL;
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
		delete inventory[i];
}

void		MateriaSource::learnMateria(AMateria* mat)
{
	if (!mat)
		return ;

	for (size_t i = 0; i < 4; i++) {
		if (!inventory[i])
		{
			inventory[i] = mat;
			return ;
		}
	}
	delete mat;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (inventory[i] && inventory[i]->getType() == type)
			return (inventory[i]->clone());
	}
	return (0);
}
