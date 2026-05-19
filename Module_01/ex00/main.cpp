#include "Zombie.hpp"

int main()
{
    Zombie  *zombie_var = newZombie("Arara");

    zombie_var->announce();
    randomChump("Azul");

    delete zombie_var;

    return (0);
}
