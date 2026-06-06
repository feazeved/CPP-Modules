#pragma once

#include <string>

#include "ICharacter.hpp"

class AMateria;

class Character : public ICharacter {
	public:
	Character(const std::string& n);
	Character(const Character& other);
	Character& operator=(const Character& other);
	virtual ~Character();

	virtual const std::string&	getName() const;
	void						setName(std::string name);

	virtual void				equip(AMateria* m);
	virtual void				unequip(int idx);
	virtual void				use(int idx, ICharacter& target);

private:
	std::string	name;
	AMateria*	inventory[4];
};
