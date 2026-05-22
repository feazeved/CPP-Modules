#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>

#include "Weapon.hpp"


class HumanA{
public:
    HumanA(const std::string &n, Weapon &w);
    void  attack(void);

private:
    Weapon      &weapon;
    std::string name;
};


#endif
