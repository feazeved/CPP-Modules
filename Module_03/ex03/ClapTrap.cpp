#include <iostream>

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &n) :
	name(n), hp(10), ep(10), ad(0)
{
    std::cout << "[ClapTrap] Default constructed " << name << "!\n";
}

ClapTrap::ClapTrap(const ClapTrap& other) :
	name(other.name), hp(other.hp), ep(other.ep), ad(other.ad)
{
    std::cout << "[ClapTrap] Copy constructed another " << name << "!\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this == &other)
        return (*this);

    std::cout << "[ClapTrap] Assigned constructed another " << other.name << "!\n";
    this->name = other.name;
    this->hp = other.hp;
    this->ep = other.ep;
    this->ad = other.ad;

    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "[ClapTrap] " << name << " got destroyed!\n";
}


const std::string& ClapTrap::getName() const
{
    return (name);
}

void         ClapTrap::setName(const std::string &n)
{
    name = n;
}

int          ClapTrap::getAd() const
{
    return (ad);
}

void         ClapTrap::setAd(const int a)
{
    ad = a;
}

int          ClapTrap::getHp() const
{
    return (hp);
}

void	ClapTrap::attack(const std::string& target)
{
    if (hp <= 0)
        return ;
    else if (ep <= 0)
    {
        std::cout << "[ClapTrap] " << name << " cannot do this!\n";
    }

    std::cout << "[ClapTrap] " << name
              << " attacks " << target
              << " causing " << ad
              << " points of damage!\n";
    ep -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
    if (hp <= 0)
        return ;

    std::cout << "[ClapTrap] " << name
              << " took " << amount
              << " of damage!\n";
    hp -= amount;
    if (hp <= 0)
        std::cout << "[ClapTrap] " << name << " died!\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
    if (hp <= 0)
        return ;
    else if (ep <= 0)
    {
        std::cout << "[ClapTrap] " << name << " cannot do this!\n";
    }

    std::cout << "[ClapTrap] " << name
              << " repaired " << amount
              << " health point" << (amount != 1 ? "s!\n" : "!\n");
    ep -= 1;
    hp += amount;
}
