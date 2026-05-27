#include "Zombie.hpp"

Zombie::Zombie(const std::string &name) :
    name(name)
{
}

Zombie::~Zombie()
{
    std::cout << this->name << " got headshotted!\n";
}

void  Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}

