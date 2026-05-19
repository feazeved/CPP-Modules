#include "Zombie.hpp"

Zombie  *zombieHorde(int N, std::string name)
{
    Zombie  *horde_ptr = new Zombie[N];

    for (int i = 0; i < N; i++)
    {
        horde_ptr[i].SetName(name);
    }
    return (horde_ptr);
}
