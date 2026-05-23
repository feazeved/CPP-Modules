#include <string>
#include <iostream>

#include "Harl.hpp"

static level  stt_converter(const std::string& str)
{
    if (str == "DEBUG")
        return (DEBUG);
    else if (str == "INFO")
        return (INFO);
    else if (str == "WARNING")
        return (WARNING);
    else if (str == "ERROR")
        return (ERROR);
    
    return (NONE);
}

int main(int argc, char **argv)
{
    if (argc != 2){
        std::cerr << "Error: You must pass exactly one parameter.\n";
        return (1);
    }

    enum level  option = stt_converter(argv[1]);

    Harl  obj;
    obj.complain(option);
    return (0);
}
