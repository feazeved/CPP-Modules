#include <string>
#include <iostream>
#include "PhoneBook.hpp"

int main()
{
    std::string input;
    PhoneBook   phonebook;

    while (1)
    {
        std::cout << "Enter ADD to save a new contact, SEARCH to display a contact or EXIT to quit the program." << std::endl;
        std::cout << "phonebook> ";
        std::cin >> input;
        std::cout << std::endl;
        if (input == "ADD")
            phonebook.AddContact();
        else if (input == "SEARCH")
            phonebook.PrintPhoneBook();
        else if (input == "EXIT")
            std::exit(0);
        else
        {
        }
    }
    return (0);
}
