#include <iostream>

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
	name("default"), hp(10), ep(10), ad(0)
{
    std::cout << "Default constructor shouldn't be called. Name is set to \"default\".\n";
}

ClapTrap::ClapTrap(const std::string &n) :
	name(n), hp(10), ep(10), ad(0)
{
    std::cout << "ClapTrap " << name << " is ready for use!\n";
}

ClapTrap::ClapTrap(const ClapTrap& other) :
	name(other.name), hp(other.hp), ep(other.ep), ad(other.ad)
{
    std::cout << "Copy constructed another " << name << "!\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this == &other)
        return (*this);
    this->name = other.name;
    this->hp = other.hp;
    this->ep = other.ep;
    this->ad = other.ad;
    
    std::cout << "Assigned constructed another " << name << "!\n";
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " got destroyed!\n";
}


std::string& ClapTrap::getName()
{
    return (name);
}

void         ClapTrap::setName(const std::string &n)
{
    name = n;
}

int          ClapTrap::getAd()
{
    return (ad);
}

void         ClapTrap::setAd(const int a)
{
    ad = a;
}

int          ClapTrap::getHp()
{
    return (hp);
}

bool  ClapTrap::isFit(const int& epCost)
{
    if (hp <= 0)
        return (false);
    if ((ep - epCost) < 0)
    {
        std::cout << "ClapTrap " << name << " don't have enough ep for this!\n";
        return (false);
    }
    return (true);
}

void	ClapTrap::attack(const std::string& target)
{
    if (!isFit(1))
		    return ;

    std::cout << "ClapTrap " << name
              << " attacks " << target 
              << " causing " << ad 
              << " points of damage!\n";
    ep -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
    if (!isFit(0))
        return ;
    std::cout << "ClapTrap " << name
              << " took " << amount
              << " of damage!\n";
    hp -= amount;
    if (hp <= 0)
        std::cout << "*ClapTrap " << name << " died!*\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
    if (!isFit(1))
        return ;

    std::cout << "ClapTrap " << name
              << " repaired " << amount
              << " health point" << (amount != 1 ? "s!\n" : "!\n");
    ep -= 1;
    hp += amount;
}

