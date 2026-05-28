#include <iostream>
#include <iomanip>

#include "ClapTrap.hpp"

int main()
{
    ClapTrap  assign;
    ClapTrap  clap("clap");
    ClapTrap  trap("trap");
    ClapTrap  copy(clap);

    assign = trap;

    std::cout << "\n|-----" << std::setw(25) << std::left << "Testing vars" << "-----|\n\n";
    std::cout << "assign: " << assign.getName() << "\n";
    std::cout << "clap: " << clap.getName() << "\n";
    std::cout << "trap: " << trap.getName() << "\n";
    std::cout << "copy: " << copy.getName() << "\n";
  
    copy.setName("copy");
    std::cout << "\nnew copy: " << copy.getName() << "\n";
    std::cout << "clap: " << clap.getName() << "\n";

    assign.setName("assign");
    std::cout << "\nnew assign: " << assign.getName() << "\n";
    std::cout << "trap: " << trap.getName() << "\n";

    std::cout << "\n|-----" << std::setw(25) << std::left << "Testing basic functions" << "-----|\n\n";
    clap.attack(trap.getName());
    trap.takeDamage(clap.getAd());
    trap.beRepaired(1);

    std::cout << "\n\n";

    clap.setAd(1);
    std::cout << "trap hp: " << trap.getHp() << "\n";
    for (int i = 0; i < 10; i++)
    {
        clap.attack(trap.getName());
        trap.takeDamage(clap.getAd());
        std::cout << "\n";
    }
    if (trap.getHp())
    {
        copy.setAd(100);
        copy.attack(trap.getName());
        trap.takeDamage(copy.getAd());
    }
    std::cout << std::endl;

    return (0);
}
