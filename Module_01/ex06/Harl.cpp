#include <iostream>

#include "Harl.hpp"

void  Harl::complain(char *str)
{
    typedef void(Harl::*fptr)(void);
    std::string options[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    fptr        ptr[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    std::string level(str);
    int i;
    for (i = 0; i < 4; i++)
    {
        if (i == 3 && level != options[i])
        {
            i = -1;
            break ;
        }
        if (options[i] == level)
            break ;
    }

    switch (i) {
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
            break;
        case (DEBUG):
            (this->*ptr[DEBUG])();
        case (INFO):
            (this->*ptr[INFO])();
        case (WARNING):
            (this->*ptr[WARNING])();
        case (ERROR):
            (this->*ptr[ERROR])();
            break;
    }
}

void  Harl::debug(void)
{
    std::cout << "[ DEBUG ]\n";
    std::cout << "I love having extra bacon.\n\n";
}

void  Harl::info(void)
{
    std::cout << "[ INFO ]\n";
    std::cout << "I cannot believe adding extra bacon costs more.\n\n";
}

void  Harl::warning(void)
{
    std::cout << "[ WARNING ]\n";
    std::cout << "I think I deserve some extra bacon for free.\n\n";
}

void  Harl::error(void)
{
    std::cout << "[ ERROR ]\n";
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
    std::cout << std::endl;
}

