#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() :
	ClapTrap()
{
	std::cout << "[ScavTrap] Default constructor shouldn't be called. Name is set to \"default\".\n";
}

ScavTrap::ScavTrap(const std::string &n) :
	ClapTrap(n)
{
	std::cout << "[ScavTrap] Constructor called!\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "[ScavTrap] Copy constructor called!\n";
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "[ScavTrap] Assignment constructor called!\n";
	if (this == &other)
		return (*this);
	ClapTrap::operator=(other);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap] Got destroyed!\n";
}

void	ScavTrap::guardGate()
{
	std::cout << "[ScavTrap] Is now in guard mode.\n";
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