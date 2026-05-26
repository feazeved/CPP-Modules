#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
    public:
        Zombie(const std::string &name);
        Zombie();

        ~Zombie();


        void        announce(void);
        std::string GetName();
        void        SetName(const std::string &new_name);


    private:
        std::string name;
};

Zombie  *zombieHorde(int N, const std::string name);
void    randomChump(std::string name);
Zombie  *newZombie(std::string name);

#endif
