#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <string>

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
    FragTrap();
    FragTrap(const std::string& n);
    
    FragTrap(const FragTrap& other);
    FragTrap& operator=(const FragTrap& other);

    ~FragTrap();

    void  highFivesGuys(void);

private:

};


#endif
