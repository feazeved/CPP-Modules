#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "[MateriaSource] DEFAULT constructor called!\n";
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	std::cout << "[MateriaSource] COPY constructor called!\n";
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	std::cout << "[MateriaSource] ASSIGNMENT copy constructor called!\n";
	if (this == &other)
		return (*this);

	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "[MateriaSource] DESTRUCTOR called!\n";
}

void	learnMateria(AMateria* mat)
{
	
}

AMateria*	createMateria(std::string const & type)
{
	for (size_t i = 0; i < 4; i++)
	{
		
	}
	return ()
}