#include "Zombie.hpp"

Zombie::Zombie(const std::string &name) : name(name)
{
    //initialization list
}

Zombie::Zombie() : name()
{

}

Zombie::~Zombie()
{
    std::cout << this->name << " got headshotted!\n";
}


void        Zombie::announce(void)
{
    std::cout << this->name << ":  BraiiiiiiinnnzzzZ...\n";
}

std::string Zombie::GetName()
{
    return (this->name);
}

void        Zombie::SetName(std::string new_name)
{
    this->name = new_name;
}
