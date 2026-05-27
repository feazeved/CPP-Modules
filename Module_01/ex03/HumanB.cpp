#include <iostream>
#include <string>

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(const std::string &n)
    : weapon(0), name(n)
{
}

HumanB::HumanB(const std::string &n, Weapon& w) :
    name(n)
{
    weapon = &w;
}

void    HumanB::setWeapon(Weapon *new_weapon)
{
    this->weapon = new_weapon;
}

Weapon  *HumanB::getWeapon(void)
{
    return (this->weapon);
}

void    HumanB::attack(void)
{
	if (this->weapon)
    	std::cout << this->name << " attacks with their " << weapon->getType() << "\n";
	else
		std::cout << this->name << " attacks with their bare hands" << std::endl;
}
