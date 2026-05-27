#include <iostream>

#include "Zombie.hpp"

int main()
{
	int n = 10;
    Zombie *ptr = NULL;
	ptr = zombieHorde(n, "Felipe");
	if (!ptr)
		return (1);
	for (int i = 0; i < n; i++)
	{
		std::cout << "N: " << i << ": ";
    	ptr[i].announce();
	}
    delete[] ptr;
    return (0);
}
