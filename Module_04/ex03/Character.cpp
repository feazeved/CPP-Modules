#include <cstddef>
#include <new>

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(const std::string& n) :
	name(n), floorCount(0)
{
	for (size_t i = 0; i < 4; i++) inventory[i] = NULL;
	for (size_t i = 0; i < 100; i++) floor[i] = NULL;
}

Character::Character(const Character& other) :
	name(other.name), floorCount(0)
{
	for (size_t i = 0; i < 100; i++) floor[i] = NULL;

	for (size_t i = 0; i < 4; i++) {
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character& other)
{
	if (this == &other)
		return (*this);
	name = other.name;

	for (size_t i = 0; i < 4; i++) {
		if (inventory[i])
		{
			delete inventory[i];
			inventory[i] = NULL;
		}
	}

	for (size_t i = 0; i < floorCount; i++) {
		if (floor[i])
		{
			delete floor[i];
			floor[i] = NULL;
		}
	}
	floorCount = 0;

	for (size_t i = 0; i < 4; i++){
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
	return (*this);
}

Character::~Character()
{
	for (size_t i = 0; i < 4; i++) delete inventory[i];
	for (size_t i = 0; i < floorCount; i++) delete floor[i];
}

const std::string&	Character::getName() const { return (name); }
void				Character::setName(std::string name) { this->name = name; }


void		Character::equip(AMateria* m)
{
	if (!m)
		return ;

	for (size_t i = 0; i < 4; i++) {
		if (!inventory[i])
		{
			inventory[i] = m;
			return ;
		}
	}
	delete m;
}

void		Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || !inventory[idx])
		return ;

	if (floorCount < 100)
	{
		floor[floorCount] = inventory[idx];
		floorCount++;
	}

	inventory[idx] = NULL;
}

void		Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || !inventory[idx])
		return ;

	inventory[idx]->use(target);
}
