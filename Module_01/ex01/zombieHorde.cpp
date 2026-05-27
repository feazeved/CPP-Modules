#include "Zombie.hpp"

Zombie  *zombieHorde(int N, const std::string name)
{
	if (N <= 0)
		return (NULL);
    Zombie  *horde_ptr = new Zombie[N];

    for (int i = 0; i < N; i++)
    {
        horde_ptr[i].SetName(name);
    }
    return (horde_ptr);
}
