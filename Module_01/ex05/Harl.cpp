#include <string>
#include <iostream>

#include "Harl.hpp"

void  Harl::debug(void)
{
    std::cout << "|DEBUG|\n";
    std::cout << "I love having extra bacon\n";
}

void  Harl::info(void)
{
    std::cout << "|INFO|\n";
    std::cout << "I cannot believe adding extra bacon costs more money\n";
}

void  Harl::warning(void)
{
    std::cout << "|WARNING|\n";
    std::cout << "I think I deserve to have some extra bacon for free\n";
}

void  Harl::error(void)
{
    std::cout << "|ERROR|\n";
    std::cout << "This is unacceptable! I want to speak to the manager now\n";
}

void  Harl::complain(std::string level)
{
    typedef void(Harl::*fptr)(void);

    std::string options[4] = {"debug", "info", "warning", "error"};

    fptr        ptr[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    
    for (int i = 0; i < 4; i++){
        if (level == options[i])
        {
            (this->*ptr[i])();
            return ;
        }
    }
    std::cerr << "Error: Unknown level\n";
}
