#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() :
	ClapTrap()
{
	std::cout << "[ScavTrap] Shouldn't call constructor without name. Name is set to \"default\".\n";
}

ScavTrap::ScavTrap(const std::string &n) :
	ClapTrap(n)
{
	std::cout << "[ScavTrap] Default Constructor called with name " << name << "!\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) :
    ClapTrap(other)
{
    std::cout << "[ScavTrap] Copy constructed another " << name << "!\n";
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "[ScavTrap] Assigned constructed another " << other.name << "!\n";
	if (this == &other)
		return (*this);
	ClapTrap::operator=(other);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap] " << name << " got destroyed!\n";
}

void	ScavTrap::guardGate()
{
	std::cout << "[ScavTrap] " << name << " is now in guard mode.\n";
}

void	ScavTrap::attack(const std::string& target)
{
	if (!ClapTrap::isFit(1))
	{
		std::cout << "[ScavTrap] " << name << " cannot do this\n";
		return ;
	}

    std::cout << "[ScavTrap] " << name
              << " attacks " << target 
              << " causing " << ad 
              << " points of damage!\n";
    ep -= 1;
}

