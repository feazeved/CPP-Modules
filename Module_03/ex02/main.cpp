#include <iostream>

#include "FragTrap.hpp"

int main()
{
    std::cout << "|----- Constructors -----|\n";
    FragTrap    frag("Frag");
    FragTrap    trap("Trap");
    std::cout << "\n";
    FragTrap    copy(trap);

    copy = frag;
    std::cout << "\n\n|----- Testing value at vars -----|\n";
    std::cout << frag.getName() << "\n" << trap.getName() << "\n" << copy.getName() << "\n";

    std::cout << "\n\n|----- Destructors -----|\n";
    return (0);
    return (0);
}
