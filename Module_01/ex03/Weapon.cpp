#include <string>

#include "Weapon.hpp"


Weapon::Weapon(const std::string& t)
    : type(t)
{
}

const std::string&  Weapon::getType(void)
{
    return (this->type);
}

void                Weapon::setType(const std::string& new_type)
{
    this->type = new_type;
}
