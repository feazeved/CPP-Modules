#include <iostream>

#include "FragTrap.hpp"

FragTrap::FragTrap() :
    ClapTrap()
{
    std::cout << "[FragTrap] Shouldn't call constructor without name. Name is set to \"default\".\n";
}

FragTrap::FragTrap(const std::string& n) :
    ClapTrap(n)
{
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
    std::cout << "[FragTrap] " << name << " requests a high five!\n";
}

