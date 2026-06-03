#include <iostream>

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& n) :
    ClapTrap(n)
{
	hp = 100;
    ep = 100;
    ad = 30;
    std::cout << "[FragTrap] Default Constructor called with name " << name << "!\n";
}

FragTrap::FragTrap(const FragTrap& other) :
    ClapTrap(other)
{
    std::cout << "[FragTrap] Copy constructed another " << name << "!\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "[FragTrap] Assigned constructed another " << other.name << "!\n";
    if (this == &other)
        return (*this);
    ClapTrap::operator=(other);
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "[FragTrap] " << name << " got destroyed!\n";
}

void  FragTrap::highFivesGuys()
{
    std::cout << "[FragTrap] " << name << " requests a positive high five!\n";
}
