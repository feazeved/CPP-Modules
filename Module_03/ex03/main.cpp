#include <iostream>
#include <iomanip>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "|-----  ClapTrap Constructors  -----|\n\n";
    ClapTrap  c_assign;
    ClapTrap  c_clap("clap");
    ClapTrap  c_trap("trap");
    ClapTrap  c_copy(c_clap);

    c_assign = c_trap;

    std::cout << "\n|-----  ScavTrap Constructors  -----|\n\n";
    ScavTrap  s_assign;
    ScavTrap  s_scav("scav");
    ScavTrap  s_trap("trap");
    ScavTrap  s_copy(s_scav);

    s_assign = s_scav;

    std::cout << "\n|-----  FragTrap Constructors  -----|\n\n";
    FragTrap  f_assign;
    FragTrap  f_frag("frag");
    FragTrap  f_trap("trap");
    FragTrap  f_copy(f_frag);

    f_assign = f_frag;
    std::cout << "\n|-----  Basic functions  -----|\n\n";

    f_frag.attack(f_trap.getName());
    f_trap.takeDamage(f_frag.getAd());

    std::cout << "\nTrap has " << f_trap.getHp() << "HP.\n";

    f_trap.beRepaired(20);

    std::cout << "Trap has " << f_trap.getHp() << "HP and " << f_trap.getEp() << "EP.\n\n";

    f_frag.setEp(2);
    for (int i = 0; i < 3; i++)
    {
        f_frag.attack(f_trap.getName());
    }

    std::cout << "\n|-----  Destructors  -----|\n\n";
}
