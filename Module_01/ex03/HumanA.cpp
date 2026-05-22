#include <iostream>
#include <string>

#include "HumanA.hpp"

HumanA::HumanA(const std::string &n, Weapon &w)
    : weapon(w), name(n)
{
}


void  HumanA::attack(void)
{
    std::cout << this->name << " attacks with their " << weapon.getType() << "\n";
}
