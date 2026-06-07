#pragma once

#include <string>

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
public:
	MateriaSource();
	MateriaSource(const MateriaSource& other);
	MateriaSource& operator=(const MateriaSource& other);
	virtual ~MateriaSource();

	virtual void		learnMateria(AMateria * mat);
	virtual AMateria*	createMateria(std::string const & type);

private:
	AMateria*	inventory[4];
};
