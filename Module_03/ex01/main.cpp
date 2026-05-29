#include <iostream>

#include "ScavTrap.hpp"

int main()
{
    std::cout << "|----- Constructors -----|\n";

    ScavTrap    scav("Scav");
    ScavTrap    trap("Trap");
    std::cout << "\n";
    ScavTrap    copy_then_assign(scav);
    copy_then_assign = trap;

    std::cout << "\n\n|----- Testing value at vars -----|\n";
    std::cout << scav.getName() << "\n" << trap.getName() << "\n" << copy_then_assign.getName() << "\n";

    std::cout << "\n\n|----- Destructors -----|\n";
    return (0);
}
