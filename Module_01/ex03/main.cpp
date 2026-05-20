#include <iostream>

#include "Weapon.hpp"
#include "HumanA.hpp"
//#include "HumanB.cpp"

int main()
{
    std::cout << "\n----------|Testing HumanA|----------" << "\n\n";
    {
        Weapon  club = Weapon("crude spiked club");

        HumanA  bob("Bob", club);
        bob.attack();
        club.setType("Some other type of club");
        bob.attack();
    }
    std::cout << "\n----------|Testing HumanB|----------" << "\n\n";
    {
        Weapon  club = Weapon("crude spiked club");

        HumanB  jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return (0);
}
