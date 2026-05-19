#include "Zombie.hpp"

int main()
{
    Zombie *ptr = zombieHorde(3, "Felipe");
	ptr[0].announce();
	ptr[1].announce();
	ptr[2].announce();
    delete[] ptr;
    return (0);
}
