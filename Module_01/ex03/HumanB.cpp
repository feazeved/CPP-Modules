#include <iostream>
#include <string>

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(const std::string &n)
    : name(n)
{
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
    std::cout << this->name << " attacks with their " << weapon->getType() << "\n";
}
