#include "Zombie.hpp"

int main()
{
    Zombie *ptr = zombieHorde(42, "Felipe");
    delete ptr;
    return (0);
}
