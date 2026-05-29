#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <string>

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamonTrap : public FragTrap, public ScavTrap {
public:

private:
   std::string  name;
};

#endif
