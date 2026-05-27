#include <string>
#include <iostream>

#include "Harl.hpp"

int main()
{
    Harl  obj;

	obj.complain("");
	obj.complain("arara");
    obj.complain("debug");
    obj.complain("info");
    obj.complain("warning");
    obj.complain("error");

    return (0);
}

