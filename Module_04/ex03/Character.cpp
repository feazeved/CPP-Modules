#include <cstddef>
#include <iostream>

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(const std::string& n) :
	name(n), inventory()
{
	std::cout << "[Character] DEFAULT constructor called with name " << name << "!\n";
}

Character::Character(const Character& other) :
	name(other.name)
{
	for (size_t i = 0; i < 4; i++) {
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}

	std::cout << "[Character] COPY constructed another " << name << "!\n";
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		name = other.name;

		for (size_t i = 0; i < 4; i++) {
			if (inventory[i])
			{
				delete inventory[i];
				inventory[i] = NULL;
			}
		}

		for (size_t i = 0; i < 4; i++){
			if (other.inventory[i])
				inventory[i] = other.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
	}

	std::cout << "[Character] ASSIGNMENT copy constructed another " << other.name << "!\n";
	return (*this);
}

Character::~Character()
{
	for (size_t i = 0; i < 4; i++)
		delete inventory[i];

	std::cout << "[Character] DESTRUCTOR called!\n";
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

	for (size_t i = 0; i < 4; i++){
		if (inventory[i] == m)
			return ;
	}

	delete m;
}

void		Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;

	if (inventory[idx])
		inventory[idx] = NULL;
}

void		Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return ;

	if (inventory[idx])
		inventory[idx]->use(target);
}
