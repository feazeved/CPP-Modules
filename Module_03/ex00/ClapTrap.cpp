#include <iostream>

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
	name(), hp(10), ep(10), ad(10)
{
	std::cout << ""
}

ClapTrap::ClapTrap(const std::string &n) :
	name(n), hp(10), ep(10), ad(10)
{
}

ClapTrap::ClapTrap(const ClapTrap& other) :
	name(other.name), hp(other.hp), ep(other.ep), ad(other.ad)
{
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this == &other)
		return (*this);
	this->hp = other.hp;
	this->ep = other.ep;
	this->ad = other.ad;
}

ClapTrap::~ClapTrap()
{
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->ep < 1)
		return ;
	std::cout << "ClapTrap " << this->name 
			  << " attacks " << target 
			  << " causing " << this->ad 
			  << "points of damage!\n";
	ep -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{

}

void	ClapTrap::beRepaired(unsigned int amount)
{

}
