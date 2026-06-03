#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <string>

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
    FragTrap(const std::string& n);

    FragTrap(const FragTrap& other);
    FragTrap& operator=(const FragTrap& other);

    ~FragTrap();

    void  highFivesGuys(void);

private:

};


#endif
