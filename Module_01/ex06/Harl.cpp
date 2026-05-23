#include <iostream>

#include "Harl.hpp"

void  Harl::complain(const level& option)
{
    switch (option) {
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
            break;
        case (DEBUG):
            debug();
        case (INFO):
            info();
        case (WARNING):
            warning();
        case (ERROR):
            error();
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

