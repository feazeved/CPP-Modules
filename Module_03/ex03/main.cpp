#include <iostream>

#include "DiamondTrap.hpp"

int main()
{
    std::cout << "|----- Constructors -----|\n";
    DiamondTrap	Diamond("diamond");
    DiamondTrap	Trap("trap");
    std::cout << "\n";

    DiamondTrap	Copy(Diamond);
    Copy.whoAmI();
    std::cout << "\n";
    DiamondTrap	Assign("placeholder");
    Assign = Trap;
    Assign.whoAmI();
    std::cout << "\n";
    Assign.attack(Copy.getName());


    std::cout << "\n\n";
    Diamond.whoAmI();
    Trap.whoAmI();
    std::cout << "\n\n";
    return (0);
}
