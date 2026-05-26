#include <string>
#include <iostream>

#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2){
        std::cerr << "Error: You must pass exactly one parameter.\n";
        return (1);
    }
    Harl  obj;
    obj.complain(argv[1]);
    return (0);
}
