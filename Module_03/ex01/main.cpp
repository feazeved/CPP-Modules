#include <iostream>
#include <iomanip>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap  assign;
    ClapTrap  clap("clap");
    ClapTrap  trap("trap");
    ClapTrap  copy(clap);

    assign = trap;

  
    ScavTrap ScavA("Robert");
    ScavA.guardGate();
    ScavA.attack("Pigeon");
    ScavA.takeDamage(10);

    ScavTrap ScavB(ScavA);
    ScavB.beRepaired(5);
    ScavB.beRepaired(1);

    ScavTrap ScavC = ScavA;
    ScavC.takeDamage(100);
    ScavC.takeDamage(100);
    ScavC.attack("Perry");
}
