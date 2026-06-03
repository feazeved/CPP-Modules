#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &n) :
	ClapTrap(n)
{
	hp = 100;
	ep = 50;
	ad = 20;
	std::cout << "[ScavTrap] Default Constructor called with name " << name << "!\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) :
    ClapTrap(other)
{
    std::cout << "[ScavTrap] Copy constructed another " << name << "!\n";
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
    if (this == &other)
		return (*this);
    ClapTrap::operator=(other);
	std::cout << "[ScavTrap] Assigned constructed with name " << other.name << "!\n";
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap] " << name << " Got destroyed!\n";
}

void	ScavTrap::guardGate()
{
	std::cout << "[ScavTrap] " << name << " is now in guard mode.\n";
}

void	ScavTrap::attack(const std::string& target)
{
    if (hp <= 0)
        return ;
    else if (ep <= 0)
    {
        std::cout << "[ScavTrap] " << name << " cannot do this\n";
    }

    std::cout << "[ScavTrap] " << name
              << " attacks " << target
              << " causing " << ad
              << " points of damage!\n";
    ep -= 1;
}
