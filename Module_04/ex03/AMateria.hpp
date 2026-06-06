#pragma once

#include <string>

#include "ICharacter.hpp"

class ICharacter;

class AMateria {
public:
	AMateria(std::string const & type);
	AMateria(const AMateria& other);
	AMateria& operator=(const AMateria& other);
	virtual ~AMateria();

	std::string	const & getType() const;
	void	setType(std::string type);

	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);
protected:
	std::string	type;
};
