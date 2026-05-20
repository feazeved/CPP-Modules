#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>

#include "Weapon.hpp"


class HumanB{
public:
    HumanB(const std::string &n);

    void    setWeapon(Weapon &new_weapon);
    Weapon  getWeapon(void);

    void    attack(void);


private:
    Weapon      *weapon;
    std::string name;
};

#endif
