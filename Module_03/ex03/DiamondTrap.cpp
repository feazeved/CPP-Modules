#include <iostream>

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& n) :
	ClapTrap(n), FragTrap(n), ScavTrap(n), name(n)
{
	ClapTrap::name = n + "_clap_name";
	hp = 100;
	ep = 50;
	ad = 30;
	std::cout << "[DiamondTrap] Default constructor called with name " << name << "\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) :
	ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	name = other.name;
	ClapTrap::name = other.ClapTrap::name;
	std::cout << "[DiamondTrap] Copy constructed another " << name << "!\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "[DiamondTrap] Assigned constructed another " << other.name << "!\n";
	if (this == &other)
		return (*this);
	name = other.name;
	ClapTrap::name = other.ClapTrap::name;
	hp = other.hp;
	ep = other.ep;
	ad = other.ad;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "[DiamondTrap] " << name << " got destroyed!\n";
}

void	DiamondTrap::whoAmI()
{
	std::cout << "[DiamondTrap] My name is '" << name << "' and my clap's name is '" << ClapTrap::name << "'!\n";
}
