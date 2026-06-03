#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
	ScavTrap(const std::string &n);

	ScavTrap(const ScavTrap& other);
	ScavTrap& operator=(const ScavTrap& other);

	~ScavTrap();

	void	attack(const std::string& target);
	void	guardGate();

private:
};

#endif
